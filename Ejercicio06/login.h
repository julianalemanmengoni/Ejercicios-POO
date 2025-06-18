#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include "formulario.h"

class Login : public QWidget {
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

private slots:
    void verificarCredenciales();

private:
    QLineEdit *usuario;
    QLineEdit *clave;
    QPushButton *boton;
};

#endif // LOGIN_H
