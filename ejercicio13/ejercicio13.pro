QT += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TEMPLATE = app
TARGET = ejercicio13

SOURCES += main.cpp \
           login.cpp \
           ventana.cpp

HEADERS += login.h \
           ventana.h

FORMS += login.ui
