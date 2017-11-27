#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QWidget>
#include <QLabel>

#include "snake.h"

namespace Ui {
class ScoreBoard;
}

class ScoreBoard : public QWidget
{
    Q_OBJECT

public:
    explicit ScoreBoard(QWidget * parent, std::vector<Snake*> * snakes);
    ~ScoreBoard();
    void score(int snakeIndex, int score);
    void resetScore();


private:
    Ui::ScoreBoard * ui;
    std::vector<std::pair<QLabel*, QLabel*>*> scores;
};

#endif // SCOREBOARD_H
