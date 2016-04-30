#include "interface.h"

interface::interface(QObject *parent) : QObject(parent)
{
    connect(&connection_server, SIGNAL(on_login()), this, SLOT(do_login()));
    connect(&connection_server, SIGNAL(on_fail_or_error(QString)), this, SLOT(do_display_failure(QString)));


    /* Create user interface */
    w_login = new login;
    w_game = new game;

    connect(&connection_server, SIGNAL(on_login()), w_login, SLOT(do_destroy()));
    w_login->show();
}

void interface::do_display_failure(QString description)
{
    qDebug() << description;
}

void interface ::do_login()
{
    connect(&connection_server, SIGNAL(on_ready()), w_game, SLOT(do_wait_until_start()));
    connect(&connection_server, SIGNAL(on_get_clients()), w_game, SLOT(do_populate_players()));
    connect(&connection_server, SIGNAL(on_start()), w_game, SLOT(do_start()));
    connect(&connection_server, SIGNAL(on_change_phase(QJsonObject)), w_game, SLOT(do_set_rule(QJsonObject)));
    connect(&connection_client, SIGNAL(on_accept_prepare_proposal(QJsonObject)), w_game, SLOT(do_proposal_prepare(QJsonObject)));
    w_game->show();
}
