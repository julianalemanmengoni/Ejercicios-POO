#include "game.h"
#include <QPainter>
#include <QKeyEvent>
#include <QMessageBox>

Game::Game(QWidget *parent)
    : QWidget(parent), gameOver(false), velocidad(5) {
    setFixedSize(800, 300);
    trex = new TRex(50, 200, this);

    timerPrincipal = new QTimer(this);
    connect(timerPrincipal, &QTimer::timeout, this, &Game::actualizar);
    timerPrincipal->start(30);

    timerPajaro = new QTimer(this);
    connect(timerPajaro, &QTimer::timeout, this, &Game::crearPajaro);
    timerPajaro->start(5000);

    cactus.append(new Cactus(width(), 220));
}

void Game::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);
    painter.setBrush(Qt::gray);
    painter.drawRect(0, 250, width(), 50); // suelo

    trex->dibujar(painter);

    for (auto *c : cactus)
        c->dibujar(painter);
    for (auto *p : pajaros)
        p->dibujar(painter);

    if (gameOver) {
        painter.setPen(Qt::red);
        painter.setFont(QFont("Arial", 24));
        painter.drawText(rect(), Qt::AlignCenter, "GAME OVER
Presiona Espacio para reiniciar");
    }
}

void Game::keyPressEvent(QKeyEvent *event) {
    if (gameOver && event->key() == Qt::Key_Space) {
        reiniciarJuego();
        return;
    }

    switch (event->key()) {
        case Qt::Key_Space: trex->saltar(); break;
        case Qt::Key_Down: trex->agacharse(); break;
        case Qt::Key_Left: trex->frenar(); break;
        case Qt::Key_Right: trex->adelantar(); break;
    }
}

void Game::actualizar() {
    if (gameOver) return;

    for (auto *c : cactus) c->mover(velocidad);
    for (auto *p : pajaros) p->mover(velocidad);
    trex->actualizar();

    detectarColisiones();

    // Remover obstáculos fuera de pantalla
    cactus.erase(std::remove_if(cactus.begin(), cactus.end(),
        [](Cactus *c){ return c->fueraPantalla(); }), cactus.end());
    pajaros.erase(std::remove_if(pajaros.begin(), pajaros.end(),
        [](Pajaro *p){ return p->fueraPantalla(); }), pajaros.end());

    if (rand() % 100 < 2)
        cactus.append(new Cactus(width(), 220));

    velocidad += 0.001; // dificultad progresiva

    update();
}

void Game::crearPajaro() {
    pajaros.append(new Pajaro(width(), 180 - rand()%80));
}

void Game::detectarColisiones() {
    QRect rectTrex = trex->rectangulo();

    for (auto *c : cactus) {
        if (rectTrex.intersects(c->rectangulo())) {
            gameOver = true;
            break;
        }
    }

    for (auto *p : pajaros) {
        if (rectTrex.intersects(p->rectangulo())) {
            gameOver = true;
            break;
        }
    }
}

void Game::reiniciarJuego() {
    gameOver = false;
    velocidad = 5;
    cactus.clear();
    pajaros.clear();
    trex->resetear();
    cactus.append(new Cactus(width(), 220));
}
