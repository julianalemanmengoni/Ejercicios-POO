#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Poste.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    std::vector<Poste> postes;
    postes.emplace_back(12, 15.5);
    postes.emplace_back(8, 10.0);
    postes.emplace_back(15, 20.2);
    postes.emplace_back(10, 12.0);
    postes.emplace_back(6, 8.5);

    std::cout << "Postes antes de ordenar:\n";
    for (const Poste &p : postes)
        p.mostrar();

    std::sort(postes.begin(), postes.end(), [](const Poste &a, const Poste &b) {
        return a.getAltura() < b.getAltura();
    });

    std::cout << "\nPostes después de ordenar por altura:\n";
    for (const Poste &p : postes)
        p.mostrar();

    return a.exec();
}
