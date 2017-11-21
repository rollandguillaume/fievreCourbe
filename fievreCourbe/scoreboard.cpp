#include "scoreboard.h"
#include "ui_scoreboard.h"

ScoreBoard::ScoreBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScoreBoard)
{
    ui->setupUi(this);
}

ScoreBoard::~ScoreBoard()
{
    delete ui;
}
