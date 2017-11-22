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

    int width = 500;
    int height = 500;

    layout = new QHBoxLayout();
    game_win = new GameWindow(this, width, height);
    layout->addWidget(game_win);
    sb = new ScoreBoard(this, game_win->getSnakes());
    layout->addWidget(sb);


    this->centralWidget()->setLayout(layout);

    setFixedSize(sb->width()+game_win->width()+layout->margin(), game_win->height()+ui->menubar->height()+layout->margin()*2);

    QObject::connect(ui->action_new, SIGNAL(triggered(bool)), game_win, SLOT(initPart()));
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

void MainWindow::makeSnakes()
{
    //game_win->updateSnake(dialogConfig->getInfo());
}

