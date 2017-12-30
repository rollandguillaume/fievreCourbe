#ifndef BONUS_H
#define BONUS_H

#include <QGraphicsPixmapItem>
#include "config.h"
#include "snake.h"
#include <QDebug>

class Snake;//anticipation d'inclusion

class Bonus : public QGraphicsPixmapItem
{
public:
    Bonus();
    void init(std::vector<Snake*> *snakes);
    void posAlea(int x, int y);
    virtual void execute(Snake*s);

public:
    QString filename;
    std::vector<Snake*> * snakes;
};

#endif // BONUS_H
