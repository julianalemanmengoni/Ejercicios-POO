#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Ventana : public QWidget {
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);

private slots:
    void analizarSitio();
    void procesarRespuesta(QNetworkReply *reply);
    void descargarArchivo(const QUrl &url);

private:
    QLineEdit *entradaURL;
    QPushButton *botonAnalizar;
    QTextEdit *textoLog;
    QString carpetaDestino;
    QNetworkAccessManager *manager;

    void seleccionarCarpeta();
    QString extraerNombreArchivo(const QUrl &url);
};

#endif // VENTANA_H
