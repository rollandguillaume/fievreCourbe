#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->start_btn, SIGNAL(clicked()), parent, SLOT(start()));
}

StartWindow::~StartWindow()
{
    delete ui;
}
