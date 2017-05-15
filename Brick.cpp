#include <iostream>
#include "brick.h"

Brick::Brick(int x, int y)
{
    image.load("brickie.png");
    destroyed = false;
    rect = image.rect();
    rect.translate(x, y);
}

Brick::~Brick()
{
    std::cout << ("Brick deleted") << std::endl;
}

bool Brick::isDestroyed()
{
    return destroyed;
}

void Brick::setDestroyed(bool destr)
{
    destroyed = destr;
}

QRect Brick::getRect()
{
    return rect;
}

void Brick::setRect(QRect rct)
{
    rect = rct;
}

QImage &Brick::getImage()
{
    return image;
}
