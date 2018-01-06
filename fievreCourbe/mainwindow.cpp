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

    // Set the new action : restart a new game (Ctrl+Shift+N)
    QObject::connect(ui->action_new, SIGNAL(triggered(bool)), this, SLOT(newGame()));

    // Initialize the startWindow where you configure the game
    start_win = new StartWindow(this);

    this->setCentralWidget(start_win);
}

/**
 * @brief MainWindow::start
 *  initialise la vue du jeu
 */
void MainWindow::start()
{
    int width = Config::WIDTH;
    int height = Config::HEIGHT;

    // Configure the GameWindow and the ScoreBoard
    game_win = new GameWindow(start_win->getJoueurs(), ui->action_new, this, width, height);
    sb = new ScoreBoard(this, game_win->getSnakes());
    game_win->setSB(sb);

    layout = new QHBoxLayout();
    layout->addWidget(game_win);
    layout->addWidget(sb);

    QWidget * game = new QWidget();
    game->setLayout(layout);
    this->setCentralWidget(game);

    // Setting of the window size so it shows all the GameWindow
    this->adjustSize();
    this->setFixedWidth(game_win->width() + sb->width());

}

void MainWindow::newGame()
{
    start_win = new StartWindow(this);
    this->setCentralWidget(start_win);
    //ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::endGame(QString *winner)
{
    qDebug() << "test" << winner;
}

void MainWindow::dialogHelp () {
    dialog_help->show();
}
