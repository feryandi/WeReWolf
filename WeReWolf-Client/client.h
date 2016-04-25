#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QCloseEvent>

class client : public QObject
{
	    Q_OBJECT
	public:
	    explicit client(QObject *parent = 0);
	    void doConnect(QString server_ip, quint16 server_port);
		

	signals:

	public slots:
		void connected();
		void disconnected();
		void sendMessageJSONObject(QJsonObject message);
		void readMessage();

	private:
		QTcpSocket *socket;
		

};
/* Universal connection handler */
extern client connection;
#endif // CLIENT_H
