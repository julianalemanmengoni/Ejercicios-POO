#include "ventana.h"
#include "admin.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDebug>

Ventana::Ventana(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Gestión de Medicamentos");
    resize(400, 300);

    spinDosis = new QDoubleSpinBox;
    spinDosis->setRange(0.1, 1000.0);
    spinDosis->setDecimals(1);

    btnAgregar = new QPushButton("Agregar");
    btnSumar = new QPushButton("Sumar");
    btnComparar = new QPushButton("Comparar");

    lista = new QListWidget;

    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *top = new QHBoxLayout;
    top->addWidget(spinDosis);
    top->addWidget(btnAgregar);
    layout->addLayout(top);
    layout->addWidget(lista);

    QHBoxLayout *bottom = new QHBoxLayout;
    bottom->addWidget(btnSumar);
    bottom->addWidget(btnComparar);
    layout->addLayout(bottom);

    setLayout(layout);

    connect(btnAgregar, SIGNAL(clicked()), this, SLOT(agregarCaja()));
    connect(btnSumar, SIGNAL(clicked()), this, SLOT(sumarCajas()));
    connect(btnComparar, SIGNAL(clicked()), this, SLOT(compararCajas()));

    AdminDB::instancia()->conectar();
    cargarLista();
}

void Ventana::agregarCaja() {
    float dosis = spinDosis->value();
    if (!AdminDB::instancia()->insertarCaja(dosis)) {
        QMessageBox::warning(this, "Error", "Se superan las 1000 dosis.");
        return;
    }
    cargarLista();
}

void Ventana::sumarCajas() {
    QList<QListWidgetItem*> items = lista->selectedItems();
    if (items.size() != 2) return;

    CajaMedicamento c1 = AdminDB::instancia()->obtenerTodas().at(lista->row(items[0]));
    CajaMedicamento c2 = AdminDB::instancia()->obtenerTodas().at(lista->row(items[1]));

    CajaMedicamento suma = c1 + c2;
    if (!AdminDB::instancia()->insertarCaja(suma.getDosis())) {
        QMessageBox::warning(this, "Error", "No se puede sumar. Se superan las 1000 dosis.");
        return;
    }
    cargarLista();
}

void Ventana::compararCajas() {
    QList<QListWidgetItem*> items = lista->selectedItems();
    if (items.size() != 2) return;

    CajaMedicamento c1 = AdminDB::instancia()->obtenerTodas().at(lista->row(items[0]));
    CajaMedicamento c2 = AdminDB::instancia()->obtenerTodas().at(lista->row(items[1]));

    if (c1 == c2)
        qDebug() << "Las cajas son iguales en dosis.";
    else
        qDebug() << "Las cajas son diferentes en dosis.";
}

void Ventana::cargarLista() {
    lista->clear();
    QList<CajaMedicamento> cajas = AdminDB::instancia()->obtenerTodas();
    foreach (CajaMedicamento c, cajas)
        lista->addItem(c.toString());
}
