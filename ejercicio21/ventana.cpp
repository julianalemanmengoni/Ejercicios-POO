#include "ventana.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include <QRegularExpression>
#include <QFile>
#include <QDir>
#include <QNetworkRequest>
#include <QStandardPaths>

Ventana::Ventana(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Analizador HTML");
    resize(600, 400);

    entradaURL = new QLineEdit;
    botonAnalizar = new QPushButton("Analizar y Descargar");
    textoLog = new QTextEdit;
    textoLog->setReadOnly(true);
    manager = new QNetworkAccessManager(this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(entradaURL);
    layout->addWidget(botonAnalizar);
    layout->addWidget(textoLog);
    setLayout(layout);

    connect(botonAnalizar, SIGNAL(clicked()), this, SLOT(analizarSitio()));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(procesarRespuesta(QNetworkReply*)));
}

void Ventana::analizarSitio() {
    seleccionarCarpeta();
    if (carpetaDestino.isEmpty()) return;

    QUrl url(entradaURL->text());
    if (!url.isValid()) {
        textoLog->append("URL inválida.");
        return;
    }

    manager->get(QNetworkRequest(url));
    textoLog->append("Descargando HTML...");
}

void Ventana::procesarRespuesta(QNetworkReply *reply) {
    if (reply->error()) {
        textoLog->append("Error al obtener HTML.");
        reply->deleteLater();
        return;
    }

    QString html = QString::fromUtf8(reply->readAll());

    QRegularExpression re("(https?:\/\/[^"'<>\s]+\.(jpg|jpeg|png|gif|css|js))");
    QRegularExpressionMatchIterator i = re.globalMatch(html);

    textoLog->append("Recursos encontrados:");

    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString recurso = match.captured(1);
        textoLog->append(recurso);
        descargarArchivo(QUrl(recurso));
    }

    reply->deleteLater();
}

void Ventana::descargarArchivo(const QUrl &url) {
    QNetworkRequest request(url);
    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, [this, reply, url]() {
        if (reply->error()) {
            textoLog->append("Error al descargar: " + url.toString());
            reply->deleteLater();
            return;
        }

        QByteArray datos = reply->readAll();
        QString nombre = extraerNombreArchivo(url);
        QFile archivo(carpetaDestino + "/" + nombre);
        if (archivo.open(QIODevice::WriteOnly)) {
            archivo.write(datos);
            archivo.close();
            textoLog->append("Guardado: " + nombre);
        }

        reply->deleteLater();
    });
}

void Ventana::seleccionarCarpeta() {
    carpetaDestino = QFileDialog::getExistingDirectory(this, "Seleccionar carpeta de descarga");
}

QString Ventana::extraerNombreArchivo(const QUrl &url) {
    return url.fileName();
}
