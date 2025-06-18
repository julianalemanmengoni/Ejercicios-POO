#ifndef SENSOR_H
#define SENSOR_H

#include <cstdlib>

class Sensor {
public:
    Sensor() {
        valorActual = std::rand() % 1024;
    }

    int getValorBruto() const { return valorActual; }

    int getValorBrutoOffline() const;

    inline double getValorNormalizado() const {
        return valorActual / 1023.0;
    }

    double getValorNormalizadoOffline() const;

private:
    int valorActual;
};

#endif // SENSOR_H
