#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QWidget>

namespace Ui {
class ScoreBoard;
}

class ScoreBoard : public QWidget
{
    Q_OBJECT

public:
    explicit ScoreBoard(QWidget *parent = 0);
    ~ScoreBoard();

private:
    Ui::ScoreBoard *ui;
};

#endif // SCOREBOARD_H
