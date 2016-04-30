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
    QLabel *labelTitle;
    QFrame *line;
    QPushButton *buttonPlay;
    QLineEdit *textServerPort;
    QLabel *labelNickname;
    QLabel *labelServerIP;
    QLineEdit *textServerIP;
    QLabel *labelServerPort;
    QLineEdit *textNickname;
    QLabel *label;
    QLineEdit *textClientPort;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(540, 200);
        centralWidget = new QWidget(login);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        labelTitle = new QLabel(centralWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setGeometry(QRect(20, 10, 501, 31));
        QFont font;
        font.setFamily(QStringLiteral("Lato"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignCenter);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(40, 40, 461, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        buttonPlay = new QPushButton(centralWidget);
        buttonPlay->setObjectName(QStringLiteral("buttonPlay"));
        buttonPlay->setGeometry(QRect(20, 150, 501, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Lato Semibold"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        buttonPlay->setFont(font1);
        buttonPlay->setFocusPolicy(Qt::TabFocus);
        buttonPlay->setCheckable(false);
        buttonPlay->setAutoDefault(false);
        buttonPlay->setFlat(false);
        textServerPort = new QLineEdit(centralWidget);
        textServerPort->setObjectName(QStringLiteral("textServerPort"));
        textServerPort->setGeometry(QRect(120, 110, 141, 24));
        QFont font2;
        font2.setFamily(QStringLiteral("Lato"));
        font2.setPointSize(11);
        textServerPort->setFont(font2);
        textServerPort->setFocusPolicy(Qt::StrongFocus);
        textServerPort->setCursorPosition(5);
        labelNickname = new QLabel(centralWidget);
        labelNickname->setObjectName(QStringLiteral("labelNickname"));
        labelNickname->setGeometry(QRect(280, 70, 81, 20));
        labelNickname->setFont(font2);
        labelServerIP = new QLabel(centralWidget);
        labelServerIP->setObjectName(QStringLiteral("labelServerIP"));
        labelServerIP->setGeometry(QRect(20, 70, 91, 20));
        labelServerIP->setFont(font2);
        textServerIP = new QLineEdit(centralWidget);
        textServerIP->setObjectName(QStringLiteral("textServerIP"));
        textServerIP->setGeometry(QRect(120, 70, 141, 24));
        textServerIP->setFont(font2);
        textServerIP->setFocusPolicy(Qt::StrongFocus);
        textServerIP->setCursorPosition(1);
        labelServerPort = new QLabel(centralWidget);
        labelServerPort->setObjectName(QStringLiteral("labelServerPort"));
        labelServerPort->setGeometry(QRect(20, 110, 91, 20));
        labelServerPort->setFont(font2);
        textNickname = new QLineEdit(centralWidget);
        textNickname->setObjectName(QStringLiteral("textNickname"));
        textNickname->setGeometry(QRect(380, 70, 141, 24));
        textNickname->setFont(font2);
        textNickname->setFocusPolicy(Qt::StrongFocus);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(280, 110, 81, 20));
        label->setFont(font2);
        textClientPort = new QLineEdit(centralWidget);
        textClientPort->setObjectName(QStringLiteral("textClientPort"));
        textClientPort->setGeometry(QRect(380, 110, 141, 24));
        textClientPort->setFont(font2);
        textClientPort->setFocusPolicy(Qt::StrongFocus);
        textClientPort->setLayoutDirection(Qt::LeftToRight);
        login->setCentralWidget(centralWidget);

        retranslateUi(login);

        buttonPlay->setDefault(false);


        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QApplication::translate("login", "login", 0));
        labelTitle->setText(QApplication::translate("login", "WeReWolf", 0));
        buttonPlay->setText(QApplication::translate("login", "Play!", 0));
        textServerPort->setText(QApplication::translate("login", "55555", 0));
        textServerPort->setPlaceholderText(QApplication::translate("login", "55555", 0));
        labelNickname->setText(QApplication::translate("login", "Nickname", 0));
        labelServerIP->setText(QApplication::translate("login", "Server Host", 0));
        textServerIP->setText(QApplication::translate("login", "127.0.0.1", 0));
        textServerIP->setPlaceholderText(QApplication::translate("login", "localhost", 0));
        labelServerPort->setText(QApplication::translate("login", "Server Port", 0));
        textNickname->setText(QString());
        textNickname->setPlaceholderText(QApplication::translate("login", "user_name", 0));
        label->setText(QApplication::translate("login", "Listen Port", 0));
        textClientPort->setText(QApplication::translate("login", "9999", 0));
        textClientPort->setPlaceholderText(QApplication::translate("login", "9999", 0));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
