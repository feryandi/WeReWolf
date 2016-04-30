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
    ui->labelRole->setText(connection_server.getPlayerName() + ", you are " + connection_server.getRole() + "!");
    ui->labelRole->show();
    ui->buttonVote->setText("Vote!");
    ui->buttonVote->setEnabled(true);
}

void game::do_wait_until_start()
{
    ui->labelTime->setText("Please wait for other players...");
    ui->buttonVote->setDisabled(true);
}

void game::do_populate_players()
{
    /* Night = 0
     * Day = 1 */

    ui->listPlayer->clear();
    QStringList list_player;
    int size = connection_server.getClients().size();

    if ( connection_server.getCurrentTime() == 1 ) {
        QJsonObject json_object;
        for (int i=0; i<size; i++){
            json_object = connection_server.getClients().at(i).toObject();
            if (json_object.value("is_alive").toInt() == 1){
                list_player += json_object.value("username").toString();
            }
        }
         ui->buttonVote->setEnabled(true);
    } else {
        QJsonArray json_array;
        json_array = connection_server.getNonFriends();
        for (int i=0; i<json_array.size(); i++){
            list_player += json_array.at(i).toString();
        }

        if (connection_server.getRole() == "villager"){
            ui->buttonVote->setDisabled(true);
        }

        qDebug() << "Total non-friends: " << json_array.size();
    }

    qDebug() << "Total client: " << connection_server.getClients().size();

    int clientID = static_cast<int>(connection_server.getPlayerId());
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

    connection_server.setCurrentTime(message.value("time").toString());
    connection_server.setCurrentDay(message.value("day").toInt());

    /* Send list clients message */
    QJsonObject json_object;
    json_object.insert("method", "client_address");
    connection_server.sendMessageJSON(json_object);

    /*if (message.value("time").toString() == "night") {
        do_populate_players(0);
    } else {
        do_populate_players(1);
    }*/
}

void game::do_proposal_prepare(QJsonObject message, QHostAddress sender_ip, quint16 sender_port)
{
    int c = message.value("proposal_id").toArray().at(0).toInt();
    int recentCounter = connection_client.getCounterLocal();
    int newKPU = message.value("proposal_id").toArray().at(1).toInt();
    int lastKPU = connection_client.getLastKPU();
    QJsonObject json_object;
    qDebug() << "DO_PROPOSAL_PREPARE";
    qDebug() << "c = " << c;
    qDebug() << "recentCounter = " << recentCounter;
    qDebug() << "lastKPU = " << lastKPU;
    qDebug() << "newKPU = " << newKPU;
    if ((recentCounter < c) || ((recentCounter == c) && (lastKPU  < newKPU))) {
        connection_client.setCounter(c);

        if (lastKPU == -1) {
            json_object.insert("status","ok");
            json_object.insert("description","accepted");
        } else {
            json_object.insert("status","ok");
            json_object.insert("description","accepted");
            json_object.insert("previous_accepted",lastKPU);
        }

        /* Kalo dia potensial jadi leader dan dia udah dapet proposal lain,
         * maka dia ngalah ga kirim proposal selama x ms */
        int size = connection_server.getClients().size();
        int clientID = static_cast<int>(connection_server.getPlayerId());
        if (((clientID) == size-1) || ((clientID) == (size - 2))) {
            if (connection_client.getCounterPrepare() >= (size-1)) {
                //QTimer::singleShot(1000, &connection_client, SLOT(accept_proposal()));
                connection_client.accept_proposal();
            }
        }

        connection_client.setLastKPU(newKPU);
        connection_client.sendMessage(sender_ip.toString(), QString::number(sender_port), json_object);

        qDebug() << "Accepting proposal from " << message.value("proposal_id").toArray().at(1) << " with value " << c;
    } else {
        json_object.insert("status","fail");
        json_object.insert("description","rejected");
        connection_client.sendMessage(sender_ip.toString(), QString::number(sender_port), json_object);
    }
}

void game::do_proposal_accept(QJsonObject message, QHostAddress sender_ip, quint16 sender_port)
{
    int c = message.value("proposal_id").toArray().at(0).toInt();
    int recentCounter = connection_client.getCounterLocal();
    int playerId = message.value("proposal_id").toArray().at(1).toInt();
    int lastKPU = connection_client.getLastKPU();
    int kpuId = message.value("kpu_id").toInt();
    QJsonObject json_object;

    qDebug() << "DO_PROPOSAL_ACCEPT";
    qDebug() << "c = " << c;
    qDebug() << "recentCounter = " << recentCounter;
    qDebug() << "lastKPU = " << lastKPU;
    qDebug() << "kpuId = " << kpuId;

    if ((recentCounter == c) && ((playerId == lastKPU) && (kpuId  == lastKPU))) {
        json_object.insert("status","ok");
        json_object.insert("description","accepted");

        connection_client.sendMessage(sender_ip.toString(), QString::number(sender_port), json_object);
        qDebug() << "Konfirmasi KPU " << message.value("proposal_id").toArray().at(1) << " with value " << c;
    } else {
        json_object.insert("status","fail");
        json_object.insert("description","rejected");
        connection_client.sendMessage(sender_ip.toString(), QString::number(sender_port), json_object);
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
        QString username = ui->listPlayer->currentItem()->text();
        QString sender_ip;
        quint16 sender_port;

        sender_ip = connection_server.getClientDataByUsername(username).value("address").toString();
        sender_port = (connection_server.getClientDataByUsername(username)).value("port").toInt();

        if (connection_server.getCurrentTime() == 1){
            QJsonObject json_object;
            json_object.insert("method", "vote_civilian");
            json_object.insert("player_id",
                               connection_server.getClientIdByUsername(username));

            connection_client.sendMessage(sender_ip, QString::number(sender_port), json_object);
        } else {
            QJsonObject json_object;
            json_object.insert("method", "vote_werewolf");
            json_object.insert("player_id",
                               connection_server.getClientIdByUsername(username));

            connection_client.sendMessage(sender_ip, QString::number(sender_port), json_object);
        }
    }
}
