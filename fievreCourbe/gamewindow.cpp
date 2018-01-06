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
    this->setFixedSize(width+Config::WALL_SIZE, height+Config::WALL_SIZE);
    scene->setSceneRect(0,0,width,height);

    // Background noir
    this->setBackgroundBrush(QBrush(Qt::black));


    // Timer ?? un tour de jeu pour chaque fin du timer
    clock = new QTimer();
    connect(clock,SIGNAL(timeout()),this,SLOT(play()));


    // Séquence d'initialisation
    initPart();

}

// ??
GameWindow::~GameWindow()
{

}

/**
 * @brief GameWindow::keyPressEvent
 *  pour un event clavier
 *  si la touche pressé appartient a un serpent
 *  alors on active le fait que ce serpent tourne
 *  , s'il s'agit d'un event repeat, il est ignoré
 * @param event
 */
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
            } else if (nbAlive <= 1) {
                initPart();
            } else {
                clock->start(13);
            }
        }
    }
}

/**
 * @brief GameWindow::keyPressEvent
 *  pour un event clavier
 *  si la touche relachée appartient a un serpent
 *  alors on désactive le fait que ce serpent tourne
 * @param event
 */
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

/**
 * @brief GameWindow::initPart
 *  initialise une partie au depart d'une manche
 *  enlever tout les bonus s'il y en a
 *  enlever tous les serpents present
 *  replacer tous les serpent a de nouvelle position
 *  replacer les murs
 */
void GameWindow::initPart()
{
    if ( clock->isActive() ){
        clock->stop();
    }

    spawnBonusTic = Config::SPAWN_BONUS;
    spawnBonus = 0;
    removeAllBonus();

    toRemoveSnakesOnScene();
    createSnakes();
    toPlaceSnakesOnScene();

    nbAlive = snakes.size();

    destroyWalls();
    erectWalls();
}

/**
 * @brief GameWindow::toRemoveSnakesOnScene
 *  Efface tous les serpents sur l'écran
 */
void GameWindow::toRemoveSnakesOnScene()
{
    int size = snakes.size();
    for (int s = 0; s < size; s++) {
        scene->removeItem(snakes[s]);
        snakes[s]->clearPath();

        QString tmp = joueurs[s];
        QStringList snake = tmp.split(';');

        tmp = snake[0] + ";" + snake[1] + ";" + snake[2] + ";" + snake[3] + ";" + QString::number(snakes[s]->getScore()) + ";";

        joueurs[s] = tmp;
    }

}

/**
 * @brief GameWindow::createSnakes
 *   Créer tous les serpents
 */
void GameWindow::createSnakes()
{
    snakes.clear();

    int size = joueurs.size();
    for (int s = 0; s < size; s++) {
        QString tmp = joueurs[s];
        QStringList snake = tmp.split(';');

        snakes.push_back(new Snake(snake.at(0)));
        snakes[s]->setKeyOnLeft(snake.at(1));
        snakes[s]->setKeyOnRight(snake.at(2));
        snakes[s]->setColor(snake.at(3));
        snakes[s]->setScore(snake.at(4));
    }

    for (int s = 0; s < size; s++) {
        snakes[s]->setScene(scene);
    }
}

/**
 * @brief GameWindow::toPlaceSnakesOnScene
 *  Place tous les serpents sur l'écran
 */
void GameWindow::toPlaceSnakesOnScene()
{
    //give a random position
    std::pair<int, int> test;

    //to place all snakes
    int size = snakes.size();
    for (int s = 0; s < size; s++) {
        test = getRandomPos();
        snakes[s]->setPosInit(test.first, test.second);
        scene->addItem(snakes[s]);
    }
}

/**
 * @brief GameWindow::destroyWalls
 *  Détruit les murs
 */
void GameWindow::destroyWalls()
{
    int size = walls.size();
    for (int s = 0; s < size; s++) {
        scene->removeItem(walls[s]);
    }
}

/**
 * @brief GameWindow::getRandomPos
 *  donne deux entier aleatoire
 *  un premier compris entre la largeur de la scene en retirant une largeur a gauche et a droite
 *  un second compris entre la hauteur de la scene en retirant une hauteur en haut et en bas
 * @return une pair d'entier servant de coordonnees
 */
