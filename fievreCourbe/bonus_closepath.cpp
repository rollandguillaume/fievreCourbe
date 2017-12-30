#include "bonus_closepath.h"

#include <QDebug>

Bonus_closepath::Bonus_closepath(int x, int y, std::vector<Snake *> *snakes)
{
    //qDebug()<<"closepath bonus";
    filename = "./bonus/closepath.png";
    Bonus::init(x, y, snakes);
}


void Bonus_closepath::execute(Snake *s)
{
    qDebug()<<"execution du vrai bonus "<<s->getName();

    int size = snakes->size();
    for (int s = 0; s < size; s++) {
        Snake * item = dynamic_cast<Snake*>(snakes->at(s));
        if (item)
        {
            item->clearPath();
            item->setPosInit(item->x(), item->y());
        }
    }
}
