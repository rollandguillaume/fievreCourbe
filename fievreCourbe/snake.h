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
    bool checkColisions();
    bool isAlive();
    void getOutOfHell();
    QString getName();
    int getScore();
    void resetScore();
    void addPoint();
    void setScene(QGraphicsScene * scene);
    void setColor(QString color);
    qreal getSize() const;
    void addTrace();
    void setPosInit(float x, float y);
    void clearPath();
    void traceCorps();
    void bodyFollowHead();

private:
    void rotation();
    std::pair<int, int> * checkDirection();
    void commitSuicide();

public:
    static const int BAS = 0;
    static const int DROITE = 1;//direction du serpent
    static const int GAUCHE = 2;
    static const int HAUT = 3;

private:
//    QGraphicsItem * head;
    std::vector<CorpsSnake *> corps;
    QString name;
    int score;
    int step;
    bool keyRight;//key right press ??
    bool keyLeft;
    int direction;
    int angle;//angle de rotation
    int keyOnRight;//value of the key to turn on right
    int keyOnLeft;
    bool life;
    QGraphicsScene * scene;
    QString couleur;
    int compteurPrint;

    QPainterPath courbe;
    QGraphicsPathItem * pathCourbe;

};

#endif // SNAKE_H
