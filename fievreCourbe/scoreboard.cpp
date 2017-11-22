#include "scoreboard.h"
#include "ui_scoreboard.h"
#include "snake.h"
#include <QDebug>

ScoreBoard::ScoreBoard(QWidget *parent, std::vector<Snake*> *snakes) :
    QWidget(parent),
    ui(new Ui::ScoreBoard)
{
    ui->setupUi(this);

    int size = snakes->size();
    for (int s = 0; s < size; s++) {
        scores.push_back(
                    new std::pair<QLabel*, QLabel*>(
                        new QLabel(snakes->at(s)->getName()),
                        new QLabel(QString("0"))
                    )
        );
    }

    QGridLayout *layout = new QGridLayout();

    for (int i = 0; i < size; i++) {
        layout->addWidget(scores[i]->first, i, 0);
        layout->addWidget(scores[i]->second, i, 1);
    }
    ui->verticalLayout->addLayout(layout);
}

ScoreBoard::~ScoreBoard()
{
    delete ui;
}

void ScoreBoard::setName(int snakeIndex, QString name)
{
    scores.at(snakeIndex)->first->setText(name);
}

void ScoreBoard::score(int snakeIndex, int score)
{
    scores.at(snakeIndex)->second->setText(QString(score));
}

void ScoreBoard::resetScore()
{
    int size = scores.size();
    for (int i = 0; i < size; i++) {
        scores.at(i)->second->setText(QString("0"));
    }
}
