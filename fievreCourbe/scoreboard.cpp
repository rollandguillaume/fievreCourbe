#include "scoreboard.h"
#include "ui_scoreboard.h"

#include <QDebug>

ScoreBoard::ScoreBoard(QWidget *parent, std::vector<Snake*> *snakes) :
    QWidget(parent),
    ui(new Ui::ScoreBoard)
{
    ui->setupUi(this);

    // Boucle sur tous les snakes
    int size = snakes->size();

    for (int s = 0; s < size; s++) {
        // On créer l'affichage du score d'un snake
        scores.push_back(
                    new std::pair<QLabel*, QLabel*>(
                        new QLabel(snakes->at(s)->getName()),
                        new QLabel(QString("0"))
                    )
        );
    }

    // Le layout contenant les scores
    QGridLayout *layout = new QGridLayout();

    // On ajoute les labels pour chaque snake
    for (int i = 0; i < size; i++) {
        layout->addWidget(scores[i]->first, i, 0);
        layout->addWidget(scores[i]->second, i, 1);
    }

    this->setStyleSheet("QLabel {font: bold 14px}");

    ui->verticalLayout->addLayout(layout);
}

ScoreBoard::~ScoreBoard()
{
    delete ui;
}

void ScoreBoard::score(std::vector<Snake*> *snakes)
{
    // Boucle sur tous les snakes
    int size = snakes->size();

    for (int s = 0; s < size; s++) {
        scores.at(s)->first->setText(snakes->at(s)->getName());
        scores.at(s)->second->setText(QString::number(snakes->at(s)->getScore()));
        if( snakes->at(s)->getScore() >= (size-1)*10){
            scores.at(s)->first->setText("WINNER : " + snakes->at(s)->getName());
        }
    }

}
