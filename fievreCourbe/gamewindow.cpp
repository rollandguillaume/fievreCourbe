#include "gamewindow.h"
#include <QTimer>

#include <QDebug>

GameWindow::GameWindow(QWidget *parent)
    : QGraphicsView(parent)
{

    un = new Snake("un", 30, 40);
    deux = new Snake("deux", 50, 100);


    QGraphicsScene * scene = new QGraphicsScene();
    scene->addItem(un);
    scene->addItem(deux);

    this->setScene(scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->setFixedSize(800, 600);
    scene->setSceneRect(0,0,800,600);

    QTimer * clock = new QTimer();
    connect(clock,SIGNAL(timeout()),this,SLOT(play()));
    clock->start(50);


}

GameWindow::~GameWindow()
{

}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()==false) {
        if (event->key() == Qt::Key_Left){
            un->setKeyLeft(true);
        }
        else if (event->key() == Qt::Key_Right){
            un->setKeyRight(true);
        }
        else if (event->key() == Qt::Key_Q){
            deux->setKeyLeft(true);
        }
        else if (event->key() == Qt::Key_S){
            deux->setKeyRight(true);
        }
    }
}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()==false) {

        if (event->key() == Qt::Key_Left){
            un->setKeyLeft(false);
        }
        else if (event->key() == Qt::Key_Right){
            un->setKeyRight(false);
        }
        else if (event->key() == Qt::Key_Q){
            deux->setKeyLeft(false);
        }
        else if (event->key() == Qt::Key_S){
            deux->setKeyRight(false);
        }
    }
}

void GameWindow::play()
{
    un->move();
    deux->move();
}


