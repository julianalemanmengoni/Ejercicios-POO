#include "formulario.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

Formulario::Formulario(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Formulario");

    QLabel *lblLegajo = new QLabel("Legajo:");
    QLabel *lblNombre = new QLabel("Nombre:");
    QLabel *lblApellido = new QLabel("Apellido:");
    QLineEdit *editLegajo = new QLineEdit;
    QLineEdit *editNombre = new QLineEdit;
    QLineEdit *editApellido = new QLineEdit;
    QPushButton *boton = new QPushButton("Aceptar");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lblLegajo, 0, 0);
    layout->addWidget(editLegajo, 0, 1);
    layout->addWidget(lblNombre, 1, 0);
    layout->addWidget(editNombre, 1, 1);
    layout->addWidget(lblApellido, 2, 0);
    layout->addWidget(editApellido, 2, 1);
    layout->addWidget(boton, 3, 0, 1, 2);

    setLayout(layout);
}
