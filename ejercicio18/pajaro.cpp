#include "pajaro.h"

Pajaro::Pajaro(int x, int y) : x(x), y(y), ancho(30), alto(20) {}

void Pajaro::mover(int velocidad) {
    x -= velocidad;
}

void Pajaro::dibujar(QPainter &p) {
    p.setBrush(Qt::red);
    p.drawRect(x, y, ancho, alto);
}

QRect Pajaro::rectangulo() {
    return QRect(x, y, ancho, alto);
}

bool Pajaro::fueraPantalla() {
    return x + ancho < 0;
}
