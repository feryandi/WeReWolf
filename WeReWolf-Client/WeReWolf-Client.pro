#-------------------------------------------------
#
# Project created by QtCreator 2016-04-25T16:01:12
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WeReWolf-Client
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    handler_server.cpp \
    handler_client.cpp \
    game.cpp \
    interface.cpp \
    gameover.cpp

HEADERS  += login.h \
    handler_server.h \
    handler_client.h \
    game.h \
    interface.h \
    gameover.h

FORMS    += login.ui \
    game.ui \
    gameover.ui
