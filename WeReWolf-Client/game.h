#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include "handler_server.h"

namespace Ui {
class game;
}

class game : public QMainWindow
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = 0);
    ~game();

private slots:
    void do_wait_until_start();
    void do_populate_players();
    void on_buttonVote_clicked();

private:
    Ui::game *ui;
};

#endif // GAME_H