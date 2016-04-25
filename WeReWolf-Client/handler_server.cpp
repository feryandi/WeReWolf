#include "handler_server.h"

handler_server connection_server;

handler_server::handler_server(QObject *parent) : QObject(parent)
{
}

void handler_server::doConnect(QString server_ip, quint16 server_port)
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(statusConnected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(statusDisconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readMessage()));

    qDebug() << "connecting...";

    socket->connectToHost(server_ip, server_port);
    if (!socket->waitForConnected(3000)){
        qDebug() << "Error: " << socket->errorString();
    }
}



void handler_server::statusConnected()
{
    qDebug() << "connected...";
}

void handler_server::statusDisconnected()
{
    qDebug() << "disconnected...";
}

void handler_server::readMessage()
{
    QByteArray message = socket->readAll();

    qDebug() << "reading...";

    QList<QByteArray> message_list= message.split('\n');
    qDebug() << message_list;
}

void handler_server::sendMessageJSON(QJsonObject message)
{
    qDebug() << "writing...";
    qDebug() << message;

    QJsonDocument json_document;
    json_document.setObject(message);
    if (socket->write(json_document.toJson(QJsonDocument::Compact) + "\r\n") < 0){
        qDebug() << "Error: " << socket->errorString();
    }
}
