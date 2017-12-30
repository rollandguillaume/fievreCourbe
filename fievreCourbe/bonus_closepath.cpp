#include "bonus_closepath.h"

#include <QDebug>

Bonus_closepath::Bonus_closepath(int x, int y)
{
    //qDebug()<<"closepath bonus";
    filename = "./bonus/test.png";
    Bonus::init(x, y);
}


void Bonus_closepath::execute(Snake *s)
{
    qDebug()<<"execution du vrai bonus "<<s->getName();
}
