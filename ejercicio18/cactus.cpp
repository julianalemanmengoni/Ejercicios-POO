#include "cactus.h"

Cactus::Cactus(int x, int y) : x(x), y(y), ancho(20), alto(40) {}

void Cactus::mover(int velocidad) {
    x -= velocidad;
}

void Cactus::dibujar(QPainter &p) {
    p.setBrush(Qt::green);
    p.drawRect(x, y, ancho, alto);
}

QRect Cactus::rectangulo() {
    return QRect(x, y, ancho, alto);
}

bool Cactus::fueraPantalla() {
    return x + ancho < 0;
}
