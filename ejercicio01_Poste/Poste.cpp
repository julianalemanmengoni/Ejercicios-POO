#include "Poste.h"
#include <iostream>

Poste::Poste(int altura, float diametro) {
    this->altura = altura;
    this->diametro = diametro;
}

int Poste::getAltura() const {
    return altura;
}

float Poste::getDiametro() const {
    return diametro;
}

void Poste::mostrar() const {
    std::cout << "Altura: " << altura << " m - Diametro: " << diametro << " cm" << std::endl;
}
