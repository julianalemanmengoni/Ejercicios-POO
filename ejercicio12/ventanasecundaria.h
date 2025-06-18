#ifndef VENTANASECUNDARIA_H
#define VENTANASECUNDARIA_H

#include <QWidget>

class VentanaSecundaria : public QWidget {
    Q_OBJECT

public:
    VentanaSecundaria(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Ventana Secundaria");
        resize(400, 300);
    }
};

#endif // VENTANASECUNDARIA_H
