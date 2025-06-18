#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QListWidget>

class Ventana : public QWidget {
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);

private slots:
    void agregarCaja();
    void sumarCajas();
    void compararCajas();

private:
    QDoubleSpinBox *spinDosis;
    QPushButton *btnAgregar;
    QPushButton *btnSumar;
    QPushButton *btnComparar;
    QListWidget *lista;

    void cargarLista();
};

#endif // VENTANA_H
