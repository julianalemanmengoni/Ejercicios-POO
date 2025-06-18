#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QTimer>
#include <QVector>
#include "trex.h"
#include "pajaro.h"
#include "cactus.h"

class Game : public QWidget {
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void actualizar();
    void crearPajaro();

private:
    TRex *trex;
    QVector<Pajaro*> pajaros;
    QVector<Cactus*> cactus;
    QTimer *timerPrincipal;
    QTimer *timerPajaro;
    bool gameOver;
    int velocidad;
    void reiniciarJuego();
    void detectarColisiones();
};

#endif // GAME_H
