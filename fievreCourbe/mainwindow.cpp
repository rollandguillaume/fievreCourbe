#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialog_help = new Dialog_help(this);
    QObject::connect(ui->action_quit , SIGNAL(triggered(bool)), qApp, SLOT(quit()));

    stack = new QStackedWidget(this);
    config_win = new ConfigWindow(this);

    stack->addWidget(config_win);
    this->setCentralWidget(stack);
    stack->setCurrentIndex(0);

    QObject::connect(ui->action_Start , SIGNAL(triggered(bool)), this, SLOT(showGame()));
    QObject::connect(ui->action_new , SIGNAL(triggered(bool)), this, SLOT(showConfig()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dialogHelp () {
    dialog_help->show();
}

void MainWindow::showConfig () {
    //TODO
    delete game_win;
    stack->setCurrentIndex(0);
}

void MainWindow::showGame () {
    //TODO
    delete game_win;
    game_win = new GameWindow(this);
    stack->addWidget(game_win);
    stack->setCurrentIndex(1);
//    qDebug() << QString("stack count") << QString::number(stack->count());
}
