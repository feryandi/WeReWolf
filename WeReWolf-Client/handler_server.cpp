#include "handler_server.h"

handler_server connection_server;

handler_server::handler_server(QObject *parent) : QObject(parent), last_sent_method("")
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
    } else{
        local_address = socket->localAddress();
    }
}

QString handler_server::getLocalAddress()
{
    return local_address.toString();
}

QJsonArray handler_server::getClients()
{
    return clients;
}

void handler_server::statusConnected()
{
    qDebug() << "connected...";
}

void handler_server::statusDisconnected()
{
    qDebug() << "disconnected...";
}

void handler_server::sendMessageJSON(QJsonObject message)
{
    qDebug() << "writing...";
    qDebug() << message;

    QJsonDocument json_document;
    json_document.setObject(message);
    if (socket->write(json_document.toJson(QJsonDocument::Compact) + "\r\n") < 0){
        qDebug() << "Error: " << socket->errorString();
    } else{
        last_sent_method = message.value("method").toString();
    }
}

void handler_server::readMessage()
{
    QByteArray message = socket->readAll();

    qDebug() << "reading...";

    QList<QByteArray> message_list= message.split('\n');
    qDebug() << message_list;

    QJsonDocument json_document;
    QJsonObject json_object;
    QJsonValue method, status;
    for (int i=0; i<message_list.size(); i++){
        json_document = QJsonDocument::fromJson(message_list.at(i));
        json_object = json_document.object();

        if (json_object.contains("status")){
            /* Response Client->Server */
            status = json_object.value("status");

            if (last_sent_method == "join" && status == "ok"){
                player_id = json_object.value("player_id").toInt();
                emit on_login();
            } else if (last_sent_method == "leave" && status == "ok"){

            } else if (last_sent_method == "ready" && status == "ok"){
                emit on_ready();
            } else if (last_sent_method == "client_address" && status == "ok"){
                //clients = json_object.value("clients").toArray();
                QJsonObject client_;
                for (int i=0; i<json_object.value("clients").toArray().size(); i++){
                    client_ = json_object.value("clients").toArray().at(i).toObject();
                    clients.push_back(client_);
                }
                emit on_get_clients();
            } else if (status == "fail" || status == "error"){

            }
        } else if (json_object.contains("method")){
            /* Request Server->Client */
            method = json_object.value("method");

            if (method == "start"){
                /* Send list clients message */
                QJsonObject json_object_;
                json_object_.insert("method", "client_address");
                sendMessageJSON(json_object_);
            } else if (method == "change_phase"){

            } else if (method == "game_over"){

            }
        }

    }
}
