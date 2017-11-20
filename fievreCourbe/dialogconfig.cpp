#include "dialogconfig.h"
#include "ui_dialogconfig.h"

DialogConfig::DialogConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConfig)
{
    ui->setupUi(this);

    connect(this,SIGNAL(accepted()), parent, SLOT(makeSnakes()));
}

DialogConfig::~DialogConfig()
{
    delete ui;
}
