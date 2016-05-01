#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login),
    nickname("user_name")
{
    ui->setupUi(this);
    ui->labelNickname->setStyleSheet("QLabel { color : white; }");
    ui->label->setStyleSheet("QLabel { color : white; }");
    ui->labelServerIP->setStyleSheet("QLabel { color : white; }");
    ui->labelServerPort->setStyleSheet("QLabel { color : white; }");
    //ui->labelBackground->setPixmap(QPixmap(":/assets/login-bg.png"));

    //qDebug()<<"File exists -"<<QFileInfo(":/assets/login-bg.png").exists()<<" "<<QFileInfo(":/assets/login-bg.png").absoluteFilePath();
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
    /* Setup information */
    if (ui->textNickname->text() != ""){
        nickname = ui->textNickname->text();
    }
    connection_server.setPlayerName(nickname);
    QString server_ip = ui->textServerIP->text();
    qint16 server_port = ui->textServerPort->text().toInt();
    QString client_port = ui->textClientPort->text();

    /* Establish connection */
    connection_server.doConnect(server_ip, server_port);
    connection_client.doListen(client_port.toInt());

    /* Send join message */
    QJsonObject json_object;
    json_object.insert("method", "join");
    json_object.insert("username", nickname.toStdString().c_str());
    json_object.insert("udp_address", connection_server.getLocalAddress().toStdString().c_str());
    json_object.insert("udp_port", client_port.toInt());
    connection_server.sendMessageJSON(json_object);
}
