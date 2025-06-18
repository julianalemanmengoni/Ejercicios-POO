#include "admin.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

AdminDB* AdminDB::instancia() {
    static AdminDB instancia;
    return &instancia;
}

AdminDB::AdminDB() {}

void AdminDB::conectar() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("medicamentos.db");
    db.open();

    QSqlQuery q;
    q.exec("CREATE TABLE IF NOT EXISTS cajas_medicamentos ("
           "id INTEGER PRIMARY KEY AUTOINCREMENT, "
           "dosis_totales REAL NOT NULL)");
}

bool AdminDB::insertarCaja(float dosis) {
    if (obtenerTotalDosis() + dosis > 1000.0) return false;

    QSqlQuery q;
    q.prepare("INSERT INTO cajas_medicamentos (dosis_totales) VALUES (?)");
    q.addBindValue(dosis);
    return q.exec();
}

QList<CajaMedicamento> AdminDB::obtenerTodas() {
    QList<CajaMedicamento> lista;
    QSqlQuery q("SELECT id, dosis_totales FROM cajas_medicamentos");

    while (q.next()) {
        lista.append(CajaMedicamento(q.value(0).toInt(), q.value(1).toFloat()));
    }
    return lista;
}

float AdminDB::obtenerTotalDosis() {
    QSqlQuery q("SELECT SUM(dosis_totales) FROM cajas_medicamentos");
    if (q.next()) return q.value(0).toFloat();
    return 0.0;
}
