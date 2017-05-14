#include <QPainter>
#include <QApplication>
#include "breakout.h"

Breakout::Breakout(QWidget *parent) : QWidget(parent) {
    x = 0;
    gameOver = false;
    gameWon = false;
    paused = false;
    gameStarted = false;
    ball = new Ball();
    paddle = new Paddle();

    int k = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            bricks[k] = new Brick(j * 40 + 30, i * 10 + 50);
            k++;
        }
    }
}

Breakout::~Breakout() {
    delete ball;
    delete paddle;

    for (int i = 0; i < N_OF_BRICKS; i++) {
        delete bricks[i];
    }
}

void Breakout::paintEvent(QPaintEvent * e) {
    Q_UNUSED(e);

    QPainter painter(this);

    if (gameOver) {
        finishGame(&painter, "Game lost");
    } else if (gameWon) {
        finishGame(&painter, "Victory");
    } else {
        drawObjects(&painter);
    }
}

void Breakout::finishGame(QPainter *, QString message) {
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width(message);

    painter->setFont(font);
    int h = height();
    int w = width();

    painter->translate(QPoint(w/2, h/2));
    painter->drawText(-textWidth/2, 0, message);
}

void Breakout::drawObjects(QPainter * painter) {
    painter->drawImage(ball->getRect(), ball->getImage());
    painter->drawImage(paddle->getRect(), paddle->getImage());

    for (int i = 0; i < N_OF_BRICKS; i++) {
        if (!bricks[i]->isDestroyed()) {
            painter->drawImage(bricks[i]->getRect(), bricks[i]->getImage());
        }
    }
}


























