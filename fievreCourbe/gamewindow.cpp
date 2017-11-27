#include "gamewindow.h"

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

    destroyWalls();
    erectWalls();
}

void GameWindow::toPlaceSnakesOnScene()
{
    //give a random position
    snakes[0]->setPosInit(30, 40);
    snakes[1]->setPosInit(50, 100);

    //to place all snakes
    int size = snakes.size();
    for (int s = 0; s < size; s++) {
        scene->addItem(snakes[s]);
    }
}

void GameWindow::createSnakes()
{
    snakes.clear();

    snakes.push_back(new Snake(QString("Joueur 1")));
    snakes[0]->setKeyOnRight("3");
    snakes[0]->setKeyOnLeft("2");
    snakes[0]->setColor("orange");
    snakes.push_back(new Snake(QString("Joueur 2")));
    snakes[1]->setKeyOnRight("s");
    snakes[1]->setKeyOnLeft("q");
    snakes[1]->setColor("red");


    int size = snakes.size();
    for (int s = 0; s < size; s++) {
        snakes[s]->setScene(scene);;
    }

}

std::vector<Snake*>* GameWindow::getSnakes()
{
    return &snakes;
}

void GameWindow::toRemoveSnakesOnScene()
{
    int size = snakes.size();
    for (int s = 0; s < size; s++) {
        scene->removeItem(snakes[s]);
    }
}

void GameWindow::erectWalls()
{
    int width = 500;
    int height = 500;
    int wallSize = 5;
    if(walls.size()==0){
        walls.push_back(new Wall(0, 0, wallSize, height));
        walls.push_back(new Wall(width-wallSize, 0, wallSize, height));
        walls.push_back(new Wall(0, height-wallSize, width, wallSize));
        walls.push_back(new Wall(0, 0, width, wallSize));
    }

    int size = walls.size();
    for (int s = 0; s < size; s++) {
        scene->addItem(walls[s]);
    }

}

void GameWindow::destroyWalls()
{
    int size = walls.size();
    for (int s = 0; s < size; s++) {
        scene->removeItem(walls[s]);
    }
}

void GameWindow::play()
{
    int size = snakes.size();
    for (int s = 0; s < size; s++) {
        snakes[s]->move();
    }

}



