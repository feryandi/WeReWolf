#ifndef INTERFACE_H
#define INTERFACE_H

#include <QObject>
#include "handler_server.h"
#include "handler_client.h"
#include "login.h"
#include "game.h"
#include "gameover.h"



class interface : public QObject {
        Q_OBJECT

    public:
        explicit interface(QObject *parent = 0);

    signals:

    public slots:
        void do_login();

    private:
        login *w_login;
        game *w_game;
        gameover *w_gameover;
};

#endif // INTERFACE_H
