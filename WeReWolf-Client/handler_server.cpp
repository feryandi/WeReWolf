#include "handler_server.h"

handler_server connection_server;

handler_server::handler_server(QObject *parent) : QObject(parent), last_sent_method(""), kpu_id(-1), game_over(false)
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
        foreach (const QHostAddress &local_address_, QNetworkInterface::allAddresses()) {
            if (local_address_.protocol() == QAbstractSocket::IPv4Protocol && local_address_ != QHostAddress(QHostAddress::LocalHost))
            local_address = local_address_.toString();
        }
    }
}

QString handler_server::getLocalAddress()
{
    return local_address.toString();
}

QVector<QString> handler_server::getFriends()
{
    return friends;
}

QJsonArray handler_server::getClients()
{
    return clients;
}

QString handler_server::getRole()
{
    return player_role;
}

int handler_server::getPlayerId()
{
    return player_id;
}

int handler_server::getCurrentTime()
{
    return current_time;
}

int handler_server::getCurrentDay()
{
    return current_day;
}

void handler_server::setCurrentDay(int current_day_)
{
    current_day = current_day_;
}

void handler_server::setCurrentTime(QString current_time_)
{
    if (current_time_ == "night"){
        current_time = 0;
    } else {
        current_time = 1;
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

void handler_server::sendMessageJSON(QJsonObject message)
{
    qDebug() << "writing...";
    qDebug() << message;

    QJsonDocument json_document;
    json_document.setObject(message);
    if (socket->write(json_document.toJson(QJsonDocument::Compact) + "\n") < 0){
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
    QJsonValue method, status, description;
    for (int i=0; i<message_list.size(); i++){
        json_document = QJsonDocument::fromJson(message_list.at(i));
        json_object = json_document.object();

        if (json_object.contains("status")){
            /* Response Client->Server */
            status = json_object.value("status");

            if (status == "fail" || status == "error"){
                description = json_object.value("description");
                emit on_fail_or_error(description.toString());

            } else if (last_sent_method == "join" && status == "ok"){
                player_id = json_object.value("player_id").toInt();
                emit on_login();

            } else if (last_sent_method == "leave" && status == "ok"){

            } else if (last_sent_method == "ready" && status == "ok"){
                emit on_ready();

            } else if (last_sent_method == "client_address" && status == "ok"){
                //clients = json_object.value("clients").toArray();
                int size_ = clients.size();
                for (int i=0; i<size_; i++){
                    clients.removeFirst();
                }

                QJsonObject client_;
                for (int i=0; i<json_object.value("clients").toArray().size(); i++){
                    client_ = json_object.value("clients").toArray().at(i).toObject();
                    clients.push_back(client_);
                }
                qDebug() << "AARGHH" << clients;

                emit on_get_clients();

            }
        } else if (json_object.contains("method")){
            /* Request Server->Client */
            method = json_object.value("method");

            if (method == "start"){
                /* Set user role */
                player_role = json_object.value("role").toString();

                QString friend_;
                for (int i=0; i<json_object.value("friend").toArray().size(); i++){
                    friend_ = json_object.value("friend").toArray().at(i).toString();
                    friends.push_back(friend_);
                }

                emit on_start();
                emit on_change_phase(json_object);

            } else if (method == "change_phase"){
                if(!game_over) {
                    emit on_change_phase(json_object);
                }
            } else if (method == "game_over"){
                game_over = true;
                emit on_game_over(json_object);
            } else if (method == "kpu_selected") {
                kpu_id = json_object.value("kpu_id").toInt();
                emit on_kpu_is_selected();
            } else if (method == "vote_now") {
                emit on_vote_now();
            }
        }

    }
}

int handler_server::getClientIdByUsername(QString username){
    for (int i=0; i<clients.size(); i++){
        if (clients.at(i).toObject().value("username").toString() == username){
            return clients.at(i).toObject().value("player_id").toInt();
        }
    }
    return -1;
}

QJsonObject handler_server::getClientDataByUsername(QString username){
    QJsonObject ret;
    for (int i=0; i<clients.size(); i++){
        if (clients.at(i).toObject().value("username").toString() == username){
            ret = clients.at(i).toObject();
        }
    }
    return ret;
}

QJsonObject handler_server::getClientDataById(int id){
    QJsonObject ret;
    for (int i=0; i<clients.size(); i++){
        if (clients.at(i).toObject().value("player_id").toInt() == id){
            ret = clients.at(i).toObject();
        }
    }
    return ret;
}

QJsonArray handler_server::getNonFriends()
{
    QJsonArray ret;
    for (int i=0; i<clients.size(); i++){
        bool is_friend = false;
        for (int j=0; j<friends.size(); j++){
            if ( friends.at(j) == clients.at(i).toObject().value("username").toString() ) {
                is_friend = true;
            }
        }
        if (!is_friend) {
            ret.insert(0, clients.at(i).toObject().value("username").toString());
        }
    }

    return ret;
}

QString handler_server::getPlayerName(){
    return player_name;
}

void handler_server::setPlayerName(QString player_name_){
    player_name = player_name_;
}

int handler_server::getDeadWerewolf() {
    int ret = 0;
    for (int i = 0; i < clients.size(); i++) {
        if ( clients.at(i).toObject().value("is_alive") == 0 ) {
            if ( clients.at(i).toObject().value("role") == "werewolf" ) {
                ret++;
            }
        }
    }
    return ret;
}

int handler_server::getDeadPlayer() {
    int ret = 0;
    for (int i = 0; i < clients.size(); i++) {
        if ( clients.at(i).toObject().value("is_alive") == 0 ) {
            ret++;
        }
    }
    return ret;
}
