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
        int getCounter();
        int getLastKPU();
        void setCounter(int c);
        void setLastKPU(int c);
        void resetCounter();

    signals:
        void on_fail_or_error(QString);
        void on_accept_prepare_proposal(QJsonObject);

    public slots:
        void readMessage();
        void sendMessage(QString recv_address, QString recv_port, QJsonObject message);
        void prepare_proposal();

    private:
        QUdpSocket *socket;
        QString last_sent_method;
        int local_counter;
        int last_KPU;
};

/* Universal client connection handler */
extern handler_client connection_client;

#endif // HANDLER_CLIENT_H
