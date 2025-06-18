#include "trex.h"

TRex::TRex(int x, int y, QWidget *)
    : x(x), y(y), ancho(40), alto(40), velocidadY(0), enElAire(false) {}

void TRex::dibujar(QPainter &p) {
    p.setBrush(Qt::darkGray);
    p.drawRect(x, y, ancho, alto);
}

void TRex::saltar() {
    if (!enElAire) {
        velocidadY = -15;
        enElAire = true;
    }
}

void TRex::agacharse() {
    alto = 20;
}

void TRex::frenar() {
    x -= 5;
}

void TRex::adelantar() {
    x += 5;
}

void TRex::actualizar() {
    if (enElAire || y < 200) {
        y += velocidadY;
        velocidadY += 1;
        if (y >= 200) {
            y = 200;
            enElAire = false;
            alto = 40;
        }
    }
}

QRect TRex::rectangulo() {
    return QRect(x, y, ancho, alto);
}

void TRex::resetear() {
    x = 50;
    y = 200;
    velocidadY = 0;
    enElAire = false;
    alto = 40;
}
