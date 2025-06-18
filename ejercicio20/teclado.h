#ifndef TECLADO_H
#define TECLADO_H

#include "instrumento.h"
#include "electrico.h"

class Teclado : public Instrumento, public Electrico {
public:
    Teclado(int teclas = 61, int volt = 220) : teclas(teclas), Electrico(volt) {}
    void sonar() override;
    int getTeclas() const { return teclas; }
    void setTeclas(int t) { teclas = t; }

private:
    int teclas;
};

#endif // TECLADO_H
