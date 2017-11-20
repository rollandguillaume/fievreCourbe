#include "snake.h"
#include <iostream>
#include <QKeyEvent>
#include <math.h>


#include <QDebug>

Snake::Snake(std::string name, int x, int y)
{
    this->name = name;
    this->setRect(x,y,10,10);
    this->step = 5;

    this->keyLeft = false;
    this->keyRight = false;
    this->angle = 10;
    this->direction = 0;
}

void Snake::move()
{
    rotation();
    float radToDeg = direction * M_PI / 180;
    setPos(x()+step*cos(radToDeg),y()+step*sin(radToDeg));
}

void Snake::rotation()
{
//    qDebug()<<"angle:" << angle << " ; direction:"<<direction;
    if (keyRight) {
        direction += angle;
    } else if (keyLeft) {
        direction -= angle;
    }

    direction = direction % 360;

}

void Snake::setKeyRight(bool press)
{
    this->keyRight = press;
}

void Snake::setKeyLeft(bool press)
{
    this->keyLeft = press;
}





