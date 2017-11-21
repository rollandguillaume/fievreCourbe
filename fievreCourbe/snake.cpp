#include "snake.h"
#include <iostream>
#include <QKeyEvent>
#include <math.h>
#include <QBrush>
#include <QPen>


#include <QDebug>

Snake::Snake(std::string name)
{
    this->name = name;
    this->setRect(0,0,7,7);
    this->step = 1;

    this->setBrush(QBrush(Qt::yellow));

    this->setPen(QPen(Qt::NoPen));

    this->keyLeft = false;
    this->keyRight = false;
    this->angle = 2.5;
    this->direction = 0;
}

void Snake::move()
{
    rotation();
    float radToDeg = direction * M_PI / 180;
    float x2 = x()+step*cos(radToDeg);
    float y2 = y()+step*sin(radToDeg);
//    qDebug() << x2<<","<< y2;
// gestion sortie fenetre des serpents
//    if (x2<=0) {

//    }
//    if (y2<=0) {

//    }
    setPos(x2, y2);
}

void Snake::rotation()
{
//    qDebug()<<"angle:" << angle << " ; direction:"<<direction;
    if (!(keyRight && keyLeft)) {

        if (keyRight) {
            direction += angle;
        } else if (keyLeft) {
            direction -= angle;
        }
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

void Snake::setKeyOnRight(std::__cxx11::string val)
{
    QKeySequence seq = QKeySequence(QString::fromStdString(val));
    keyOnRight = seq[0];
}

void Snake::setKeyOnLeft(std::__cxx11::string val)
{
    QKeySequence seq = QKeySequence(QString::fromStdString(val));
    keyOnLeft = seq[0];
}

int Snake::getKeyOnRight() const
{
    return keyOnRight;
}

int Snake::getKeyOnLeft() const
{
    return keyOnLeft;
}





