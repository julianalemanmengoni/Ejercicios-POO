#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Función auxiliar para eliminar espacios de una string
std::string quitarEspacios(const std::string& str) {
    std::string sinEspacios;
    for (char c : str) {
        if (c != ' ')
            sinEspacios += c;
    }
    return sinEspacios;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    std::vector<std::string> expresiones = {
        "pan comido",
        "tirar la toalla",
        "estar en las nubes",
        "llover a cántaros",
        "hacer la vista gorda"
    };

    std::cout << "Expresiones antes de ordenar:\n";
    for (const std::string& e : expresiones)
        std::cout << e << std::endl;

    std::sort(expresiones.begin(), expresiones.end(), [](const std::string& a, const std::string& b) {
        return quitarEspacios(a) < quitarEspacios(b);
    });

    std::cout << "\nExpresiones después de ordenar alfabéticamente (sin considerar espacios):\n";
    for (const std::string& e : expresiones)
        std::cout << e << std::endl;

    return a.exec();
}
