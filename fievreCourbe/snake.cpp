#include "snake.h"
#include <iostream>
#include <QKeyEvent>
#include <math.h>
#include <QBrush>
#include <QPen>
#include "config.h"


#include <QDebug>

Snake::Snake(std::string name)
{
    this->name = name;
    this->setRect(0,0,Config::SIZE_SNAKE, Config::SIZE_SNAKE);
    this->step = 1;

    this->setBrush(QBrush(Qt::yellow));
    this->setPen(QPen(Qt::NoPen));

    this->keyLeft = false;
    this->keyRight = false;
    this->angle = 2;
    this->direction = 0;
    life = true;
}

void Snake::move()
{
    if (isAlive()) {

        rotation();
        float radToDeg = direction * M_PI / 180;
        float x2 = x()+step*cos(radToDeg);
        float y2 = y()+step*sin(radToDeg);

        if (checkColisions()) {
            //colision so snake must be dead :s
            //the snake stop because his position is not update anymore
            commitSuicide();

        } else {
            // gestion sortie fenetre des serpents
            int width = 500;//TODO a trouver ailleur : une classe Config Static ??
            int height = 500;

            std::vector<int> dir = checkDirection();
            int lr = dir[0];
            int hb = dir[1];

            if (x2<=0 && lr==Snake::GAUCHE) {
                x2 += width-boundingRect().width();
            } else if (x2+boundingRect().width() >= width && lr==Snake::DROITE) {
                x2 -= width-boundingRect().width();
            }
            if (y2<=0 && hb==Snake::HAUT) {
                y2 += height-boundingRect().height();
            } else if (y2+boundingRect().height() >= height && hb==Snake::BAS) {
                y2 -= height-boundingRect().height();
            }

            //new pos of snake
            setPos(x2, y2);
        }
    }

}

/**
 * rotate of the snake when one key is pressing
 * @brief Snake::rotation
 */
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
    if (direction < 0) {
        direction += 360;
    }

}

std::vector<int> Snake::checkDirection()
{
    int ret = -1;
    int ret2 = -1;

    if (direction>=90 && direction<270) {
        ret = Snake::GAUCHE;
    } else {
        ret = Snake::DROITE;
    }

    if (direction>180 && direction<=360) {
        ret2 = Snake::HAUT;
    } else {
        ret2 = Snake::BAS;
    }
    std::vector<int> vect;
    vect.push_back(ret);
    vect.push_back(ret2);


    return vect;
}

void Snake::commitSuicide()
{
    //TODO faire des trucs
    //comme donner des points aux adverssaires
    life = false;


}

void Snake::setKeyRight(bool press)
{
    this->keyRight = press;
}

void Snake::setKeyLeft(bool press)
{
    this->keyLeft = press;
}

/**
 * initialize the key to turn on right
 * @brief Snake::setKeyOnRight
 * @param val
 */
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

/**
 * check if the right key is pressing
 * @brief Snake::getKeyOnRight
 * @return
 */
int Snake::getKeyOnRight() const
{
    return keyOnRight;
}

int Snake::getKeyOnLeft() const
{
    return keyOnLeft;
}

bool Snake::checkColisions()
{
    return (collidingItems().size() > 0) ;
}

bool Snake::isAlive()
{
    return life;
}

void Snake::getOutOfHell()
{
    life = true;
}





