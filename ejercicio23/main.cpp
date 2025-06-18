#include <QCoreApplication>
#include <QDebug>
#include "cuentabancaria.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    CuentaBancaria cuenta1(1000);
    CuentaBancaria cuenta2(800);

    cuenta1.depositar(200);
    cuenta2.depositar(100);

    cuenta1.mostrar();
    cuenta2.mostrar();

    if (compararSaldo(cuenta1, cuenta2)) {
        qDebug() << "La cuenta 1 tiene mayor saldo.";
    } else {
        qDebug() << "La cuenta 2 tiene mayor o igual saldo.";
    }

    return 0;
}
