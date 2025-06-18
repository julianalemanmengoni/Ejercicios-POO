#ifndef CAJA_H
#define CAJA_H

#include <QString>

class CajaMedicamento {
public:
    CajaMedicamento(float dosis);
    CajaMedicamento(int id, float dosis);

    int getId() const;
    float getDosis() const;
    QString toString() const;

    CajaMedicamento operator+(const CajaMedicamento &otra) const;
    bool operator==(const CajaMedicamento &otra) const;

private:
    int id;
    float dosisTotales;
};

#endif // CAJA_H
