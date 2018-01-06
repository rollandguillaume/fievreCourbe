#include "dialog_name.h"
#include "ui_dialog_name.h"

Dialog_Name::Dialog_Name(QString winner, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Name)
{
    ui->setupUi(this);
    ui->winner_label->setText(winner);

    QObject::connect(ui->end_btn, SIGNAL(clicked()), this, SLOT(quit()));
}

Dialog_Name::~Dialog_Name()
{
    delete ui;
}
