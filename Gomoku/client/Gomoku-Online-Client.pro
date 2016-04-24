#-------------------------------------------------
#
# Project created by QtCreator 2015-12-02T21:20:42
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gomoku-Online-Client
TEMPLATE = app

SOURCES += main.cpp\
        login.cpp \
    lobby.cpp \
    game.cpp \
    client.cpp \
    interface.cpp \
    gameover.cpp

HEADERS  += login.h \
    lobby.h \
    game.h \
    client.h \
    interface.h \
    gameover.h

FORMS    += login.ui \
    lobby.ui \
    game.ui \
    gameover.ui
