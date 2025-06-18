#ifndef BATERIA_H
#define BATERIA_H

#include "instrumento.h"

class Bateria : public Instrumento {
public:
    Bateria(int tambores = 5) : tambores(tambores) {}
    void sonar() override;
    int getTambores() const { return tambores; }
    void setTambores(int t) { tambores = t; }

private:
    int tambores;
};

#endif // BATERIA_H
