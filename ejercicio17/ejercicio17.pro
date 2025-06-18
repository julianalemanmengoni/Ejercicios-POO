QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TEMPLATE = app
TARGET = ejercicio17

SOURCES += main.cpp \
           boton.cpp \
           ventana.cpp

HEADERS += boton.h \
           ventana.h

FORMS += ventana.ui
