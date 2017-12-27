#ifndef BONUS_H
#define BONUS_H

#include <QGraphicsPixmapItem>

class Bonus : public QGraphicsPixmapItem
{
public:
    Bonus();
    void init();
    void execute();

public:
    QString filename;
};

#endif // BONUS_H
