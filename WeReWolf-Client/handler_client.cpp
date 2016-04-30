#include "handler_client.h"

handler_client connection_client;

handler_client::handler_client(QObject *parent) : QObject(parent), last_KPU(-1)
{
}

int handler_client::getCounterLocal()
{
    return counter_local;
}

int handler_client::getCounterPrepare()
{
    return counter_prepare;
}

int handler_client::getCounterAccept()
{
    return counter_accept;
}

int handler_client::getLastKPU()
{
    return last_KPU;
}

void handler_client::setCounter(int c)
{
    counter_local = c;
}

void handler_client::setLastKPU(int c)
{
    last_KPU = c;
}

void handler_client::resetCounter()
{
    counter_local = 0;
}

void handler_client::doListen(quint16 client_port)
{
    socket = new QUdpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readMessage()));

    qDebug() << "binding...";

    socket->bind(QHostAddress::Any, client_port);
}

void handler_client::readMessage()
{
    while (socket->hasPendingDatagrams()) {
        QByteArray message;
        message.resize(socket->pendingDatagramSize());

        QHostAddress sender_ip;
        quint16 sender_port;
        socket->readDatagram(message.data(), message.size(), &sender_ip, &sender_port);

        qDebug() << "reading...";

        QList<QByteArray> message_list = message.split('\n');
        qDebug() << message_list;

        QJsonDocument json_document;
        QJsonObject json_object;
        QJsonValue method, status, description;
        for (int i=0; i<message_list.size()-1; i++){
            json_document = QJsonDocument::fromJson(message_list.at(i));
            json_object = json_document.object();

            //qDebug() << "AAAAA" << json_object << "BBBB";
            //qDebug() << "CCCCC" << last_sent_method << "DDDD";


            if (json_object.contains("status")){
                /* Response Proposer->Acceptor */
                status = json_object.value("status");

                if (status == "fail" || status == "error"){
                    description = json_object.value("description");
                    emit on_fail_or_error(description.toString());

                } else if (last_sent_method == "prepare_proposal" && status == "ok"){
                    counter_prepare++;
                    qDebug() << "Prepare Counter Sekarang = " << counter_prepare;
                    if (counter_prepare == connection_server.getClients().size()-1){
                        accept_proposal();
                    }
                } else if (last_sent_method == "accept_proposal" && status == "ok"){
                    QJsonObject json_object_;
                    json_object_.insert("method", "accepted_proposal");
                    json_object_.insert("kpu_id", last_KPU);
                    json_object_.insert("Description", "Kpu is selected");

                    connection_server.sendMessageJSON(json_object_);
                } else if (last_sent_method == "vote_werewolf" && status == "ok"){

                }

            } else if (json_object.contains("method")){
                /* Request Acceptor->Proposer */
                method = json_object.value("method");
                // Cek dia nerima method apa
                if (method == "prepare_proposal"){
                    emit on_accept_prepare_proposal(json_object,sender_ip,sender_port);
                } else if (method == "accept_proposal"){
                    emit on_accept_accept_proposal(json_object,sender_ip,sender_port);
                } else if (method == "vote_werewolf") {
                    sendResponse(sender_ip.toString(),QString::number(sender_port),"ok","");
                }
            }

        }
    }
}

void handler_client::sendMessage(QString recv_address, QString recv_port, QJsonObject message)
{
    QJsonDocument json_document;
    json_document.setObject(message);
    qDebug() << "SEND UDP DATAGRAM: " << json_document;
    socket->writeDatagram((json_document.toJson(QJsonDocument::Compact) + "\r\n"), QHostAddress(recv_address), recv_port.toUShort());
    if (message.value("method").toString() != ""){
        last_sent_method = message.value("method").toString();
    }
}

void handler_client::prepare_proposal()
{
    int size = connection_server.getClients().size();
    int newcounter = connection_client.getCounterLocal() + 1;
    counter_prepare = 0;
    for (int i = 0; i < size; i++)
    {
        QJsonValue playerid;
        playerid = connection_server.getPlayerId();

        if (i != playerid.toInt())
        {
            QJsonObject json_object = connection_server.getClients().at(i).toObject();
            qDebug() << json_object;
            QString address = json_object.value("address").toString();
            QString port = json_object.value("port").toString();

            /* send message */
            QJsonObject message;
            QJsonArray json_array;

            json_array.insert(0,newcounter);
            json_array.insert(1,playerid);
            qDebug() << "Proposal-id: " << newcounter;
            qDebug() << "Your player id: " << playerid;
            connection_client.setCounter(newcounter);
            message.insert("method", "prepare_proposal");
            message.insert("proposal_id", json_array);

            connection_client.setLastKPU(playerid.toInt());

            sendMessage(address,port,message);
        }
    }
}

void handler_client::accept_proposal()
{
    int size = connection_server.getClients().size();
    int counter = connection_client.getCounterLocal();
    counter_prepare = 0;
    for (int i = 0; i < size; i++)
    {
        QJsonValue playerid;
        playerid = connection_server.getPlayerId();

        if (i != playerid.toInt())
        {
            QJsonObject json_object = connection_server.getClients().at(i).toObject();
            qDebug() << json_object;
            QString address = json_object.value("address").toString();
            QString port = json_object.value("port").toString();

            /* send message */
            QJsonObject message;
            QJsonArray json_array;

            json_array.insert(0,counter);
            json_array.insert(1,playerid);
            //qDebug() << "ini accept";
            qDebug() << "Proposal-id: " << counter;
            qDebug() << "Your player id: " << playerid;
            connection_client.setCounter(counter);
            message.insert("method", "accept_proposal");
            message.insert("proposal_id", json_array);
            message.insert("kpu_id", playerid);

            sendMessage(address,port,message);
        }
    }
}

void handler_client::sendResponse(QString address, QString port, QString status, QString description)
{
    QJsonObject json_object;
    json_object.insert("status",status);
    json_object.insert("description",description);
    sendMessage(address,port,json_object);
}
