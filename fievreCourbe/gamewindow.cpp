#include "gamewindow.h"

GameWindow::GameWindow(std::vector<QString> joueurs, QWidget *parent, int width, int height)
    : QGraphicsView(parent)
{
    // Initialise la liste de joueurs
    this->joueurs = joueurs;

    // Création de la scène
    scene = new QGraphicsScene();
    this->setScene(scene);

    // On retire les scrollbars
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Taille fixer
    this->setFixedSize(width, height);
    scene->setSceneRect(0,0,width,height);

    // Background noir
    this->setBackgroundBrush(QBrush(Qt::black));

    // Timer ??
    clock = new QTimer();

    // Signal ??
    connect(clock,SIGNAL(timeout()),this,SLOT(play()));

    // Séquence d'initialisation
    initPart();

}

// ??
GameWindow::~GameWindow()
{

}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()==false) {
        int size = snakes.size();
        for (int s = 0; s < size; s++) {
            if (event->key() == snakes[s]->getKeyOnRight()) {
                snakes[s]->setKeyRight(true);
            } else if (event->key() == snakes[s]->getKeyOnLeft()) {
                snakes[s]->setKeyLeft(true);
            }
        }

        //EVENT PAUSE
        if (event->key() == Qt::Key_Space) {
            if (clock->isActive()) {
                clock->stop();
            } else if (nbAlive == 1) {
                initPart();
            } else {
                clock->start(13);
            }
        }
    }
}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()==false) {
        int size = snakes.size();
        for (int s = 0; s < size; s++) {
            if (event->key() == snakes[s]->getKeyOnRight()) {
                snakes[s]->setKeyRight(false);
            } else if (event->key() == snakes[s]->getKeyOnLeft()) {
                snakes[s]->setKeyLeft(false);
            }
        }
    }
}

void GameWindow::initPart()
{
    if ( clock->isActive() ){
        clock->stop();
    }
    nbAlive = 0;

    toRemoveSnakesOnScene();
    createSnakes();
    toPlaceSnakesOnScene();

    destroyWalls();
    erectWalls();
}

// Efface tous les serpents sur l'écran
void GameWindow::toRemoveSnakesOnScene()
{
    int size = snakes.size();
    for (int s = 0; s < size; s++) {
        scene->removeItem(snakes[s]);
        snakes[s]->clearPath();
    }

}

// Créer tous les serpents
void GameWindow::createSnakes()
{
    snakes.clear();

    int size = joueurs.size();
    for (int s = 0; s < size; s++) {
        QString tmp = joueurs[s];
        qDebug() << tmp;
        QStringList test = tmp.split(';');

        snakes.push_back(new Snake(test.at(0)));
        snakes[s]->setKeyOnLeft(test.at(1));
        snakes[s]->setKeyOnRight(test.at(2));
        snakes[s]->setColor(test.at(3));
    }

    for (int s = 0; s < size; s++) {
        snakes[s]->setScene(scene);
    }
}

// Place tous les serpents sur l'écran
void GameWindow::toPlaceSnakesOnScene()
{
    //give a random position
    snakes[0]->setPosInit(30, 40);
    snakes[1]->setPosInit(50, 100);

    //to place all snakes
    int size = snakes.size();
    for (int s = 0; s < size; s++) {
        scene->addItem(snakes[s]);
    }
}

// Détruit les murs
void GameWindow::destroyWalls()
{
    int size = walls.size();
    for (int s = 0; s < size; s++) {
        scene->removeItem(walls[s]);
    }
}

// Créer les murs
void GameWindow::erectWalls()
{
    int width = Config::WIDTH;
    int height = Config::HEIGHT;
    int wallSize = Config::WALL_SIZE;
    if(walls.size()==0){
        walls.push_back(new Wall(0, 0, wallSize, height));
        walls.push_back(new Wall(0, 0, width, wallSize));

        walls.push_back(new Wall(width-wallSize-4, 0, wallSize, height));
        walls.push_back(new Wall(0, height-wallSize-4, width, wallSize));
    }

    int size = walls.size();
    for (int s = 0; s < size; s++) {
        scene->addItem(walls[s]);
    }

}

// Début d'une manche
void GameWindow::play()
{
    int size = snakes.size();
    nbAlive = 0;
    for (int s = 0; s < size; s++) {
        snakes[s]->move();
        if (snakes[s]->isAlive()) {
            nbAlive++;
        }
    }
    if (nbAlive <= 1) {
        clock->stop();
    }

}

/*******************
 ***** GETTERS *****
 *******************/
std::vector<Snake*>* GameWindow::getSnakes()
{
    return &snakes;
}
