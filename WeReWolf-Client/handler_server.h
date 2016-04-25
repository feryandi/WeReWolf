#ifndef HANDLER_SERVER_H
#define HANDLER_SERVER_H

#include <QObject>
#include <QTcpSocket>
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

    signals:
        void on_login();

    public slots:
        void statusConnected();
        void statusDisconnected();
        void sendMessageJSON(QJsonObject message);
        void readMessage();

    private:
        QTcpSocket *socket;
        QString last_sent_method;
        int player_id;
};

/* Universal server connection handler */
extern handler_server connection_server;

#endif // HANDLER_SERVER_H
