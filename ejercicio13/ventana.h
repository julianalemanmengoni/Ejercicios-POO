#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QPixmap>

class Ventana : public QWidget {
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void imagenDescargada(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
    QPixmap imagenFondo;
};

#endif // VENTANA_H
