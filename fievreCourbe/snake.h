#ifndef SNAKE_H
#define SNAKE_H

#include <QThread>
#include <QGraphicsRectItem>

class Snake : public QGraphicsRectItem
{
public:
    Snake(std::__cxx11::string name, int x, int y);
    void move();
    void rotation();
    void setKeyRight(bool press);
    void setKeyLeft(bool press);
private:
    void calculDirY(bool up);

private:
    std::string name;
    int step;
    float dirX;
    float dirY;
    bool keyRight;
    bool keyLeft;
    float rota;//degree for x

};

#endif // SNAKE_H
