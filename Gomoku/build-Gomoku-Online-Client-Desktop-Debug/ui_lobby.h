/********************************************************************************
** Form generated from reading UI file 'lobby.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOBBY_H
#define UI_LOBBY_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lobby
{
public:
    QWidget *centralwidget;
    QLabel *labelCreateRoom;
    QLabel *labelJoinRoom;
    QLineEdit *textCreateRoom;
    QPushButton *buttonCreateRoom;
    QListWidget *listRoom;
    QPushButton *buttonJoinRoom;
    QPushButton *buttonSpectate;
    QPushButton *buttonRefreshRoom;

    void setupUi(QMainWindow *lobby)
    {
        if (lobby->objectName().isEmpty())
            lobby->setObjectName(QStringLiteral("lobby"));
        lobby->resize(400, 340);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lobby->sizePolicy().hasHeightForWidth());
        lobby->setSizePolicy(sizePolicy);
        lobby->setMinimumSize(QSize(400, 340));
        lobby->setMaximumSize(QSize(400, 340));
        QIcon icon;
        icon.addFile(QStringLiteral("../../res/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        lobby->setWindowIcon(icon);
        centralwidget = new QWidget(lobby);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        labelCreateRoom = new QLabel(centralwidget);
        labelCreateRoom->setObjectName(QStringLiteral("labelCreateRoom"));
        labelCreateRoom->setGeometry(QRect(20, 20, 271, 20));
        QFont font;
        font.setFamily(QStringLiteral("Lato"));
        font.setPointSize(11);
        labelCreateRoom->setFont(font);
        labelJoinRoom = new QLabel(centralwidget);
        labelJoinRoom->setObjectName(QStringLiteral("labelJoinRoom"));
        labelJoinRoom->setGeometry(QRect(20, 90, 271, 20));
        labelJoinRoom->setFont(font);
        textCreateRoom = new QLineEdit(centralwidget);
        textCreateRoom->setObjectName(QStringLiteral("textCreateRoom"));
        textCreateRoom->setGeometry(QRect(20, 50, 271, 24));
        textCreateRoom->setFont(font);
        buttonCreateRoom = new QPushButton(centralwidget);
        buttonCreateRoom->setObjectName(QStringLiteral("buttonCreateRoom"));
        buttonCreateRoom->setGeometry(QRect(300, 50, 81, 26));
        QFont font1;
        font1.setFamily(QStringLiteral("Lato Semibold"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        buttonCreateRoom->setFont(font1);
        listRoom = new QListWidget(centralwidget);
        listRoom->setObjectName(QStringLiteral("listRoom"));
        listRoom->setGeometry(QRect(20, 120, 271, 192));
        buttonJoinRoom = new QPushButton(centralwidget);
        buttonJoinRoom->setObjectName(QStringLiteral("buttonJoinRoom"));
        buttonJoinRoom->setGeometry(QRect(300, 120, 81, 26));
        buttonJoinRoom->setFont(font1);
        buttonSpectate = new QPushButton(centralwidget);
        buttonSpectate->setObjectName(QStringLiteral("buttonSpectate"));
        buttonSpectate->setGeometry(QRect(300, 160, 81, 26));
        buttonSpectate->setFont(font1);
        buttonRefreshRoom = new QPushButton(centralwidget);
        buttonRefreshRoom->setObjectName(QStringLiteral("buttonRefreshRoom"));
        buttonRefreshRoom->setGeometry(QRect(300, 200, 81, 26));
        buttonRefreshRoom->setFont(font1);
        lobby->setCentralWidget(centralwidget);

        retranslateUi(lobby);

        QMetaObject::connectSlotsByName(lobby);
    } // setupUi

    void retranslateUi(QMainWindow *lobby)
    {
        lobby->setWindowTitle(QApplication::translate("lobby", "Enter a room", 0));
        labelCreateRoom->setText(QApplication::translate("lobby", "Enter a new room name and click create:", 0));
        labelJoinRoom->setText(QApplication::translate("lobby", "Or select a room from the list below:", 0));
        textCreateRoom->setPlaceholderText(QApplication::translate("lobby", "#HMIFDrama", 0));
        buttonCreateRoom->setText(QApplication::translate("lobby", "Create", 0));
        buttonJoinRoom->setText(QApplication::translate("lobby", "Join", 0));
        buttonSpectate->setText(QApplication::translate("lobby", "Spectate", 0));
        buttonRefreshRoom->setText(QApplication::translate("lobby", "Refresh", 0));
    } // retranslateUi

};

namespace Ui {
    class lobby: public Ui_lobby {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOBBY_H
