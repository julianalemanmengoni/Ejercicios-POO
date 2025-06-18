#include "ventana.h"
#include <QNetworkReply>
#include <QPainter>
#include <QUrl>
#include <QNetworkRequest>

Ventana::Ventana(QWidget *parent) : QWidget(parent) {
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &Ventana::imagenDescargada);

    QUrl url("https://picsum.photos/1920/1080");
    manager->get(QNetworkRequest(url));
}

void Ventana::imagenDescargada(QNetworkReply *reply) {
    QByteArray data = reply->readAll();
    imagenFondo.loadFromData(data);
    imagenFondo = imagenFondo.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    update(); // repinta cuando ya está la imagen
}

void Ventana::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    if (!imagenFondo.isNull()) {
        int x = (width() - imagenFondo.width()) / 2;
        int y = (height() - imagenFondo.height()) / 2;
        painter.drawPixmap(x, y, imagenFondo);
    }
}
