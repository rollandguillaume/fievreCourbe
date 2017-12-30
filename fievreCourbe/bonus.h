#ifndef BONUS_H
#define BONUS_H

#include <QGraphicsPixmapItem>
#include "config.h"
#include "snake.h"

class Snake;//anticipation d'inclusion

class Bonus : public QGraphicsPixmapItem
{
public:
    Bonus();
    void init(int x, int y, std::vector<Snake*> *snakes);
    virtual void execute(Snake*s);

public:
    QString filename;
    std::vector<Snake*> * snakes;
};

#endif // BONUS_H
