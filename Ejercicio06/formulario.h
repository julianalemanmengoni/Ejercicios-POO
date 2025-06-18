#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>

class QLineEdit;
class QPushButton;

class Formulario : public QWidget {
    Q_OBJECT

public:
    Formulario(QWidget *parent = nullptr);
};

#endif // FORMULARIO_H
