/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QLabel *labelTitle;
    QLabel *labelTime;
    QPushButton *buttonVote;
    QTextEdit *textNarration;
    QListWidget *listPlayer;
    QLabel *labelRole;

    void setupUi(QMainWindow *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName(QStringLiteral("game"));
        game->resize(420, 360);
        centralwidget = new QWidget(game);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(40, 40, 341, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        labelTitle = new QLabel(centralwidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setGeometry(QRect(40, 10, 391, 31));
        QFont font;
        font.setFamily(QStringLiteral("Lato"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignCenter);
        labelTime = new QLabel(centralwidget);
        labelTime->setObjectName(QStringLiteral("labelTime"));
        labelTime->setGeometry(QRect(30, 60, 371, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Lato"));
        font1.setPointSize(11);
        labelTime->setFont(font1);
        labelTime->setAlignment(Qt::AlignCenter);
        buttonVote = new QPushButton(centralwidget);
        buttonVote->setObjectName(QStringLiteral("buttonVote"));
        buttonVote->setGeometry(QRect(20, 320, 381, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Lato Semibold"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        buttonVote->setFont(font2);
        buttonVote->setFocusPolicy(Qt::TabFocus);
        buttonVote->setCheckable(false);
        buttonVote->setAutoDefault(false);
        buttonVote->setFlat(false);
        textNarration = new QTextEdit(centralwidget);
        textNarration->setObjectName(QStringLiteral("textNarration"));
        textNarration->setGeometry(QRect(20, 110, 381, 71));
        QFont font3;
        font3.setItalic(false);
        textNarration->setFont(font3);
        listPlayer = new QListWidget(centralwidget);
        new QListWidgetItem(listPlayer);
        new QListWidgetItem(listPlayer);
        new QListWidgetItem(listPlayer);
        new QListWidgetItem(listPlayer);
        new QListWidgetItem(listPlayer);
        new QListWidgetItem(listPlayer);
        new QListWidgetItem(listPlayer);
        listPlayer->setObjectName(QStringLiteral("listPlayer"));
        listPlayer->setGeometry(QRect(20, 190, 381, 121));
        labelRole = new QLabel(centralwidget);
        labelRole->setObjectName(QStringLiteral("labelRole"));
        labelRole->setGeometry(QRect(30, 80, 361, 20));
        QFont font4;
        font4.setFamily(QStringLiteral("Lato"));
        font4.setPointSize(9);
        labelRole->setFont(font4);
        labelRole->setAlignment(Qt::AlignCenter);
        game->setCentralWidget(centralwidget);

        retranslateUi(game);

        buttonVote->setDefault(false);


        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QMainWindow *game)
    {
        game->setWindowTitle(QApplication::translate("game", "WeReWolf", 0));
        labelTitle->setText(QApplication::translate("game", "WeReWolf - The Game", 0));
        labelTime->setText(QApplication::translate("game", "DAY TIME", 0));
        buttonVote->setText(QApplication::translate("game", "Ready!", 0));
        textNarration->setHtml(QApplication::translate("game", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Lato'; font-size:9pt;\">Pagi harinya, warga bernama Ryan ditemukan terbunuh dan tidak bernyawa lagi. Werewolf harus segera ditemukan, pilih salah satu warga untuk dibunuh.</span></p></body></html>", 0));

        const bool __sortingEnabled = listPlayer->isSortingEnabled();
        listPlayer->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listPlayer->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("game", "New Item", 0));
        QListWidgetItem *___qlistwidgetitem1 = listPlayer->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("game", "New Item", 0));
        QListWidgetItem *___qlistwidgetitem2 = listPlayer->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("game", "New Item", 0));
        QListWidgetItem *___qlistwidgetitem3 = listPlayer->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("game", "New Item", 0));
        QListWidgetItem *___qlistwidgetitem4 = listPlayer->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("game", "New Item", 0));
        QListWidgetItem *___qlistwidgetitem5 = listPlayer->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("game", "New Item", 0));
        QListWidgetItem *___qlistwidgetitem6 = listPlayer->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("game", "New Item", 0));
        listPlayer->setSortingEnabled(__sortingEnabled);

        labelRole->setText(QApplication::translate("game", "ROLE", 0));
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
