#include "ventana.h"
#include <QVBoxLayout>
#include <QLabel>

Ventana::Ventana(const QString &nombre, const QString &ultimoIngreso, QWidget *parent)
    : QWidget(parent) {
    setWindowTitle("Bienvenido");
    resize(400, 200);

    QLabel *lblNombre = new QLabel(nombre);
    lblNombre->setStyleSheet("font-size: 24px; font-weight: bold;");
    QLabel *lblIngreso = new QLabel("Último ingreso: " + ultimoIngreso);
    lblIngreso->setStyleSheet("font-size: 14px; color: gray;");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lblNombre);
    layout->addWidget(lblIngreso);
    setLayout(layout);
}
