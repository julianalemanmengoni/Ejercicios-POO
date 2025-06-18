#ifndef PERSONA_H
#define PERSONA_H

#include <QString>
#include <QDebug>

class Persona {
public:
    Persona(QString nombre) : nombre(nombre) {
        ++contador;
    }

    void mostrar() const {
        qDebug() << "Nombre:" << nombre;
    }

    static int totalPersonas() {
        return contador;
    }

private:
    QString nombre;
    static int contador;
};

#endif // PERSONA_H
