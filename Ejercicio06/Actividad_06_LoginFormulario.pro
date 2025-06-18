QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TEMPLATE = app
TARGET = Actividad_06_LoginFormulario

SOURCES += main.cpp \
           login.cpp \
           formulario.cpp

HEADERS += login.h \
           formulario.h
