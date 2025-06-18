#ifndef CACTUS_H
#define CACTUS_H

#include <QPainter>

class Cactus {
public:
    Cactus(int x, int y);
    void mover(int velocidad);
    void dibujar(QPainter &p);
    QRect rectangulo();
    bool fueraPantalla();

private:
    int x, y, ancho, alto;
};

#endif // CACTUS_H
