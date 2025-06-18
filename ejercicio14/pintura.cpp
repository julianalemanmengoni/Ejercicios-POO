#include "pintura.h"
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>

Pintura::Pintura(QWidget *parent)
    : QWidget(parent), color(Qt::black), grosor(5), dibujando(false) {
    setWindowTitle("Pintura");
    resize(800, 600);
    lienzo = QPixmap(size());
    lienzo.fill(Qt::white);
}

void Pintura::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dibujando = true;
        ultimoPunto = event->pos();
    }
}

void Pintura::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton) && dibujando) {
        QPainter painter(&lienzo);
        painter.setPen(QPen(color, grosor, Qt::SolidLine, Qt::RoundCap));
        painter.drawLine(ultimoPunto, event->pos());
        ultimoPunto = event->pos();
        update();
    }
}

void Pintura::wheelEvent(QWheelEvent *event) {
    grosor += event->angleDelta().y() > 0 ? 1 : -1;
    if (grosor < 1) grosor = 1;
}

void Pintura::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_R:
            color = Qt::red;
            break;
        case Qt::Key_G:
            color = Qt::green;
            break;
        case Qt::Key_B:
            color = Qt::blue;
            break;
        case Qt::Key_Escape:
            lienzo.fill(Qt::white);
            update();
            break;
    }
}

void Pintura::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, lienzo);
}
