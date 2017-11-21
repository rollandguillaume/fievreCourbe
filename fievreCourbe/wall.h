#ifndef WALL_H
#define WALL_H

#include <QGraphicsRectItem>


class Wall : public QGraphicsRectItem
{
public:
    Wall(int x, int y, int w, int h);
};

#endif // WALL_H
