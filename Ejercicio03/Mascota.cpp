#include "Mascota.h"

Mascota::Mascota(std::string nombre, int edad, float peso) {
    this->nombre = nombre;
    this->edad = edad;
    this->peso = peso;
}

std::string Mascota::getNombre() const {
    return nombre;
}

int Mascota::getEdad() const {
    return edad;
}

float Mascota::getPeso() const {
    return peso;
}
