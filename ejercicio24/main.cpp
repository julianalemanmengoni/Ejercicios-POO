#include <QCoreApplication>
#include "persona.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Persona p1("Ana");
    Persona p2("Luis");
    Persona p3("Carlos");

    p1.mostrar();
    p2.mostrar();
    p3.mostrar();

    qDebug("Total de personas creadas: %d", Persona::totalPersonas());

    return 0;
}
