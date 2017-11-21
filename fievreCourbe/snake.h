#ifndef SNAKE_H
#define SNAKE_H

#include <QThread>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

class Snake : public QGraphicsEllipseItem
{
public:
    Snake(std::__cxx11::string name);
    void move();
    void setKeyRight(bool press);
    void setKeyLeft(bool press);
    void setKeyOnRight(std::string val);
    void setKeyOnLeft(std::string val);
    int getKeyOnRight() const;
    int getKeyOnLeft() const;
    bool checkColisions();
    bool isAlive();
    void getOutOfHell();

private:
    void rotation();
    std::vector<int> checkDirection();
    void commitSuicide();

public:
    static const int BAS = 0;
    static const int DROITE = 1;//direction du serpent
    static const int GAUCHE = 2;
    static const int HAUT = 3;

private:
    std::string name;
    int step;
    bool keyRight;//key right press ??
    bool keyLeft;
    int direction;
    int angle;//angle de rotation
    int keyOnRight;//value of the key to turn on right
    int keyOnLeft;
    bool life;

};

#endif // SNAKE_H
