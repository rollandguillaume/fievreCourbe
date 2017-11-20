#ifndef SNAKE_H
#define SNAKE_H

#include <QThread>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

class Snake : public QGraphicsEllipseItem
{
public:
    Snake(std::__cxx11::string name, int x, int y);
    void move();
    void rotation();
    void setKeyRight(bool press);
    void setKeyLeft(bool press);

private:
    std::string name;
    int step;
    bool keyRight;
    bool keyLeft;
    int direction;
    int angle;//angle de rotation

};

#endif // SNAKE_H
