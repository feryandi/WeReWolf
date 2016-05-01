#include "gameover.h"
#include "ui_gameover.h"

gameover::gameover(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameover)
{
    ui->setupUi(this);
}

gameover::~gameover()
{
    delete ui;
}

void gameover::closeEvent(QCloseEvent *event)
{
    on_buttonOK_clicked();
    event->ignore();
}

void gameover::on_buttonOK_clicked()
{
    QJsonObject json_object;
        json_object.insert("method", "leave");
        connection_server.sendMessageJSON(json_object);
    emit on_deletegameover();
}

void gameover::do_show(QJsonObject data)
{
    ui->labelWinner->setText("The winner is " + data.value("winner").toString());
    this->show();
}

void gameover::do_delete()
{
    QApplication::quit();
    delete this;
}
