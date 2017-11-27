#include "dialog_key.h"
#include "ui_dialog_key.h"

Dialog_Key::Dialog_Key(QString label, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Key)
{
    setModal(true);
    ui->setupUi(this);
    ui->key_label->setText(label);
}

Dialog_Key::~Dialog_Key()
{
    delete ui;
}

void Dialog_Key::keyPressEvent(QKeyEvent *event)
{
    this->done(event->key());
}

void Dialog_Key::keyReleaseEvent(QKeyEvent *event)
{
}
