#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

class QLabel;

class Ventana : public QWidget {
    Q_OBJECT

public:
    Ventana(const QString &nombre, const QString &ultimoIngreso, QWidget *parent = nullptr);
};

#endif // VENTANA_H
