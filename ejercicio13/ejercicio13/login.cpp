#include "login.h"
#include "ui_login.h"
#include "ventana.h"
#include <QMessageBox>
#include <QNetworkRequest>
#include <QPalette>
#include <QBrush>

Login::Login(QWidget *parent)
    : QWidget(parent), ui(new Ui::Login) {
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &Login::fondoDescargado);

    QUrl url("https://picsum.photos/800/600");
    manager->get(QNetworkRequest(url));
}

Login::~Login() {
    delete ui;
}

void Login::fondoDescargado(QNetworkReply *reply) {
    QByteArray data = reply->readAll();
    fondo.loadFromData(data);
    fondo = fondo.scaled(this->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(fondo));
    this->setPalette(palette);
    this->setAutoFillBackground(true);
}

void Login::on_loginButton_clicked() {
    QString usuario = ui->userLineEdit->text();
    QString clave = ui->passLineEdit->text();

    if (usuario == "admin" && clave == "1234") {
        Ventana *v = new Ventana;
        v->showFullScreen();
        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Usuario o clave incorrectos");
    }
}
