#include "boton.h"
#include <QPainter>
#include <QMouseEvent>

Boton::Boton(QWidget *parent) : QWidget(parent), color(Qt::gray) {
    setMinimumHeight(40);
}

void Boton::colorear(Boton::Color c) {
    switch (c) {
        case Azul: color = Qt::blue; break;
        case Verde: color = Qt::green; break;
        case Magenta: color = Qt::magenta; break;
    }
    update();
}

void Boton::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.fillRect(rect(), color);
}

void Boton::mousePressEvent(QMouseEvent *) {
    emit signal_clic();
}
