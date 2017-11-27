#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Set the quit action : close the game (Ctrl+Shift+Q)
    QObject::connect(ui->action_quit , SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    // Help dialog : shows the instructions of the game (Ctrl+Shift+H)
    dialog_help = new Dialog_help(this);

    // Initialize the startWindow where you configure the game
    start_win = new StartWindow(this);

    //layout = new QHBoxLayout();
    //layout->addWidget(start_win);

    this->setCentralWidget(start_win);
}

void MainWindow::start()
{
    int width = Config::WIDTH;
    int height = Config::HEIGHT;


    // Configure the GameWindow and the ScoreBoard
    game_win = new GameWindow(this, width, height);

    // Set the new action : restart a new game (Ctrl+Shift+N)
    QObject::connect(ui->action_new, SIGNAL(triggered(bool)), game_win, SLOT(initPart()));

    this->setCentralWidget(game_win);

    // Setting of the window size so it shows all the GameWindow
    setFixedSize(game_win->width(), game_win->height()+ui->menubar->height());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dialogHelp () {
    dialog_help->show();
}

