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

    this->setCentralWidget(start_win);
}

void MainWindow::start()
{

    int width = Config::WIDTH;
    int height = Config::HEIGHT;


    // Configure the GameWindow and the ScoreBoard
    game_win = new GameWindow(this, width, height);
    sb = new ScoreBoard(this, game_win->getSnakes());

    // Set the new action : restart a new game (Ctrl+Shift+N)
    QObject::connect(ui->action_new, SIGNAL(triggered(bool)), game_win, SLOT(initPart()));

    // The layout that will contain the GameWindow and the ScoreBoard
    layout = new QHBoxLayout();
    layout->addWidget(game_win);
    layout->addWidget(sb);

    this->centralWidget()->setLayout(layout);

    // Setting of the window size so it shows all the GameWindow
    setFixedSize(sb->width()+game_win->width()+layout->margin(), game_win->height()+ui->menubar->height()+layout->margin()*2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dialogHelp () {
    dialog_help->show();
}

