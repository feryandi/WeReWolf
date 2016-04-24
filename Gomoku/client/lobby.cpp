#include "lobby.h"
#include "ui_lobby.h"

lobby::lobby(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::lobby)
{
	ui->setupUi(this);
}

lobby::~lobby()
{
	delete ui;
}

void lobby::populate_room(QJsonArray data)
{
	ui->listRoom->clear();
	QStringList list_room;
	for (int i=0; i<data.size(); i++){
		list_room += data.at(i).toObject().value("name").toString();
	}
	ui->listRoom->addItems(list_room);
}

void lobby::do_show()
{
	this->show();
}

void lobby::do_hide()
{
	this->hide();
}

void lobby::on_join(int rid)
{
	QJsonObject json_object;
	json_object.insert("type", "join");
	json_object.insert("rid", rid);
	connection.sendMessageJSONObject(json_object);
}

void lobby::on_buttonCreateRoom_clicked()
{
	QJsonObject json_object;
	json_object.insert("type", "newroom");
	json_object.insert("name", ui->textCreateRoom->text());
	connection.sendMessageJSONObject(json_object);
}

void lobby::on_buttonJoinRoom_clicked()
{
	QJsonObject json_object;
	json_object.insert("type", "join");
	int rid = connection.getRidByIndex(ui->listRoom->currentRow());
	json_object.insert("rid", rid);
	connection.sendMessageJSONObject(json_object);
}

void lobby::on_buttonRefreshRoom_clicked()
{
	QJsonObject json_object;
	json_object.insert("type", "request");
	json_object.insert("object", "rooms");
	connection.sendMessageJSONObject(json_object);
}

void lobby::on_buttonSpectate_clicked()
{
	QJsonObject json_object;
	json_object.insert("type", "spectate");
	int rid = connection.getRidByIndex(ui->listRoom->currentRow());
	json_object.insert("rid", rid);
	connection.sendMessageJSONObject(json_object);
}
