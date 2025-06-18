#include "login.h"
#include <QGridLayout>
#include <QLabel>
#include <QKeyEvent>

Login::Login(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Login");

    QLabel *lblUsuario = new QLabel("Usuario:");
    QLabel *lblClave = new QLabel("Clave:");
    usuario = new QLineEdit;
    clave = new QLineEdit;
    clave->setEchoMode(QLineEdit::Password);

    boton = new QPushButton("Ingresar");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lblUsuario, 0, 0);
    layout->addWidget(usuario, 0, 1);
    layout->addWidget(lblClave, 1, 0);
    layout->addWidget(clave, 1, 1);
    layout->addWidget(boton, 2, 0, 1, 2);

    setLayout(layout);

    connect(boton, &QPushButton::clicked, this, &Login::verificarCredenciales);
    connect(clave, &QLineEdit::returnPressed, boton, &QPushButton::click);
}

void Login::verificarCredenciales() {
    if (usuario->text() == "admin" && clave->text() == "1111") {
        Formulario *form = new Formulario;
        form->show();
        this->close();
    } else {
        clave->clear();
    }
}
