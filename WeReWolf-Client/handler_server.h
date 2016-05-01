#ifndef HANDLER_SERVER_H
#define HANDLER_SERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

class handler_server : public QObject
{
        Q_OBJECT
    public:
        explicit handler_server(QObject *parent = 0);
        void doConnect(QString server_ip, quint16 server_port);
        QString getLocalAddress();
        QJsonArray getClients();
        QVector<QString> getFriends();
        QString getRole();
        int getPlayerId();
        QString getPlayerName();
        void setPlayerName(QString player_name_);
        int getClientIdByUsername(QString);
        QJsonObject getClientDataByUsername(QString);
        QJsonObject getClientDataById(int);
        int getDeadWerewolf();
        int getDeadPlayer();

        QJsonArray getNonFriends();
        int getCurrentTime();
        int getCurrentDay();
        void setCurrentDay(int current_day_);
        void setCurrentTime(QString current_time_);
        int kpu_id;


    signals:
        void on_fail_or_error(QString);
        void on_login();
        void on_ready();
        void on_get_clients();
        void on_start();
        void on_change_phase(QJsonObject);
        void on_kpu_is_selected();
        void on_game_over(QJsonObject);
        void on_vote_now();

    public slots:
        void statusConnected();
        void statusDisconnected();
        void sendMessageJSON(QJsonObject message);
        void readMessage();

    private:
        QTcpSocket *socket;
        QHostAddress local_address;
        QString last_sent_method;
        QJsonArray clients;
        QVector<QString> friends;
        QString player_role;
        int current_time;
        int current_day;
        int player_id;
        QString player_name;
};

/* Universal server connection handler */
extern handler_server connection_server;

#endif // HANDLER_SERVER_H
