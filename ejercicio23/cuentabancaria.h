#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H

class CuentaBancaria {
private:
    int saldo;

public:
    CuentaBancaria(int inicial) : saldo(inicial) {}

    void depositar(int cantidad) {
        saldo += cantidad;
    }

    void mostrar() const {
        qDebug("Saldo: %d", saldo);
    }

    friend bool compararSaldo(CuentaBancaria c1, CuentaBancaria c2);
};

bool compararSaldo(CuentaBancaria c1, CuentaBancaria c2) {
    return c1.saldo > c2.saldo;
}

#endif // CUENTABANCARIA_H
