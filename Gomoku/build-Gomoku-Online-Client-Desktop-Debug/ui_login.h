/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralWidget;
    QPushButton *buttonPlay;
    QLineEdit *textServerPort;
    QLabel *labelNickname;
    QLabel *labelServerIP;
    QLabel *labelServerPort;
    QLineEdit *textServerIP;
    QLineEdit *textNickname;
    QLabel *labelTitle;
    QFrame *line;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(320, 240);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(login->sizePolicy().hasHeightForWidth());
        login->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral("../../res/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        login->setWindowIcon(icon);
        centralWidget = new QWidget(login);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        buttonPlay = new QPushButton(centralWidget);
        buttonPlay->setObjectName(QStringLiteral("buttonPlay"));
        buttonPlay->setGeometry(QRect(20, 190, 281, 26));
        QFont font;
        font.setFamily(QStringLiteral("Lato Semibold"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        buttonPlay->setFont(font);
        buttonPlay->setFocusPolicy(Qt::TabFocus);
        buttonPlay->setCheckable(false);
        buttonPlay->setAutoDefault(false);
        buttonPlay->setFlat(false);
        textServerPort = new QLineEdit(centralWidget);
        textServerPort->setObjectName(QStringLiteral("textServerPort"));
        textServerPort->setGeometry(QRect(130, 150, 167, 24));
        QFont font1;
        font1.setFamily(QStringLiteral("Lato"));
        font1.setPointSize(11);
        textServerPort->setFont(font1);
        textServerPort->setFocusPolicy(Qt::StrongFocus);
        textServerPort->setCursorPosition(2);
        labelNickname = new QLabel(centralWidget);
        labelNickname->setObjectName(QStringLiteral("labelNickname"));
        labelNickname->setGeometry(QRect(20, 70, 81, 20));
        labelNickname->setFont(font1);
        labelServerIP = new QLabel(centralWidget);
        labelServerIP->setObjectName(QStringLiteral("labelServerIP"));
        labelServerIP->setGeometry(QRect(20, 110, 91, 20));
        labelServerIP->setFont(font1);
        labelServerPort = new QLabel(centralWidget);
        labelServerPort->setObjectName(QStringLiteral("labelServerPort"));
        labelServerPort->setGeometry(QRect(20, 150, 91, 20));
        labelServerPort->setFont(font1);
        textServerIP = new QLineEdit(centralWidget);
        textServerIP->setObjectName(QStringLiteral("textServerIP"));
        textServerIP->setGeometry(QRect(130, 110, 167, 24));
        textServerIP->setFont(font1);
        textServerIP->setFocusPolicy(Qt::StrongFocus);
        textServerIP->setCursorPosition(1);
        textNickname = new QLineEdit(centralWidget);
        textNickname->setObjectName(QStringLiteral("textNickname"));
        textNickname->setGeometry(QRect(130, 70, 167, 24));
        textNickname->setFont(font1);
        textNickname->setFocusPolicy(Qt::StrongFocus);
        labelTitle = new QLabel(centralWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setGeometry(QRect(40, -10, 241, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Lato"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        labelTitle->setFont(font2);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 50, 281, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        login->setCentralWidget(centralWidget);

        retranslateUi(login);

        buttonPlay->setDefault(false);


        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Login", 0));
        buttonPlay->setText(QApplication::translate("login", "Play!", 0));
        textServerPort->setText(QApplication::translate("login", "55555", 0));
        textServerPort->setPlaceholderText(QApplication::translate("login", "55555", 0));
        labelNickname->setText(QApplication::translate("login", "Nickname", 0));
        labelServerIP->setText(QApplication::translate("login", "Server Host", 0));
        labelServerPort->setText(QApplication::translate("login", "Server Port", 0));
        textServerIP->setText(QApplication::translate("login", "127.0.0.1", 0));
        textServerIP->setPlaceholderText(QApplication::translate("login", "localhost", 0));
        textNickname->setPlaceholderText(QApplication::translate("login", "user_name", 0));
        labelTitle->setText(QApplication::translate("login", "GOMOKU ONLINE", 0));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
