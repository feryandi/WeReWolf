#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game)
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), &connection_client, SLOT(prepare_proposal()));

    ui->setupUi(this);
    ui->labelTime->setText("Please press READY to start the game!");
    ui->textNarration->setText("When the night comes, it's time for darkness to approach.");
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

    QJsonObject json_object;
    QJsonArray json_array;
    for (int i = 0; i < connection_server.getClients().size(); i++) {
        json_array.insert(0, i);
        json_array.insert(1, 0);
        connection_client.vote_result.insert(i, QJsonValue::fromVariant(json_array));
        json_array.removeFirst();
        json_array.removeFirst();

        connection_client.vote_map[i] = 0;
    }

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
    } else {
        QJsonArray json_array;
        json_array = connection_server.getNonFriends();
        for (int i=0; i<json_array.size(); i++){
            if (connection_server.getClientDataByUsername(json_array.at(i).toString()).value("is_alive").toInt() == 1){
                list_player += json_array.at(i).toString();
            }
        }

        qDebug() << "Total non-friends: " << json_array.size();
    }

    qDebug() << "Total client: " << connection_server.getClients().size();

    ui->listPlayer->addItems(list_player);
    ui->listPlayer->show();

    qDebug() << "Current time: " <<connection_server.getCurrentTime();

    if ( connection_server.getCurrentTime() == 0 ) {
        if (connection_server.getRole() == "civilian"){
            ui->buttonVote->setDisabled(true);
            ui->buttonVote->setEnabled(false);
        }
    }

    QJsonObject player_data;
    player_data = connection_server.getClientDataByUsername(connection_server.getPlayerName());
    if (player_data.value("is_alive").toInt() == 0) {
        ui->buttonVote->setText("You died :(");
        ui->buttonVote->setDisabled(true);
        ui->buttonVote->setEnabled(false);
    }

    timer->stop();
    if ( connection_server.getCurrentTime() == 1 ) {
        connection_server.kpu_id = -1;

        qDebug() << "Start Ngirim Proposal";

        int clientID = static_cast<int>(connection_server.getPlayerId());
        if (((clientID + 1) == size) || ((clientID + 1) == (size - 1)))
        {
            /* Ngirim Proposal Terus-terusan sampe kpu_id diterima */
            qDebug() << "Ngirim Proposal";

            if (connection_server.kpu_id == -1){
                ui->buttonVote->setDisabled(true);
                timer->start(1000);
            } else {
                timer->stop();
            }
        }
    } else {
        timer->stop();
    }
}

void game::do_set_rule(QJsonObject message)
{
    ui->labelTime->setText(message.value("time").toString() + " - day " + QString::number(message.value("days").toInt()));
    ui->textNarration->setText(message.value("description").toString());

    connection_server.setCurrentTime(message.value("time").toString());
    connection_server.setCurrentDay(message.value("day").toInt());
    connection_server.kpu_id = -1;

    /* Send list clients message */
    QJsonObject json_object;
    json_object.insert("method", "client_address");
    connection_server.sendMessageJSON(json_object);

    connection_client.resetVote();
}

void game::do_proposal_prepare(QJsonObject message, QHostAddress sender_ip, quint16 sender_port)
{
    mutex.lock();
    int c = message.value("proposal_id").toArray().at(0).toInt();
    int recentCounter = connection_client.getCounterLocal();
    int newKPU = message.value("proposal_id").toArray().at(1).toInt();
    int lastKPU = connection_client.getLastKPU();
    QJsonObject json_object;

    qDebug() << "DO_PROPOSAL_PREPARE";

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
                connection_client.accept_proposal();
            }
        }

        connection_client.setLastKPU(newKPU);
        connection_client.sendMessage(sender_ip.toString(), sender_port, json_object,0);

        qDebug() << "Accepting proposal from " << message.value("proposal_id").toArray().at(1) << " with value " << c;
    } else {
        json_object.insert("status","fail");
        json_object.insert("description","rejected");
        connection_client.sendMessage(sender_ip.toString(), sender_port, json_object,0);
    }
    mutex.unlock();
}

void game::do_proposal_accept(QJsonObject message, QHostAddress sender_ip, quint16 sender_port)
{
    mutex.lock();
    int c = message.value("proposal_id").toArray().at(0).toInt();
    int recentCounter = connection_client.getCounterLocal();
    int playerId = message.value("proposal_id").toArray().at(1).toInt();
    int lastKPU = connection_client.getLastKPU();
    int kpuId = message.value("kpu_id").toInt();
    QJsonObject json_object;

    qDebug() << "DO_PROPOSAL_ACCEPT";

    if ((recentCounter == c) && ((playerId == lastKPU) && (kpuId  == lastKPU))) {
        json_object.insert("status","ok");
        json_object.insert("description","accepted");

        connection_client.sendMessage(sender_ip.toString(), sender_port, json_object,0);
        qDebug() << "Konfirmasi KPU " << message.value("proposal_id").toArray().at(1) << " with value " << c;

        QJsonObject json_object_;
        json_object_.insert("method", "accepted_proposal");
        json_object_.insert("kpu_id", connection_client.getLastKPU());
        json_object_.insert("Description", "Kpu is selected");

        connection_server.sendMessageJSON(json_object_);

    } else {
        json_object.insert("status","fail");
        json_object.insert("description","rejected");
        connection_client.sendMessage(sender_ip.toString(), sender_port, json_object,0);
    }
    mutex.unlock();
}


void game::on_buttonVote_clicked()
{
    if (ui->buttonVote->text() == "Ready!"){
        /* Send ready message */
        QJsonObject json_object;
        json_object.insert("method", "ready");
        connection_server.sendMessageJSON(json_object);
    } else if (ui->listPlayer->selectedItems().count() == 1) {
        QString username = ui->listPlayer->currentItem()->text();
        QString sender_ip;
        quint16 sender_port;

        sender_ip = connection_server.getClientDataById(connection_client.getLastKPU()).value("address").toString();
        sender_port = connection_server.getClientDataById(connection_client.getLastKPU()).value("port").toInt();

        if (connection_server.getCurrentTime() == 1){
            QJsonObject json_object;
            json_object.insert("method", "vote_civilian");
            json_object.insert("player_id",
                               connection_server.getClientIdByUsername(username));

            connection_client.sendMessage(sender_ip, sender_port, json_object,1);
        } else {
            QJsonObject json_object;
            json_object.insert("method", "vote_werewolf");
            json_object.insert("player_id",
                               connection_server.getClientIdByUsername(username));

            qDebug() << "KIRIM KE:" <<  sender_ip << " Poert : " << sender_port;
            connection_client.sendMessage(sender_ip, sender_port, json_object,1);
        }
    }
    ui->buttonVote->setDisabled(true);
}

void game::do_delete() {
    delete this;
}

void game::do_set_kpu_selected()
{
    timer->stop();
    connection_client.setLastKPU(connection_server.kpu_id);
    QJsonObject message;
    message.insert("status","ok");
    connection_server.sendMessageJSON(message);
}

void game::do_vote_now()
{
    ui->buttonVote->setEnabled(true);

    if ( connection_server.getCurrentTime() == 0 ) {
        if (connection_server.getRole() == "civilian"){
            ui->buttonVote->setDisabled(true);
            ui->buttonVote->setEnabled(false);
        }
    }

    QJsonObject player_data;
    player_data = connection_server.getClientDataByUsername(connection_server.getPlayerName());
    if (player_data.value("is_alive").toInt() == 0) {
        ui->buttonVote->setText("You died :(");
        ui->buttonVote->setDisabled(true);
        ui->buttonVote->setEnabled(false);
    }
}
