#ifndef HANDLER_SERVER_H
#define HANDLER_SERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
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


    signals:
        void on_login();
        void on_ready();
        void on_get_clients();


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
        int player_id;
};

/* Universal server connection handler */
extern handler_server connection_server;

#endif // HANDLER_SERVER_H
