#ifndef DIALOG_JOUEUR_H
#define DIALOG_JOUEUR_H

#include <QDialog>

namespace Ui {
class Dialog_Joueur;
}

class Dialog_Joueur : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Joueur(QWidget *parent = 0);
    ~Dialog_Joueur();

private:
    Ui::Dialog_Joueur *ui;
};

#endif // DIALOG_JOUEUR_H
