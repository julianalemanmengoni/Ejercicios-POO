QT += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += c++11
TARGET = ejercicio19

SOURCES += main.cpp \
           ventana.cpp \
           caja.cpp \
           admin.cpp

HEADERS += ventana.h \
           caja.h \
           admin.h
