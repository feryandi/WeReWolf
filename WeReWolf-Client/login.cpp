#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) : QMainWindow(parent), ui(new Ui::login) {
    ui->setupUi(this);
    ui->labelNickname->setStyleSheet("QLabel { color : white; }");
    ui->label->setStyleSheet("QLabel { color : white; }");
    ui->labelServerIP->setStyleSheet("QLabel { color : white; }");
    ui->labelServerPort->setStyleSheet("QLabel { color : white; }");

}

login::~login() {
    delete ui;
}

void login::on_buttonPlay_clicked() {
    /* Setup information */
    QString server_ip = ui->textServerIP->text();
    qint16 server_port = ui->textServerPort->text().toInt();
    QString client_port = ui->textClientPort->text();
    QString player_name;

    if (ui->textNickname->text() == "") {
        player_name = "user_name";
    } else {
        player_name = ui->textNickname->text();
    }
    connection_server.setPlayerName(player_name);

    /* Establish connection */
    connection_server.doConnect(server_ip, server_port);
    connection_client.doListen(client_port.toInt());

    /* Send join message */
    QJsonObject json_object;
    json_object.insert("method", "join");
    json_object.insert("username", player_name.toStdString().c_str());
    json_object.insert("udp_address", connection_server.getLocalAddress().toStdString().c_str());
    json_object.insert("udp_port", client_port.toInt());
    connection_server.sendMessageJSON(json_object);
}

void login::do_destroy() {
    delete this;
}
