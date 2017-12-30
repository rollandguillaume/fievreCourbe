#ifndef BONUS_REVERSE_H
#define BONUS_REVERSE_H

#include "bonus.h"

class Bonus_reverse : public Bonus
{
public:
    Bonus_reverse(std::vector<Snake*> *snakes);
    void execute(Snake*s);
};

#endif // BONUS_REVERSE_H
