#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <QBrush>

#include <iostream>

#include "snake.h"
#include "wall.h"

class GameWindow : public QGraphicsView
{
    Q_OBJECT

public:
    GameWindow(std::vector<QString> joueurs, QWidget * parent = 0, int width = Config::WIDTH, int height = Config::HEIGHT);
    ~GameWindow();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    void createSnakes();
    std::vector<Snake*> * getSnakes();
    void updateSnake(QGridLayout layout);

private:
    void toPlaceSnakesOnScene();
    void toRemoveSnakesOnScene();
    void erectWalls();
    void destroyWalls();
    std::pair<int, int> getRandomPos();

public slots:
    void play();
    void initPart();

private:
    QTimer * clock;
    QGraphicsScene * scene;
    std::vector<Snake*> snakes;
    std::vector<Wall*> walls;
    std::vector<QString> joueurs;
    int nbAlive;

};

#endif // GAMEWINDOW_H
