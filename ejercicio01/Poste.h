#ifndef POSTE_H
#define POSTE_H

class Poste {
private:
    int altura;       // en metros
    float diametro;   // en cm

public:
    Poste(int altura, float diametro);
    int getAltura() const;
    float getDiametro() const;
    void mostrar() const;
};

#endif // POSTE_H
