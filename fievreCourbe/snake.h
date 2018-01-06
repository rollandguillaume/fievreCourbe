#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include <QBrush>
#include <QPen>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPathItem>
#include <QPainterPath>

#include <iostream>
#include <math.h>

#include "config.h"
#include "corpssnake.h"
#include "bonus.h"

class Snake : public QGraphicsEllipseItem
{
public:
    Snake(QString name);
    void move();
    void setKeyRight(bool press);
    void setKeyLeft(bool press);
    void setKeyOnRight(QString val);
    void setKeyOnLeft(QString val);
    int getKeyOnRight() const;
    int getKeyOnLeft() const;
    void reverseKey();
    bool checkColisions();
    bool isAlive();
    void getOutOfHell();
    QString getName();
    int getScore();
    void resetScore();
    void setScene(QGraphicsScene * scene);
    void setColor(QString color);
    qreal getSize() const;
    void addTrace();
    void setPosInit(float x, float y);
    void clearPath();
    void traceCorps();
    void bodyFollowHead();
    void updateScore();
    void setScore(QString val);
    void setHidden(bool b);
    Snake& operator++();

private:
    void rotation();
    std::pair<int, int> * checkDirection();
    void commitSuicide();
    void randomizePath();

public:
    static const int BAS = 0;
    static const int DROITE = 1;//direction du serpent
    static const int GAUCHE = 2;
    static const int HAUT = 3;
    //int score;

private:
    std::vector<CorpsSnake *> corps;//liste constituant le corps du serpent
    QString name;//le nom du joueurs
    int score;//le score actuel du joueur
    int step;//la vitesse de deplacement du joueur
    bool keyRight;//indique si la touche pour tourner a droite est pressé
    bool keyLeft;//indique si la touche pour tourner a gauche est pressé
    bool reverse;//indique si les commandes du joueurs doivent etre inversé
    int direction;//direction en degre vers la quelle se dirige le joueur (droite toute = 0)
    int angle;//angle de rotation
    int keyOnRight;//value of the key to turn on right
    int keyOnLeft;
    bool life;//isalive
    QGraphicsScene * scene;
    QString couleur;//couleur du joueur
    int compteurPrint;//nombre de tic avant de repaint trace

    QPainterPath courbe;//la trace laissé par le serpent
    QGraphicsPathItem * pathCourbe;
    int cptPath;//nombre de tic d'impression trace
    int cptHole;//nombre de tic de non impression (=creux courbe)

    bool hidden;//indique si le joueur est autorisé a traverser les murs/autres serpents
    int size;//eppaisseur du trait de la trace

};

#endif // SNAKE_H
