#ifndef INTERFACE_H
#define INTERFACE_H

#include <QObject>
#include "handler_server.h"
#include "handler_client.h"
#include "login.h"
#include "game.h"



class interface : public QObject
{
        Q_OBJECT
    public:
        explicit interface(QObject *parent = 0);

    signals:

    public slots:
        void do_display_failure(QString description);
        void do_login();

    private:
        login *w_login;
        game *w_game;
};

#endif // INTERFACE_H
