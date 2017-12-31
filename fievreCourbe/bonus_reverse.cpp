#include "bonus_reverse.h"

Bonus_reverse::Bonus_reverse(std::vector<Snake *> *snakes)
{
    filename = "./bonus/reverse.png";
    Bonus::init(snakes);
}

void Bonus_reverse::execute(Snake *s)
{
    qDebug()<<"REVERSE :"<<s->getName();

    int size = snakes->size();
    for (int n = 0; n < size; n++) {
        Snake * item = dynamic_cast<Snake*>(snakes->at(n));
        if (item)
        {
            if (item != s) {
                item->reverseKey();
            }
        }
    }
}
