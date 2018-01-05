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
#include "bonus_reverse.h"
#include "bonus_ghost.h"

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
    QTimer * clock;//timer pour effectuer un tour de jeu (un deplacement de chaque serpent)
    QGraphicsScene * scene;//la zone d'evolution des joueurs
    ScoreBoard * sb;//la zone d'affichage des scores des joueurs
    std::vector<Snake*> snakes;//la liste des serpents present dans la partie
    std::vector<Wall*> walls;//la liste des murs/bordure de la scene
    std::vector<QString> joueurs;
    int nbAlive;//indique le nombre de joueurs encore en vie lors d'une manche
    int spawnBonusTic;//entier a atteindre avant de faire spawn un bonus
    int spawnBonus;//compteur incrementant jusqu'a ajouter un bonus

};

#endif // GAMEWINDOW_H
