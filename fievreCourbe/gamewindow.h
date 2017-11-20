#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QtGui>
#include "snake.h"

class GameWindow : public QGraphicsView
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = 0);
    ~GameWindow();
public:
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
public slots:
    void play();
private:
    Snake * un;
    Snake * deux;

};

#endif // GAMEWINDOW_H
