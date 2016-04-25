#include "interface.h"

interface::interface(QObject *parent) : QObject(parent)
{
    connect(&connection_server, SIGNAL(on_login()), this, SLOT(do_login()));

    /* Create user interface */
    w_login = new login;
    w_game = new game;

    connect(&connection_server, SIGNAL(on_login()), w_login, SLOT(do_destroy()));
    w_login->show();
}

void interface ::do_login()
{
    connect(&connection_server, SIGNAL(on_ready()), w_game, SLOT(do_wait_until_start()));
    connect(&connection_server, SIGNAL(on_get_clients()), w_game, SLOT(do_populate_players()));
    w_game->show();
}
