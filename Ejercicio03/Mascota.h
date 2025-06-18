#ifndef MASCOTA_H
#define MASCOTA_H

#include <string>

class Mascota {
private:
    std::string nombre;
    int edad;
    float peso;
    char descripcion[1024]; // Simula un campo grande

public:
    Mascota(std::string nombre, int edad, float peso);
    std::string getNombre() const;
    int getEdad() const;
    float getPeso() const;
};

#endif // MASCOTA_H
