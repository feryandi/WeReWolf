#ifndef HANDLER_CLIENT_H
#define HANDLER_CLIENT_H

#include <QObject>
#include <QUdpSocket>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include "handler_server.h"

class handler_client : public QObject
{
        Q_OBJECT
    public:
        explicit handler_client(QObject *parent = 0);
        void doListen(quint16 client_port);

    signals:

    public slots:
        void readMessage();
        void sendMessage(QString recv_address, QString recv_port, QJsonObject message);
        void prepare_propose();

    private:
        QUdpSocket *socket;
};

/* Universal client connection handler */
extern handler_client connection_client;

#endif // HANDLER_CLIENT_H
