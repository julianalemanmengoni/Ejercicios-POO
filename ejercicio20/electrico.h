#ifndef ELECTRICO_H
#define ELECTRICO_H

class Electrico {
public:
    Electrico(int voltaje = 220) : voltaje(voltaje) {}
    virtual ~Electrico() {
        std::cout << "Desenchufado" << std::endl;
    }
    int getVoltaje() const { return voltaje; }
    void setVoltaje(int v) { voltaje = v; }

private:
    int voltaje;
};

#endif // ELECTRICO_H
