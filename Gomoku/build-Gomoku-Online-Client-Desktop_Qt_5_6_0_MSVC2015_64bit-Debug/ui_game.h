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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QWidget *centralwidget;
    QTableWidget *tableBoard;
    QListWidget *listPlayer;
    QLabel *labelListPlayer;
    QLabel *labelRoom;
    QLineEdit *textRoom;
    QPushButton *buttonPlay;
    QListWidget *listChat;
    QLabel *labelChat;
    QLineEdit *textChat;
    QPushButton *buttonChat;

    void setupUi(QMainWindow *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName(QStringLiteral("game"));
        game->resize(610, 440);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(game->sizePolicy().hasHeightForWidth());
        game->setSizePolicy(sizePolicy);
        game->setMinimumSize(QSize(610, 440));
        game->setMaximumSize(QSize(610, 440));
        QIcon icon;
        icon.addFile(QStringLiteral("../../res/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        game->setWindowIcon(icon);
        game->setToolButtonStyle(Qt::ToolButtonIconOnly);
        centralwidget = new QWidget(game);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableBoard = new QTableWidget(centralwidget);
        if (tableBoard->columnCount() < 20)
            tableBoard->setColumnCount(20);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(17, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(18, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableBoard->setHorizontalHeaderItem(19, __qtablewidgetitem19);
        if (tableBoard->rowCount() < 20)
            tableBoard->setRowCount(20);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(3, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(4, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(5, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(6, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(7, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(8, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(9, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(10, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(11, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(12, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(13, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(14, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(15, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(16, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(17, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(18, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableBoard->setVerticalHeaderItem(19, __qtablewidgetitem39);
        tableBoard->setObjectName(QStringLiteral("tableBoard"));
        tableBoard->setGeometry(QRect(20, 20, 402, 402));
        QFont font;
        font.setFamily(QStringLiteral("Lato Medium"));
        font.setPointSize(12);
        tableBoard->setFont(font);
        tableBoard->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableBoard->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableBoard->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableBoard->setTabKeyNavigation(false);
        tableBoard->setProperty("showDropIndicator", QVariant(false));
        tableBoard->setDragDropOverwriteMode(false);
        tableBoard->horizontalHeader()->setVisible(false);
        tableBoard->horizontalHeader()->setDefaultSectionSize(20);
        tableBoard->horizontalHeader()->setMinimumSectionSize(10);
        tableBoard->verticalHeader()->setVisible(false);
        tableBoard->verticalHeader()->setDefaultSectionSize(20);
        tableBoard->verticalHeader()->setMinimumSectionSize(10);
        listPlayer = new QListWidget(centralwidget);
        listPlayer->setObjectName(QStringLiteral("listPlayer"));
        listPlayer->setGeometry(QRect(440, 90, 151, 111));
        labelListPlayer = new QLabel(centralwidget);
        labelListPlayer->setObjectName(QStringLiteral("labelListPlayer"));
        labelListPlayer->setGeometry(QRect(440, 70, 151, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Lato"));
        font1.setPointSize(11);
        labelListPlayer->setFont(font1);
        labelRoom = new QLabel(centralwidget);
        labelRoom->setObjectName(QStringLiteral("labelRoom"));
        labelRoom->setGeometry(QRect(440, 20, 151, 20));
        labelRoom->setFont(font1);
        textRoom = new QLineEdit(centralwidget);
        textRoom->setObjectName(QStringLiteral("textRoom"));
        textRoom->setGeometry(QRect(440, 40, 151, 24));
        textRoom->setFont(font1);
        textRoom->setReadOnly(true);
        buttonPlay = new QPushButton(centralwidget);
        buttonPlay->setObjectName(QStringLiteral("buttonPlay"));
        buttonPlay->setGeometry(QRect(440, 390, 151, 33));
        QFont font2;
        font2.setFamily(QStringLiteral("Lato Semibold"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        buttonPlay->setFont(font2);
        listChat = new QListWidget(centralwidget);
        listChat->setObjectName(QStringLiteral("listChat"));
        listChat->setGeometry(QRect(440, 230, 151, 111));
        labelChat = new QLabel(centralwidget);
        labelChat->setObjectName(QStringLiteral("labelChat"));
        labelChat->setGeometry(QRect(440, 210, 151, 20));
        labelChat->setFont(font1);
        textChat = new QLineEdit(centralwidget);
        textChat->setObjectName(QStringLiteral("textChat"));
        textChat->setGeometry(QRect(440, 340, 121, 24));
        textChat->setFont(font1);
        buttonChat = new QPushButton(centralwidget);
        buttonChat->setObjectName(QStringLiteral("buttonChat"));
        buttonChat->setGeometry(QRect(560, 339, 32, 26));
        buttonChat->setFont(font2);
        game->setCentralWidget(centralwidget);

        retranslateUi(game);

        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QMainWindow *game)
    {
        game->setWindowTitle(QApplication::translate("game", "Gomoku Online", 0));
        QTableWidgetItem *___qtablewidgetitem = tableBoard->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("game", "0", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableBoard->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("game", "1", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableBoard->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("game", "2", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableBoard->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("game", "3", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableBoard->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("game", "4", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableBoard->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("game", "5", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableBoard->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("game", "6", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableBoard->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("game", "8", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableBoard->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("game", "8", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableBoard->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("game", "9", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableBoard->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("game", "10", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableBoard->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("game", "11", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableBoard->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("game", "12", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableBoard->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("game", "13", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableBoard->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("game", "14", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableBoard->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("game", "15", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableBoard->horizontalHeaderItem(16);
        ___qtablewidgetitem16->setText(QApplication::translate("game", "16", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableBoard->horizontalHeaderItem(17);
        ___qtablewidgetitem17->setText(QApplication::translate("game", "17", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableBoard->horizontalHeaderItem(18);
        ___qtablewidgetitem18->setText(QApplication::translate("game", "18", 0));
        QTableWidgetItem *___qtablewidgetitem19 = tableBoard->horizontalHeaderItem(19);
        ___qtablewidgetitem19->setText(QApplication::translate("game", "19", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableBoard->verticalHeaderItem(0);
        ___qtablewidgetitem20->setText(QApplication::translate("game", "0", 0));
        QTableWidgetItem *___qtablewidgetitem21 = tableBoard->verticalHeaderItem(1);
        ___qtablewidgetitem21->setText(QApplication::translate("game", "1", 0));
        QTableWidgetItem *___qtablewidgetitem22 = tableBoard->verticalHeaderItem(2);
        ___qtablewidgetitem22->setText(QApplication::translate("game", "2", 0));
        QTableWidgetItem *___qtablewidgetitem23 = tableBoard->verticalHeaderItem(3);
        ___qtablewidgetitem23->setText(QApplication::translate("game", "3", 0));
        QTableWidgetItem *___qtablewidgetitem24 = tableBoard->verticalHeaderItem(4);
        ___qtablewidgetitem24->setText(QApplication::translate("game", "4", 0));
        QTableWidgetItem *___qtablewidgetitem25 = tableBoard->verticalHeaderItem(5);
        ___qtablewidgetitem25->setText(QApplication::translate("game", "5", 0));
        QTableWidgetItem *___qtablewidgetitem26 = tableBoard->verticalHeaderItem(6);
        ___qtablewidgetitem26->setText(QApplication::translate("game", "6", 0));
        QTableWidgetItem *___qtablewidgetitem27 = tableBoard->verticalHeaderItem(7);
        ___qtablewidgetitem27->setText(QApplication::translate("game", "7", 0));
        QTableWidgetItem *___qtablewidgetitem28 = tableBoard->verticalHeaderItem(8);
        ___qtablewidgetitem28->setText(QApplication::translate("game", "8", 0));
        QTableWidgetItem *___qtablewidgetitem29 = tableBoard->verticalHeaderItem(9);
        ___qtablewidgetitem29->setText(QApplication::translate("game", "9", 0));
        QTableWidgetItem *___qtablewidgetitem30 = tableBoard->verticalHeaderItem(10);
        ___qtablewidgetitem30->setText(QApplication::translate("game", "10", 0));
        QTableWidgetItem *___qtablewidgetitem31 = tableBoard->verticalHeaderItem(11);
        ___qtablewidgetitem31->setText(QApplication::translate("game", "11", 0));
        QTableWidgetItem *___qtablewidgetitem32 = tableBoard->verticalHeaderItem(12);
        ___qtablewidgetitem32->setText(QApplication::translate("game", "12", 0));
        QTableWidgetItem *___qtablewidgetitem33 = tableBoard->verticalHeaderItem(13);
        ___qtablewidgetitem33->setText(QApplication::translate("game", "13", 0));
        QTableWidgetItem *___qtablewidgetitem34 = tableBoard->verticalHeaderItem(14);
        ___qtablewidgetitem34->setText(QApplication::translate("game", "14", 0));
        QTableWidgetItem *___qtablewidgetitem35 = tableBoard->verticalHeaderItem(15);
        ___qtablewidgetitem35->setText(QApplication::translate("game", "15", 0));
        QTableWidgetItem *___qtablewidgetitem36 = tableBoard->verticalHeaderItem(16);
        ___qtablewidgetitem36->setText(QApplication::translate("game", "16", 0));
        QTableWidgetItem *___qtablewidgetitem37 = tableBoard->verticalHeaderItem(17);
        ___qtablewidgetitem37->setText(QApplication::translate("game", "17", 0));
        QTableWidgetItem *___qtablewidgetitem38 = tableBoard->verticalHeaderItem(18);
        ___qtablewidgetitem38->setText(QApplication::translate("game", "18", 0));
        QTableWidgetItem *___qtablewidgetitem39 = tableBoard->verticalHeaderItem(19);
        ___qtablewidgetitem39->setText(QApplication::translate("game", "19", 0));
        labelListPlayer->setText(QApplication::translate("game", "Player List:", 0));
        labelRoom->setText(QApplication::translate("game", "Room:", 0));
        textRoom->setPlaceholderText(QApplication::translate("game", "#HMIFDrama", 0));
        buttonPlay->setText(QApplication::translate("game", "Start Game!", 0));
        labelChat->setText(QApplication::translate("game", "Chat Box", 0));
        textChat->setPlaceholderText(QApplication::translate("game", "Say hello :)", 0));
        buttonChat->setText(QApplication::translate("game", ">", 0));
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
