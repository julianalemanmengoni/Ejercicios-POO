#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include <QPixmap>
#include <QColor>

class Pintura : public QWidget {
    Q_OBJECT

public:
    Pintura(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QPixmap lienzo;
    QPoint ultimoPunto;
    QColor color;
    int grosor;
    bool dibujando;
};

#endif // PINTURA_H
