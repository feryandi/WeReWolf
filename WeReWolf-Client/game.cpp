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
    int size = connection_server.getClients().size();
    for (int i=0; i<size; i++){
        json_object = connection_server.getClients().at(i).toObject();
        list_player += json_object.value("username").toString();
    }

    qDebug() << "Total client: " << size;
    int clientID = static_cast<int>(connection_server.getClientId());
    if (((clientID + 1) == size) || ((clientID + 1) == (size - 1)))
    {
        qDebug() << "Ngirim Proposal";
        connection_client.prepare_proposal();
    }

    ui->listPlayer->addItems(list_player);
    ui->listPlayer->show();
}

void game::do_set_rule(QJsonObject message)
{
    ui->labelTime->setText(message.value("time").toString() + " - " + message.value("day").toString());
    ui->textNarration->setText(message.value("description").toString());
    //int size = connection_server.getClients().size();
}

void game::do_proposal_prepare(QJsonObject message)
{
    int c = message.value("proposal_id").toArray().at(0).toInt();

    if (connection_client.getCounter() <= c) {
        connection_client.setCounter(c);
        qDebug() << "Accepting proposal from " << message.value("proposal_id").toArray().at(1) << " with value " << c;
    }

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
        connection_client.sendMessage("10.5.22.248", "9999", json_object);
    }
}
