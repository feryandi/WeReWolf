#include "interface.h"

interface::interface(QObject *parent) : QObject(parent)
{
	connect(&connection, SIGNAL(on_login()), this, SLOT(on_login()));

	/* Creating the user interface */
	w_login = new login;
	w_lobby = new lobby;
	w_game = new game;
	w_gameover = new gameover;
	connect(&connection, SIGNAL(on_login()), w_login, SLOT(do_destroy()));
	w_login->show();
}

void interface::on_login()
{
	connect(&connection, SIGNAL(on_refresh_rooms(QJsonArray)), w_lobby, SLOT(populate_room(QJsonArray)));
	connect(&connection, SIGNAL(on_refresh_players(QJsonArray)), w_game, SLOT(populate_players(QJsonArray)));

	connect(&connection, SIGNAL(on_create_room(int)), w_lobby, SLOT(on_join(int)));
	connect(&connection, SIGNAL(on_join(int)), w_lobby, SLOT(do_hide()));
	connect(&connection, SIGNAL(on_join(int)), w_game, SLOT(do_show(int)));

	connect(&connection, SIGNAL(on_spectate(int)), w_lobby, SLOT(do_hide()));
	connect(&connection, SIGNAL(on_spectate(int)), w_game, SLOT(do_show(int)));
	connect(&connection, SIGNAL(on_refresh_board(QJsonArray)), w_game, SLOT(populate_board(QJsonArray)));

	connect(w_game, SIGNAL(on_closegame()), w_game, SLOT(on_game_destroyed()));
	connect(&connection, SIGNAL(on_close_game()), w_game, SLOT(do_hide()));
    connect(&connection, SIGNAL(on_close_game()), w_lobby, SLOT(do_show()));

	connect(&connection, SIGNAL(on_update_game(QJsonObject)), w_game, SLOT(do_updategame(QJsonObject)));
	connect(&connection, SIGNAL(on_start_game()), w_game, SLOT(do_startgame()));
	connect(&connection, SIGNAL(on_highlight(QJsonObject)), w_game, SLOT(do_highlight(QJsonObject)));

	connect(&connection, SIGNAL(on_game_over(QJsonObject)), w_gameover, SLOT(do_show(QJsonObject)));
	connect(w_gameover, SIGNAL(on_deletegameover()), w_gameover, SLOT(do_delete()));

	connect(&connection, SIGNAL(on_chat(QJsonObject)), w_game, SLOT(do_chat(QJsonObject)));

	w_lobby->show();
}
