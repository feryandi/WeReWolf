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

void login::on_buttonPlay_clicked()
{
    /* Setup information */
    nickname = ui->textNickname->text();
    QString server_ip = ui->textServerIP->text();
    qint16 server_port = ui->textServerPort->text().toInt();
    qint16 client_port = ui->textClientPort->text().toInt();

    /* Establish connection */
    connection_server.doConnect(server_ip, server_port);
    connection_client.doListen(client_port);

    /* Send join message */
    QJsonObject json_object;
    json_object.insert("method", "join");
    json_object.insert("username", nickname.toStdString().c_str());
    connection_server.sendMessageJSON(json_object);
}
