#ifndef INTERFACE_H
#define INTERFACE_H

#include <QObject>
#include "client.h"
#include "login.h"
#include "lobby.h"
#include "game.h"
#include "gameover.h"


class interface : public QObject
{
		Q_OBJECT
	public:
		explicit interface(QObject *parent = 0);

	signals:

	public slots:
		void on_login();

	private:
		login *w_login;
		lobby *w_lobby;
		game *w_game;
		gameover *w_gameover;

};

#endif // INTERFACE_H
