#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <QString>

class Instrumento {
public:
    Instrumento() : marca("Yamaha") {}
    virtual ~Instrumento() {}
    virtual void sonar() = 0;
    virtual QString verlo() const { return "Marca: " + marca; }

protected:
    QString marca;
};

#endif // INSTRUMENTO_H
