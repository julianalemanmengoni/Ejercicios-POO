#ifndef GUITARRA_H
#define GUITARRA_H

#include "instrumento.h"

class Guitarra : public Instrumento {
public:
    Guitarra(int cuerdas = 6) : cuerdas(cuerdas) {}
    void sonar() override;
    int getCuerdas() const { return cuerdas; }
    void setCuerdas(int c) { cuerdas = c; }

private:
    int cuerdas;
};

#endif // GUITARRA_H
