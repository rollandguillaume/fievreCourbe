#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->action_quit , SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    dialog_help = new Dialog_help(this);
    dialogConfig = new DialogConfig(this);


    game_win = new GameWindow(this);
    this->setCentralWidget(game_win);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dialogHelp () {
    dialog_help->show();
}

void MainWindow::showConfig () {
    dialogConfig->show();
}

