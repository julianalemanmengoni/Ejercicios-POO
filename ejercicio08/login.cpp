#include "login.h"
#include <QVBoxLayout>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkRequest>
#include <QMessageBox>

Login::Login(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Login JWT");
    resize(300, 180);

    usuarioEdit = new QLineEdit;
    claveEdit = new QLineEdit;
    claveEdit->setEchoMode(QLineEdit::Password);
    botonLogin = new QPushButton("Iniciar sesión");
    botonProteger = new QPushButton("Proteger solicitud");
    botonProteger->setEnabled(false);
    estadoLabel = new QLabel("Esperando...");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(new QLabel("Usuario:"));
    layout->addWidget(usuarioEdit);
    layout->addWidget(new QLabel("Clave:"));
    layout->addWidget(claveEdit);
    layout->addWidget(botonLogin);
    layout->addWidget(botonProteger);
    layout->addWidget(estadoLabel);
    setLayout(layout);

    manager = new QNetworkAccessManager(this);
    connect(botonLogin, SIGNAL(clicked()), this, SLOT(enviarLogin()));
    connect(botonProteger, SIGNAL(clicked()), this, SLOT(solicitarProtegido()));
}

void Login::enviarLogin() {
    QUrl url("http://localhost:8000/auth/login");  // Cambiar si es necesario
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["usuario"] = usuarioEdit->text();
    json["clave"] = claveEdit->text();

    QNetworkReply *reply = manager->post(request, QJsonDocument(json).toJson());
    connect(reply, SIGNAL(finished()), this, SLOT(procesarRespuesta()));
}

void Login::procesarRespuesta() {
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) return;

    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        token = doc.object()["access_token"].toString();

        if (!token.isEmpty()) {
            estadoLabel->setText("Login exitoso");
            botonProteger->setEnabled(true);
            QMessageBox::information(this, "Éxito", "Token recibido.");
        } else {
            QMessageBox::warning(this, "Error", "Token no recibido.");
        }
    } else {
        QMessageBox::critical(this, "Error", "Login fallido: " + reply->errorString());
    }

    reply->deleteLater();
}

void Login::solicitarProtegido() {
    QUrl url("http://localhost:8000/protegido"); // Ruta de ejemplo protegida
    QNetworkRequest request(url);
    request.setRawHeader("Authorization", ("Bearer " + token).toUtf8());

    QNetworkReply *reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QString respuesta = QString::fromUtf8(reply->readAll());
            QMessageBox::information(this, "Protegido", respuesta);
        } else {
            QMessageBox::warning(this, "Error", "Acceso denegado.");
        }
        reply->deleteLater();
    });
}
