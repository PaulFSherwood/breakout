#ifndef BRICK_H
#define BRICK_H
#pragma once
#include <QImage>
#include <QRect>

class Brick
{
public:
    Brick(int, int);
    ~Brick();

public:
    bool isDestroyed();
    void setDestroyed(bool destr);
    QRect getRect();
    void setRect(QRect rct);
    QImage & getImage();

private:
    QImage image;
    QRect rect;
    bool destroyed;
};

#endif // BRICK_H
