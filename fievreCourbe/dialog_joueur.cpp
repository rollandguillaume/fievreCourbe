#include "dialog_joueur.h"
#include "ui_dialog_joueur.h"

Dialog_Joueur::Dialog_Joueur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Joueur)
{
    ui->setupUi(this);
}

Dialog_Joueur::~Dialog_Joueur()
{
    delete ui;
}
