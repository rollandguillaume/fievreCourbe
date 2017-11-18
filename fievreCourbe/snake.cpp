#include "snake.h"
#include <iostream>
#include <QKeyEvent>


#include <QDebug>

Snake::Snake(std::string name, int x, int y)
{
    this->name = name;
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setRect(x,y,10,10);
    this->step = 3;
    this->right = false;
    this->left = false;
}

void Snake::run()
{
    while (true) {
//       qDebug() << this->name.c_str();
       this->setFocus();
       this->msleep(100);
       if (this->left) {
           setPos(x()-this->step,y());
       }
       if (this->right) {
           setPos(x()+this->step,y());
       }


    }
}


void Snake::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        this->left = true;
    }
    else if (event->key() == Qt::Key_Right){
        this->right = true;
    }
    else if (event->key() == Qt::Key_Up){
        setPos(x(),y()-this->step);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(),y()+this->step);
    }
}

void Snake::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        this->left = false;
    }
    else if (event->key() == Qt::Key_Right){
        this->right = false;
    }
}



