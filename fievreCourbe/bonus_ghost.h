#ifndef BONUS_GHOST_H
#define BONUS_GHOST_H

#include "bonus.h"

class Bonus_ghost : public Bonus
{
public:
    Bonus_ghost(std::vector<Snake*> *snakes);
    void execute(Snake*s);
};

#endif // BONUS_GHOST_H
