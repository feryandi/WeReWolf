#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QTimer>
#include <QMutex>
#include "handler_server.h"
#include "handler_client.h"

namespace Ui {
    class game;
}

class game : public QMainWindow {
        Q_OBJECT

    public:
        explicit game(QWidget *parent = 0);
        ~game();

    private slots:
        void do_start();
        void do_wait_until_start();
        void do_populate_players();
        void do_set_rule(QJsonObject message);
        void on_buttonVote_clicked();
        void do_proposal_prepare(QJsonObject message, QHostAddress sender_ip, quint16 sender_port);
        void do_proposal_accept(QJsonObject message, QHostAddress sender_ip, quint16 sender_port);
        void do_set_kpu_selected();
        void do_vote_now();

    private:
        Ui::game *ui;
        QMutex mutex;
        QTimer *timer;
};

#endif // GAME_H
