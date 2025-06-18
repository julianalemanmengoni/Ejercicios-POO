QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TEMPLATE = app
TARGET = ejercicio18

SOURCES += main.cpp \
           game.cpp \
           trex.cpp \
           pajaro.cpp \
           cactus.cpp

HEADERS += game.h \
           trex.h \
           pajaro.h \
           cactus.h
