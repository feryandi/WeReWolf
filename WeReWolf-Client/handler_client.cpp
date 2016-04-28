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
    qDebug() << json_document;
    socket->writeDatagram((json_document.toJson(QJsonDocument::Compact) + "\r\n"), QHostAddress(recv_address), recv_port.toUShort());
}
