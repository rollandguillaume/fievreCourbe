#ifndef BONUS_CLOSEPATH_H
#define BONUS_CLOSEPATH_H

#include "bonus.h"

class Bonus_closepath : public Bonus
{
public:
    Bonus_closepath(std::vector<Snake*> *snakes);
    void execute(Snake*s);
};

#endif // BONUS_CLOSEPATH_H
