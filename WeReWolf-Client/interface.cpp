#include "interface.h"

interface::interface(QObject *parent) : QObject(parent)
{
    connect(&connection_server, SIGNAL(on_login()), this, SLOT(do_login()));
    connect(&connection_server, SIGNAL(on_fail_or_error(QString)), this, SLOT(do_display_failure(QString)));


    /* Create user interface */
    w_login = new login;
    w_game = new game;
    w_gameover = new gameover;

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
    connect(&connection_client, SIGNAL(on_accept_prepare_proposal(QJsonObject, QHostAddress, quint16)), w_game, SLOT(do_proposal_prepare(QJsonObject,QHostAddress,quint16)));
    connect(&connection_client, SIGNAL(on_accept_accept_proposal(QJsonObject, QHostAddress, quint16)), w_game, SLOT(do_proposal_accept(QJsonObject,QHostAddress,quint16)));
    connect(&connection_server, SIGNAL(on_game_over(QJsonObject)), w_gameover, SLOT(do_show(QJsonObject)));
    connect(w_gameover, SIGNAL(on_deletegameover()), w_gameover, SLOT(do_delete()));
    connect(w_gameover, SIGNAL(on_deletegameover()), w_login, SLOT(do_destroy()));
    connect(w_gameover, SIGNAL(on_deletegameover()), w_game, SLOT(do_delete()));
    connect(&connection_server, SIGNAL(on_kpu_is_selected()), w_game, SLOT(do_set_kpu_selected()));
    connect(&connection_server, SIGNAL(on_vote_now()), w_game, SLOT(do_vote_now()));

    w_game->show();
}
