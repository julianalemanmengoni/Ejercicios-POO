#ifndef ADMIN_H
#define ADMIN_H

#include <QList>
#include <QSqlDatabase>
#include "caja.h"

class AdminDB {
public:
    static AdminDB* instancia();
    void conectar();
    bool insertarCaja(float dosis);
    QList<CajaMedicamento> obtenerTodas();
    float obtenerTotalDosis();

private:
    AdminDB();
    QSqlDatabase db;
};

#endif // ADMIN_H
