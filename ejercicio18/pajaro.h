#ifndef PAJARO_H
#define PAJARO_H

#include <QPainter>

class Pajaro {
public:
    Pajaro(int x, int y);
    void mover(int velocidad);
    void dibujar(QPainter &p);
    QRect rectangulo();
    bool fueraPantalla();

private:
    int x, y, ancho, alto;
};

#endif // PAJARO_H
