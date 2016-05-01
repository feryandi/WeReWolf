#ifndef HANDLER_CLIENT_H
#define HANDLER_CLIENT_H

#include <QObject>
#include <QUdpSocket>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <map>
#include "handler_server.h"

class handler_client : public QObject
{
        Q_OBJECT
    public:
        explicit handler_client(QObject *parent = 0);
        void doListen(quint16 client_port);
        int getCounterLocal();
        int getCounterPrepare();
        int getCounterAccept();
        int getLastKPU();
        void setCounter(int c);
        void setLastKPU(int c);
        void resetCounter();
        int getVoteResult();
        void resetVote();
        std::map<int, int> vote_map;
        int counter_vote;
        QJsonArray vote_result;

    signals:
        void on_fail_or_error(QString);
        void on_accept_prepare_proposal(QJsonObject,QHostAddress,quint16);
        void on_accept_accept_proposal(QJsonObject, QHostAddress, quint16);

    public slots:
        void readMessage();
        void sendMessage(QString recv_address, quint16 recv_port, QJsonObject message);
        void prepare_proposal();
        void accept_proposal();
        void sendResponse(QString address, quint16 port, QString status, QString description);

    private:
        QUdpSocket *socket;
        QString last_sent_method;
        int counter_local;
        int counter_prepare;
        int counter_accept;
        int last_KPU;

};

/* Universal client connection handler */
extern handler_client connection_client;

#endif // HANDLER_CLIENT_H
