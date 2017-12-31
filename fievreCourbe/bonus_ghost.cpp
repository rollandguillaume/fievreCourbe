#include "bonus_ghost.h"


Bonus_ghost::Bonus_ghost(std::vector<Snake *> *snakes)
{
    filename = "./bonus/ghost.png";
    Bonus::init(snakes);
}

void Bonus_ghost::execute(Snake *s)
{
    qDebug()<<"GHOST:"<<s->getName();

    int size = snakes->size();
    for (int n = 0; n < size; n++) {
        Snake * item = dynamic_cast<Snake*>(snakes->at(n));
        if (item)
        {
            if (item != s) {
                item->setHidden(false);
            } else {
                item->setHidden(true);
            }
        }
    }
}
