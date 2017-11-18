#ifndef SNAKE_H
#define SNAKE_H

#include <QThread>
#include <QGraphicsRectItem>

class Snake : public QGraphicsRectItem, public QThread
{
public:
    Snake(std::__cxx11::string name, int x, int y);

public:
    void run();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

private:
    std::string name;
    int step;
    bool right;
    bool left;

};

#endif // SNAKE_H
