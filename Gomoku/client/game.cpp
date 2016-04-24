#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::game)
{
	ui->setupUi(this);
}

game::~game()
{
	delete ui;

}

void game::closeEvent(QCloseEvent *event)
{
	emit on_closegame();
	event->ignore();
}

void game::populate_players(QJsonArray data)
{
	ui->listPlayer->clear();
	QStringList list_players;
	QString player_name;

	for (int i=0; i<data.size(); i++){
		player_name = "[" + data.at(i).toObject().value("char").toString() + "] " + data.at(i).toObject().value("name").toString();
		if (data.at(i).toObject().value("id") == connection.getPid()){
			player_name += " (YOU)";
		}
		list_players += player_name;
	}
	ui->listPlayer->addItems(list_players);
}

void game::populate_board(QJsonArray data)
{
	for (int i=0; i<data.size(); i++){
		for (int j=0; j<data.at(i).toArray().size(); j++) {

			if ( data.at(i).toArray().at(j).toString() != 0 ) {
				ui->tableBoard->item(j, i)->setText(data.at(i).toArray().at(j).toString());
			}

		}
	}
}

void game::do_show(int rid)
{
	ui->listChat->clear();
	ui->textRoom->setText(connection.getRoomNameByRid(rid));
	ui->tableBoard->clearContents();
	for (int i=0; i<20; i++){
		for (int j=0; j<20; j++){
			ui->tableBoard->setItem(i, j, new QTableWidgetItem(""));
		}
	}

	this->show();
}

void game::do_hide()
{
	this->hide();
}

void game::do_startgame()
{
	ui->buttonPlay->setText("Game Started!");
	ui->buttonPlay->setDisabled(1);
}

void game::do_updategame(QJsonObject data)
{
	ui->tableBoard->item(data.value("y").toInt(), data.value("x").toInt())->setText(data.value("char").toString());

	for (int i=0; i<connection.getPlayers().size(); i++){
		if (data.value("turn_id") == connection.getPlayers().at(i).toObject().value("id")){
			ui->listPlayer->item(i)->setBackgroundColor(Qt::blue);
		} else{
			ui->listPlayer->item(i)->setBackgroundColor(Qt::white);
		}
	}
}

void game::do_highlight(QJsonObject data)
{
	ui->tableBoard->item(data.value("y").toInt(), data.value("x").toInt())->setBackgroundColor(Qt::blue);
}

void game::do_chat(QJsonObject data)
{
	QString message = "[" + connection.getNameByPid(data.value("pid").toInt()) + "] " + data.value("message").toString();
	ui->listChat->insertItem(ui->listChat->size().rheight(), message);
}

void game::on_game_destroyed()
{
	QJsonObject json_object;
	json_object.insert("type", "closegame");
	connection.sendMessageJSONObject(json_object);
}

void game::on_buttonPlay_clicked()
{
	QJsonObject json_object;
	json_object.insert("type", "startgame");
	connection.sendMessageJSONObject(json_object);
}

void game::on_tableBoard_cellClicked(int row, int column)
{
	QJsonObject json_object;
	json_object.insert("type", "play");
	json_object.insert("x", column);
	json_object.insert("y", row);
	connection.sendMessageJSONObject(json_object);
}

void game::on_buttonChat_clicked()
{
	QJsonObject json_object;
	json_object.insert("type", "chat");
	json_object.insert("message", ui->textChat->text());
	connection.sendMessageJSONObject(json_object);

	ui->textChat->setText("");
}
