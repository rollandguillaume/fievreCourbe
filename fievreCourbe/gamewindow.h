#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QtGui>
#include "snake.h"

class GameWindow : public QGraphicsView
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = 0, int width = 500, int height = 500);
    ~GameWindow();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    void createSnakes();
private:
    void toPlaceSnakesOnScene();
    void toRemoveSnakesOnScene();
public slots:
    void play();
    void initPart();
private:
    QTimer * clock;
    QGraphicsScene * scene;
    std::vector<Snake*> snakes;


};

#endif // GAMEWINDOW_H
