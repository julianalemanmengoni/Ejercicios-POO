QT -= gui
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app
TARGET = ejercicio20

SOURCES += main.cpp \
           guitarra.cpp \
           bateria.cpp \
           teclado.cpp

HEADERS += instrumento.h \
           guitarra.h \
           bateria.h \
           electrico.h \
           teclado.h
