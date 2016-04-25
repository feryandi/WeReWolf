#ifndef HANDLER_CLIENT_H
#define HANDLER_CLIENT_H

#include <QObject>
#include <QUdpSocket>

class handler_client : public QObject
{
        Q_OBJECT
    public:
        explicit handler_client(QObject *parent = 0);
        void doListen(quint16 client_port);

    signals:

    public slots:
        void readMessage();

    private:
        QUdpSocket *socket;
};

/* Universal client connection handler */
extern handler_client connection_client;

#endif // HANDLER_CLIENT_H
