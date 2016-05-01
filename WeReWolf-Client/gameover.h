#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>
#include <QCloseEvent>
#include "handler_client.h"
#include "handler_server.h"

namespace Ui {
class gameover;
}

class gameover : public QDialog
{
    Q_OBJECT

public:
    explicit gameover(QWidget *parent = 0);
    ~gameover();
    void closeEvent(QCloseEvent *event);

private slots:
    void on_buttonOK_clicked();
    void do_show(QJsonObject data);

private:
    Ui::gameover *ui;
};

#endif // GAMEOVER_H
