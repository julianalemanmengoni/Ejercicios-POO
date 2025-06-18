#include "ventana.h"
#include "ui_ventana.h"
#include "boton.h"
#include <QPainter>
#include <QImage>

Ventana::Ventana(QWidget *parent)
    : QWidget(parent), ui(new Ui::Ventana) {
    ui->setupUi(this);

    // Colorear los botones promocionados
    findChild<Boton*>("boton1")->colorear(Boton::Magenta);
    findChild<Boton*>("boton2")->colorear(Boton::Yellow);
    findChild<Boton*>("boton3")->colorear(Boton::Blue);
    findChild<Boton*>("boton4")->colorear(Boton::Green);
    findChild<Boton*>("boton5")->colorear(Boton::Cyan);
}

Ventana::~Ventana() {
    delete ui;
}

void Ventana::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QImage fondo(":/fondo.png");
    painter.drawImage(rect(), fondo);
}
