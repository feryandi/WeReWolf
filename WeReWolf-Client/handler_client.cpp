#include "handler_client.h"

handler_client connection_client;

handler_client::handler_client(QObject *parent) : QObject(parent)
{
}

int handler_client::getCounter()
{
    return local_counter;
}

void handler_client::setCounter(int c)
{
    local_counter = c;
}

void handler_client::resetCounter()
{
    local_counter = 0;
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
        for (int i=0; i<message_list.size(); i++){
            json_document = QJsonDocument::fromJson(message_list.at(i));
            json_object = json_document.object();

            if (json_object.contains("status")){
                /* Response Proposer->Acceptor */
                status = json_object.value("status");

                if (status == "fail" || status == "error"){
                    description = json_object.value("description");
                    emit on_fail_or_error(description.toString());

                /*} else if (last_sent_method == "prepare_proposal" && status == "ok"){

                    emit on_login();
*/
                }

            } else if (json_object.contains("method")){
                /* Request Acceptor->Proposer */
                method = json_object.value("method");
                qDebug() << "Masuk ga yaa";
                // Cek dia nerima method apa
                if (method == "prepare_proposal"){
                    emit on_accept_prepare_proposal(json_object);

                } else if (method == "accept_proposal"){

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
}

void handler_client::prepare_proposal()
{
    int size = connection_server.getClients().size();
    for (int i = 0; i < size; i++)
    {
        QJsonValue playerid;
        playerid = connection_server.getClientId();

        if ((i < size-2))
        {
            QJsonObject json_object = connection_server.getClients().at(i).toObject();
            qDebug() << json_object;
            QString address = json_object.value("address").toString();
            QString port = json_object.value("port").toString();

            /* send message */
            QJsonObject message;
            QJsonArray json_array;
            qDebug() << "Your player id: " << playerid;

            json_array.insert(0,connection_client.getCounter());
            json_array.insert(1,playerid);
            message.insert("method", "prepare_proposal");
            message.insert("proposal_id", json_array);

            sendMessage(address,port,message);
        }
    }
}
