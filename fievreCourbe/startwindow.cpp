#include "startwindow.h"
#include "ui_startwindow.h"

#include <QDebug>

StartWindow::StartWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    // Button start clicked so it starts the game
    QObject::connect(ui->start_btn, SIGNAL(clicked()), parent, SLOT(start()));

    // Initialisation du formurlaire de controle pour les joueurs
    QLabel *nom = new QLabel("Nom");
    nom->setAlignment(Qt::AlignHCenter);

    QLabel *gauche = new QLabel("Gauche");
    gauche->setAlignment(Qt::AlignHCenter);

    QLabel *droite = new QLabel("Droite");
    droite->setAlignment(Qt::AlignHCenter);

    // Setting the style for all the QLabel on this window
    this->setStyleSheet("QLabel {font: bold 14px}");

    ui->gridLayout->addWidget(nom, 0, 0);
    ui->gridLayout->addWidget(gauche, 0, 2);
    ui->gridLayout->addWidget(droite, 0, 3);

    this->addJoueur();
    this->addJoueur();
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::addJoueur()
{
    qDebug() << "test";
}

void StartWindow::deleteJoueur(int index)
{

}
