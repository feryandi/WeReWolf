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
    client.cpp

HEADERS  += login.h \
    client.h

FORMS    += login.ui
