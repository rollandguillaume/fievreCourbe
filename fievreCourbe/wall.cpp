#include "wall.h"
#include <QBrush>

Wall::Wall(int x, int y, int w, int h)
{
    this->setRect(x,y,w,h);
    this->setBrush(QBrush(Qt::yellow));
    this->setZValue(1);
}

