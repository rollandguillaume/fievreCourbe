#include "gamewindow.h"
#include <QTimer>
#include <iostream>
#include <QBrush>

#include <QDebug>

GameWindow::GameWindow(QWidget *parent, int width, int height)
    : QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    this->setScene(scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->setFixedSize(width, height);
    scene->setSceneRect(0,0,width,height);

    this->setBackgroundBrush(QBrush(Qt::black));

    clock = new QTimer();
    connect(clock,SIGNAL(timeout()),this,SLOT(play()));

    initPart();


}

GameWindow::~GameWindow()
{

}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()==false) {
        int size = snakes.size();
        for (int s = 0; s < size; s++) {
            if (event->key() == snakes[s]->getKeyOnRight()) {
                snakes[s]->setKeyRight(true);
            } else if (event->key() == snakes[s]->getKeyOnLeft()) {
                snakes[s]->setKeyLeft(true);
            }
        }

        //EVENT PAUSE
        if (event->key() == Qt::Key_Space) {
            if (clock->isActive()) {
                clock->stop();
            } else {
                clock->start(13);
            }
        }
    }
}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()==false) {
        int size = snakes.size();
        for (int s = 0; s < size; s++) {
            if (event->key() == snakes[s]->getKeyOnRight()) {
                snakes[s]->setKeyRight(false);
            } else if (event->key() == snakes[s]->getKeyOnLeft()) {
                snakes[s]->setKeyLeft(false);
            }
        }
    }
}

void GameWindow::initPart()
{
    clock->stop();

    toRemoveSnakesOnScene();
    createSnakes();
    toPlaceSnakesOnScene();
}

void GameWindow::toPlaceSnakesOnScene()
{
    //give a random position
    snakes[0]->setPos(30, 40);
    snakes[1]->setPos(50, 100);

    //to place all snakes
    int size = snakes.size();
    for (int s = 0; s < size; s++) {
        scene->addItem(snakes[s]);
    }
}

void GameWindow::createSnakes()
{
    snakes.clear();


    snakes.push_back(new Snake("un"));

    snakes[0]->setKeyOnRight("3");
    snakes[0]->setKeyOnLeft("2");
    snakes.push_back(new Snake("deux"));

    snakes[1]->setKeyOnRight("s");
    snakes[1]->setKeyOnLeft("q");
}

void GameWindow::toRemoveSnakesOnScene()
{
    int size = snakes.size();
    for (int s = 0; s < size; s++) {
        scene->removeItem(snakes[s]);
    }
}

void GameWindow::play()
{
    int size = snakes.size();
    for (int s = 0; s < size; s++) {
        snakes[s]->move();
    }
}


