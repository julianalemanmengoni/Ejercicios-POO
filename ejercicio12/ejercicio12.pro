QT += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TEMPLATE = app
TARGET = ejercicio12

SOURCES += main.cpp \
           login.cpp

HEADERS += login.h \
           ventanasecundaria.h

FORMS += login.ui
