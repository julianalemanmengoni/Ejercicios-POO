QT += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TEMPLATE = app
TARGET = ejercicio16

SOURCES += main.cpp \
           login.cpp

HEADERS += login.h

FORMS += login.ui
