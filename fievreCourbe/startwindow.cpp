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

    // Button start clicked so it starts the game
    QObject::connect(ui->add_btn, SIGNAL(clicked()), this, SLOT(addJoueurBtn()));

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

    // Ajout de 2 joueurs automatiquement
    this->addJoueur();
    this->addJoueur();

}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::addJoueur()
{
    // Initialisation du joueur i
    int i = joueurs.size();

    // Limitation du nombre de joueurs à 6
    if(i == 5) {
        ui->add_btn->setEnabled(false);
    }
    QString joueur = names[i] + ";";

    // Entrée des touches droites et gauches
    dialog_key = new Dialog_Key("Gauche", this);
    int keyLeft = dialog_key->exec();
    dialog_key = new Dialog_Key("Droite", this);
    int keyRight = dialog_key->exec();

    // Fabriction du QString
    joueur = joueur + QString::number(keyLeft) + ";" + QString::number(keyRight) + ";";
    joueur = joueur + colors[i] + ";0;";

    // Ajout du joueur à la liste
    joueurs.push_back(joueur);

    // Affiche du joueur créer

    QLabel *nom = new QLabel(names[i]);
    nom->setAlignment(Qt::AlignHCenter);

    QLabel *gauche = new QLabel(QKeySequence(keyLeft).toString());
    gauche->setAlignment(Qt::AlignHCenter);

    QLabel *droite = new QLabel(QKeySequence(keyRight).toString());
    droite->setAlignment(Qt::AlignHCenter);

    // Setting the style for all the QLabel on this window
    this->setStyleSheet("QLabel {font: bold 14px}");

    ui->gridLayout->addWidget(nom, i+1, 0);
    ui->gridLayout->addWidget(gauche, i+1, 2);
    ui->gridLayout->addWidget(droite, i+1, 3);
}

void StartWindow::deleteJoueur(int index)
{
    // TODO
}

void StartWindow::addJoueurBtn()
{
    this->addJoueur();
}

std::vector<QString> StartWindow::getJoueurs()
{
    return this->joueurs;
}
