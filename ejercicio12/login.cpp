#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>
#include "ventanasecundaria.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login) {
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &Login::recibirClima);
    QUrl url("https://api.open-meteo.com/v1/forecast?latitude=-31.41&longitude=-64.18&current_weather=true");
    manager->get(QNetworkRequest(url));
}

Login::~Login() {
    delete ui;
}

void Login::on_loginButton_clicked() {
    QString usuario = ui->userLineEdit->text();
    QString clave = ui->passLineEdit->text();

    if (usuario == "admin" && clave == "1234") {
        VentanaSecundaria *v = new VentanaSecundaria;
        v->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Usuario o clave incorrectos");
    }
}

void Login::recibirClima(QNetworkReply *reply) {
    QByteArray data = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isObject()) {
        QJsonObject obj = doc.object();
        QJsonObject clima = obj["current_weather"].toObject();
        double temperatura = clima["temperature"].toDouble();
        ui->labelTemperatura->setText("Temperatura actual: " + QString::number(temperatura) + " °C");
    }
}
