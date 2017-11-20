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
    clock->start(100);


}

GameWindow::~GameWindow()
{

}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()==false) {
        if (event->key() == Qt::Key_Left){
//            qDebug() << "left press";
            un->setKeyLeft(true);
        }
        else if (event->key() == Qt::Key_Right){
//            qDebug() << "right press";
            un->setKeyRight(true);
        }
        else if (event->key() == Qt::Key_Q){
//            qDebug() << "q press";
            deux->setKeyLeft(true);
        }
        else if (event->key() == Qt::Key_S){
//            qDebug() << "s press";
            deux->setKeyRight(true);
        }
    }
}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()==false) {

        if (event->key() == Qt::Key_Left){
//            qDebug() << "left release";
            un->setKeyLeft(false);
        }
        else if (event->key() == Qt::Key_Right){
//            qDebug() << "right release";
            un->setKeyRight(false);
        }
        else if (event->key() == Qt::Key_Q){
//            qDebug() << "q release";
            deux->setKeyLeft(false);
        }
        else if (event->key() == Qt::Key_S){
//            qDebug() << "s release";
            deux->setKeyRight(false);
        }
    }
}

void GameWindow::play()
{
    un->move();
//    deux->move();
}


