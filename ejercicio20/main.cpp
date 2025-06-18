#include <QCoreApplication>
#include <iostream>
#include <vector>
#include "instrumento.h"
#include "guitarra.h"
#include "bateria.h"
#include "teclado.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    std::vector<Instrumento*> instrumentos;

    instrumentos.push_back(new Guitarra);
    instrumentos.push_back(new Bateria);
    instrumentos.push_back(new Teclado);
    instrumentos.push_back(new Guitarra(12));
    instrumentos.push_back(new Teclado(88, 110));

    for (Instrumento* i : instrumentos) {
        std::cout << i->verlo().toStdString() << std::endl;
        i->sonar();
    }

    for (Instrumento* i : instrumentos)
        delete i;

    return a.exec();
}
