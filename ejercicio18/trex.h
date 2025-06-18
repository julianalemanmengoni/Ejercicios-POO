#ifndef TREX_H
#define TREX_H

#include <QPainter>

class TRex {
public:
    TRex(int x, int y, QWidget *parent);
    void dibujar(QPainter &p);
    void saltar();
    void agacharse();
    void frenar();
    void adelantar();
    void actualizar();
    QRect rectangulo();
    void resetear();

private:
    int x, y, ancho, alto;
    int velocidadY;
    bool enElAire;
};

#endif // TREX_H
