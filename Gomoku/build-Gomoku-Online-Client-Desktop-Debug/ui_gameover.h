/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_gameover
{
public:
    QLabel *labelGameover;
    QPushButton *buttonOK;
    QLabel *labelWinner;

    void setupUi(QDialog *gameover)
    {
        if (gameover->objectName().isEmpty())
            gameover->setObjectName(QStringLiteral("gameover"));
        gameover->resize(290, 177);
        QIcon icon;
        icon.addFile(QStringLiteral("../../res/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        gameover->setWindowIcon(icon);
        labelGameover = new QLabel(gameover);
        labelGameover->setObjectName(QStringLiteral("labelGameover"));
        labelGameover->setGeometry(QRect(20, 20, 251, 31));
        QFont font;
        font.setFamily(QStringLiteral("Lato"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        labelGameover->setFont(font);
        labelGameover->setAlignment(Qt::AlignCenter);
        buttonOK = new QPushButton(gameover);
        buttonOK->setObjectName(QStringLiteral("buttonOK"));
        buttonOK->setGeometry(QRect(60, 120, 161, 33));
        QFont font1;
        font1.setFamily(QStringLiteral("Lato Semibold"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        buttonOK->setFont(font1);
        labelWinner = new QLabel(gameover);
        labelWinner->setObjectName(QStringLiteral("labelWinner"));
        labelWinner->setGeometry(QRect(50, 60, 191, 20));
        QFont font2;
        font2.setFamily(QStringLiteral("Lato"));
        font2.setPointSize(11);
        labelWinner->setFont(font2);
        labelWinner->setAlignment(Qt::AlignCenter);

        retranslateUi(gameover);

        QMetaObject::connectSlotsByName(gameover);
    } // setupUi

    void retranslateUi(QDialog *gameover)
    {
        gameover->setWindowTitle(QApplication::translate("gameover", "Gameover", 0));
        labelGameover->setText(QApplication::translate("gameover", "Congratulation :)", 0));
        buttonOK->setText(QApplication::translate("gameover", "OK", 0));
        labelWinner->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gameover: public Ui_gameover {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
