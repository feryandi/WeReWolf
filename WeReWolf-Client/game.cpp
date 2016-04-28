#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    ui->labelTime->setText("Please press READY to start the game!");
    ui->textNarration->setText("~ When the night comes, it's time for darkness to approach. ~");
    ui->textNarration->setAlignment(Qt::AlignHCenter);
    ui->listPlayer->hide();
    ui->labelRole->hide();
}

game::~game()
{
    delete ui;
}

void game::do_start()
{
    ui->labelRole->setText("You are " + connection_server.getRole() + "!");
    ui->labelRole->show();
    ui->buttonVote->setText("Vote!");
    ui->buttonVote->setEnabled(true);

    /* Send list clients message */
    QJsonObject json_object;
    json_object.insert("method", "client_address");
    connection_server.sendMessageJSON(json_object);
}

void game::do_wait_until_start()
{
    ui->labelTime->setText("Please wait for other players...");
    ui->buttonVote->setDisabled(true);
}

void game::do_populate_players()
{
    ui->listPlayer->clear();
    QStringList list_player;
    QJsonObject json_object;
    for (int i=0; i<connection_server.getClients().size(); i++){
        json_object = connection_server.getClients().at(i).toObject();
        list_player += json_object.value("username").toString();
    }
    ui->listPlayer->addItems(list_player);
    ui->listPlayer->show();
}

void game::on_buttonVote_clicked()
{
    if (ui->buttonVote->text() == "Ready!"){
        /* Send ready message */
        QJsonObject json_object;
        json_object.insert("method", "ready");
        connection_server.sendMessageJSON(json_object);
    } else {
        QJsonObject json_object;
        json_object.insert("method", "WASU!");
        connection_client.sendMessage("10.5.21.53", "9999", json_object);

    }

}
