#include "wall.h"


Wall::Wall(int x, int y, int w, int h)
{
    this->setRect(x,y,w,h);
    this->setBrush(QBrush(Qt::yellow));
    this->setPen(QPen(Qt::NoPen));
    this->setZValue(1);
}

