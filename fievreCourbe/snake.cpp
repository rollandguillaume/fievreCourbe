#include "snake.h"
#include <iostream>
#include <QKeyEvent>
#include <math.h>


#include <QDebug>

Snake::Snake(std::string name, int x, int y)
{
    this->name = name;
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setRect(x,y,10,10);
    this->step = 2;
    this->dirX = 0.5;//entre -1;1
    this->dirY = 0;
    this->keyLeft = false;
    this->keyRight = false;
    this->rota = 0.1;
}

void Snake::move()
{
    rotation();
    setPos(x()+dirX*step,y()+dirY*step);
}

void Snake::rotation()
{

//    qDebug() << this->name.c_str() << " ; l:" << this->keyLeft << " ; r:" << this->keyLeft;
    float rotation = rota;
    bool up = false;


//    qDebug() << "dirX:" << dirX << " ; dirY:" << dirY;

    if (this->keyRight) {//si tourner a droite
        if (this->dirX > 0) {
            if (this->dirY >= 0) {
                //bas droite
                this->dirX -= rotation;
            } else {
                //haut droite
                up = true;
                this->dirX += rotation;
            }
        } else if (this->dirX < 0) {
            if (this->dirY <= 0) {
                //haut gauche
                up = true;
                this->dirX += rotation;
            } else {
                //bas gauche
                this->dirX -= rotation;
            }
        } else {//dirX == 0
            if (this->dirY < 0) {
                //full haut
                up = true;
                this->dirX += rotation;
            } else {
                //full bas
                this->dirX -= rotation;
            }
        }


    } else if (this->keyLeft) {
        if (this->dirX > 0) {
            if (this->dirY <= 0) {
                //haut droite
                up = true;
                this->dirX -= rotation;
            } else {
                //bas droite
                this->dirX += rotation;
            }
        } else if (this->dirX < 0){
            if (this->dirY >= 0) {
                //bas gauche
                this->dirX += rotation;
            } else {
                //haut gauche
                up = true;
                this->dirX -= rotation;
            }
        } else {
            //dirX == 0
            if (this->dirY < 0) {
                //full haut
                up = true;
                this->dirX -= rotation;
            } else {
                //full bas
                this->dirX += rotation;
            }
        }

    }

    if (keyLeft || keyRight) {//recalculation of Y only if one key pressed
        this->calculDirY(up);
    }


}

void Snake::setKeyRight(bool press)
{
    this->keyRight = press;
}

void Snake::setKeyLeft(bool press)
{
    this->keyLeft = press;
}

void Snake::calculDirY(bool up)
{
    int r = 1;
    if (this->dirX >= r) {//full right
        dirX = r;
        dirY = 0;
    } else if (dirX <= -r) {//full left
        dirX = -r;
        dirY = 0;
    } else if (dirX == 0) {
        if (dirY >= 0) {//full
            dirY = r;
        } else {
            dirY = -r;
        }
    } else {
        float tmp = sqrt(pow(r,2)-pow(dirX,2));
        //tmp doit etre positif : sûr :)
        if (up) {
            dirY = -tmp;
        } else {
            dirY = tmp;
        }
        qDebug() << dirY;
    }
}





