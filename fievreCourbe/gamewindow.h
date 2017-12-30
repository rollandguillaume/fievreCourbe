#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <QBrush>
#include <QGraphicsView>
#include <QGridLayout>

#include <iostream>

#include "snake.h"
#include "wall.h"
#include "scoreboard.h"
#include "bonus_closepath.h"

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
    void setSB(ScoreBoard * sb);
    void makeBonus();

private:
    void toPlaceSnakesOnScene();
    void toRemoveSnakesOnScene();
    void erectWalls();
    void destroyWalls();
    std::pair<int, int> getRandomPos();
    void endGame();
    void removeAllBonus();

public slots:
    void play();
    void initPart();

private:
    QTimer * clock;
    QGraphicsScene * scene;
    ScoreBoard * sb;
    std::vector<Snake*> snakes;
    std::vector<Wall*> walls;
    std::vector<QString> joueurs;
    int nbAlive;
    int spawnBonusTic;
    int spawnBonus;

};

#endif // GAMEWINDOW_H
