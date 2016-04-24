#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::login),
	nickname("user_name")
{
	ui->setupUi(this);
}

login::~login()
{
	delete ui;
}

void login::do_destroy()
{
	delete this;
}

void login::on_buttonPlay_clicked()
{
	nickname = ui->textNickname->text();
	QString server_ip = ui->textServerIP->text();
	qint16 server_port = ui->textServerPort->text().toInt();

	connection.doConnect(server_ip, server_port);

	QJsonObject json_object;
	json_object.insert("type", "login");
	json_object.insert("name", nickname.toStdString().c_str());
	connection.sendMessageJSONObject(json_object);
}
