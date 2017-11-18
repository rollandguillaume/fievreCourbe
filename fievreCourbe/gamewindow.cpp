#include "gamewindow.h"

#include <QDebug>

GameWindow::GameWindow(QWidget *parent)
    : QGraphicsView(parent)
{

    un = new Snake("un", 30, 40);
    deux = new Snake("deux", 50, 100);


    QGraphicsScene * scene = new QGraphicsScene();
    scene->addItem(un);
    scene->addItem(deux);

    un->start();
    deux->start();

    this->setScene(scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->setFixedSize(800, 600);
    scene->setSceneRect(0,0,800,600);


}

GameWindow::~GameWindow()
{

}
