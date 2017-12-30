#include "bonus_closepath.h"

Bonus_closepath::Bonus_closepath(std::vector<Snake *> *snakes)
{
    filename = "./bonus/closepath.png";
    Bonus::init(snakes);
}


void Bonus_closepath::execute(Snake *s)
{
    qDebug()<<"CLEAR_PATH :"<<s->getName();

    int size = snakes->size();
    for (int n = 0; n < size; n++) {
        Snake * item = dynamic_cast<Snake*>(snakes->at(n));
        if (item)
        {
            item->clearPath();
            item->setPosInit(item->x(), item->y());
        }
    }
}
