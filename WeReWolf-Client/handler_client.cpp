#include "handler_client.h"

handler_client connection_client;

handler_client::handler_client(QObject *parent) : QObject(parent)
{
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

        if (i != static_cast<int>(connection_server.getClientId()))
        {
            QJsonObject json_object = connection_server.getClients().at(i).toObject();
            qDebug() << json_object;
            QString address = json_object.value("address").toString();
            QString port = json_object.value("port").toString();

            /* send message */
            QJsonObject message;
            QJsonArray json_array;
            qDebug() << "Your player id: " << playerid;

            json_array.insert(0,connection_server.getCounter());
            json_array.insert(1,playerid);
            message.insert("method", "prepare_proposal");
            message.insert("proposal_id", json_array);

            sendMessage(address,port,message);
        }
    }
}