std::pair<int, int> GameWindow::getRandomPos()
{
    int min = Config::SPACE_FROM_WALL;
    int maxX = Config::WIDTH-Config::SPACE_FROM_WALL;
    int maxY = Config::HEIGHT-Config::SPACE_FROM_WALL;
    int a = min + ( std::rand() % static_cast<int>(maxX - min + 1));
    int b = min + ( std::rand() % static_cast<int>(maxY - min + 1));
    return std::pair<int, int>(a, b);
}

/**
 * @brief GameWindow::endGame
 *  fin de la partie lorsqu'un joueur atteint un certain score
 *  retour sur l'ecran d'accueil
 */
void GameWindow::endGame()
{
    int size = snakes.size();
    for (int s = 0; s < size; s++) {
        if (snakes[s]->getScore() >= ((size-1)*10)) {
            qDebug() << "Joueur " << s << "a gagné !!";
        }
    }
    // TODO fin de la partie retour vers l'ecran start window ?
}

/**
 * @brief GameWindow::removeAllBonus
 *  Suppression de tous les bonus present sur la scene
 */
void GameWindow::removeAllBonus()
{
    QList<QGraphicsItem*> all = scene->items();

    foreach(QGraphicsItem * i , all)
    {
        Bonus * bonus = dynamic_cast<Bonus*>(i);
        if (bonus) {
            scene->removeItem(i);
        }
    }
}

/**
 * @brief GameWindow::erectWalls
 *  Créer les murs
 */
void GameWindow::erectWalls()
{
    int width = Config::WIDTH;
    int height = Config::HEIGHT;
    int wallSize = Config::WALL_SIZE;
    if(walls.size()==0){
        walls.push_back(new Wall(0, 0, wallSize, height));//mur gauche
        walls.push_back(new Wall(0, 0, width, wallSize));//mur haut

        walls.push_back(new Wall(width-wallSize, 0, wallSize, height));//mur droite
        walls.push_back(new Wall(0, height-wallSize, width, wallSize));//mur bas
    }

    int size = walls.size();
    for (int s = 0; s < size; s++) {
        scene->addItem(walls[s]);
    }
}

/**
 * @brief GameWindow::play
 *   Un tour de jeu
 */
void GameWindow::play()
{
    //add a bonus si le timer de bonus atteint le nombre de tic necessaire
    if (spawnBonus >= spawnBonusTic) {
        makeBonus();
        spawnBonus = 0;
    } else {
        spawnBonus++;
    }

    // Le nombre de Snake
    int size = snakes.size();
    nbAlive = 0;
    // Compteur temporaire
    int tmp = 0;

    for (int s = 0; s < size; s++) {

        // Le nombre de snake vivant
        if (snakes[s]->isAlive()) {
            nbAlive++;
        }

        // Chaque Snake bouge une fois
        snakes[s]->move();

        // Compteur pour savoir si un snake est mort à se tour
        if (snakes[s]->isAlive()) {
            tmp++;
        }

        // Si un snake est mort, on update le score des vivants
        if(tmp != nbAlive) {
            for (int t = 0; t < size; t++) {
                //snakes[t]->updateScore();

                ++ (*snakes[t]);
                this->sb->score(getSnakes());
            }
            nbAlive = tmp;
        }
    }

    if (nbAlive <= 1) {
        clock->stop();
        endGame();
    }
}

/**
 * @brief GameWindow::makeBonus
 *  add a bonus on the scene
 *  en fonction du nombre de bonus existant (voir config)
 *  selection d'un alea entre 0 et le nombre de bonus existant
 *  creation equiprobable d'un bonus
 *  ajout sur la scene en une position aleatoire
 */
void GameWindow::makeBonus()
{
    std::pair<int, int> alea;
    alea = getRandomPos();

    int lequel  = rand() % Config::NBR_BONUS;
    //qDebug()<<"lequel de bonus:"<<lequel;

    Bonus * b = NULL;
    if (lequel==0) {
        b = new Bonus_closepath(getSnakes());
    } else if (lequel==1) {
        b = new Bonus_reverse(getSnakes());
    } else if (lequel==2) {
        b = new Bonus_ghost(getSnakes());
    }

    if (b != NULL) {
        b->posAlea(alea.first, alea.second);
        scene->addItem(b);
    }
}

/**
 * @brief GameWindow::setSB
 * @param sb
 */
void GameWindow::setSB(ScoreBoard *sb)
{
    this->sb = sb;
}

/*******************
 ***** GETTERS *****
 *******************/

/**
 * @brief GameWindow::getSnakes
 * @return la liste des serpents de la partie
 */
std::vector<Snake*>* GameWindow::getSnakes()
{
    return &snakes;
}



