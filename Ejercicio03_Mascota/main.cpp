#include <QCoreApplication>
#include <iostream>
#include <vector>
#include "Mascota.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    std::vector<Mascota*> mascotas;
    const size_t objetivoBytes = 200 * 1024 * 1024; // 200 MB
    size_t memoriaUsada = 0;
    size_t tamanoEstimado = sizeof(Mascota);

    while (memoriaUsada + tamanoEstimado < objetivoBytes) {
        mascotas.push_back(new Mascota("Firulais", 3, 12.5));
        memoriaUsada += tamanoEstimado;
    }

    std::cout << "Se crearon " << mascotas.size() << " objetos de Mascota para alcanzar aproximadamente 200MB de RAM." << std::endl;

    // Liberar memoria
    for (Mascota* m : mascotas)
        delete m;

    return a.exec();
}
