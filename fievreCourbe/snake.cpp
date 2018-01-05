#include "snake.h"

#include <QDebug>

Snake::Snake(QString name)
{
    this->name = name;
    this->step = 1;
    size = Config::SIZE_SNAKE;
    hidden = false;
    reverse = false;

    this->setBrush(QBrush(Qt::yellow));//couleur de la "tete" : jaune
    this->setPen(QPen(Qt::NoPen));

    this->keyLeft = false;
    this->keyRight = false;
    this->angle = 2;
    this->direction = (rand() + 359) % 360;//une direction de depart aleatoire entre 0 et 359
    life = true;
    setColor(QString("white"));//couleur par default du tracé

    this->setRect(0,0,Config::SIZE_SNAKE, Config::SIZE_SNAKE);
    setZValue(1);//permet a la tete d'etre visible par dessus ca trace

    this->compteurPrint = Config::COMPTEUR_PRINT;

    for (int i = 0; i < 4 ; i++) {//fabrication du corps
        // nb: pour pouvoir distinguer ce qui est derriere la tete et la collision avec sa propre trace
        CorpsSnake * item = new CorpsSnake(Config::SIZE_SNAKE);
        corps.push_back(item);
    }

    randomizePath();

}

/**
 * @brief Snake::move
 *  methode d'un deplacement de la tete du serpent (this)
 */
void Snake::move()
{
    if (isAlive()) {//si en vie

        rotation();
        //calcul des nouvelles positions
        float radToDeg = direction * M_PI / 180;
        float x2 = x()+step*cos(radToDeg);
        float y2 = y()+step*sin(radToDeg);

        if (checkColisions()) {
            // Colision so snake must be dead :s
            // The snake stop because his position is not updated anymore
            commitSuicide();

        } else {//si pas eu de collisions alors faire un mouvement

            // DEBUT Gestion sortie fenetre des serpents
            int width = Config::WIDTH;
            int height = Config::HEIGHT;

            std::pair<int, int> * dir = checkDirection();
            int lr = dir->first;//direction gauche-droite
            int hb = dir->second;//direction haut-bas

            int boundWidth = boundingRect().width()/2;
            int boundHeight = boundingRect().height()/2;
            int delta = getSize()/2;//demi mesure de la taille de la tete

            /*
             * si je vais vers la gauche et que ma position futur sort de la scene
             * alors j'ajoute une largeur de scene pour "traverse" la scene et sortir du cote droite
             * on move la courbe pour eviter qu'au prochain tracer on est un trait sur toute la scene
             */
            if (x2<=-boundWidth && lr==Snake::GAUCHE) {
                x2 += width;
                courbe.moveTo(x2+delta, this->y()+delta);
            } else if (x2+boundWidth >= width && lr==Snake::DROITE) {
                x2 -= width;
                courbe.moveTo(x2+delta, this->y()+delta);
            }
            if (y2<=-boundHeight && hb==Snake::HAUT) {
                y2 += height;
                courbe.moveTo(this->x()+delta, y2+delta);
            } else if (y2+boundHeight >= height && hb==Snake::BAS) {
                y2 -= height;
                courbe.moveTo(this->x()+delta, y2+delta);
            }
            // FIN Gestion sortie fenetre des serpents

            //new pos of snake
            setPos(x2, y2);

            // DEBUT Gestion des temps de trace
            cptPath--;
            if (cptPath <= 0) {//si fin du tracer alors on commence a decremante le trou
                cptHole--;
                if (cptHole <= 0) {//si fin du trou alors on redefini de nouvelle longueur de tracage
                    randomizePath();
                }
            }
            // FIN Gestion des temps de trace


            if (this->compteurPrint <= 0) {//existe par soucis d'optimisation graphique, sinon trop de tracage
                addTrace();
                this->compteurPrint = Config::COMPTEUR_PRINT;
            } else {
                this->compteurPrint--;
            }


        }
    }

}

/**
 * rotate of the snake when one key is pressing
 * @brief Snake::rotation
 */
void Snake::rotation()
{
//    qDebug()<<"angle:" << angle << " ; direction:"<<direction;
    if (!(keyRight && keyLeft)) {//si les deux touche ne sont pas presse en meme temps

        if (reverse) {//touches inversees
            if (keyRight) {
                direction -= angle;
            } else if (keyLeft) {
                direction += angle;
            }
        } else {//etat normal
            if (keyRight) {
                direction += angle;//sens horaire
            } else if (keyLeft) {
                direction -= angle;//sens anti horaire
            }
        }
    }

    direction = direction % 360;
    if (direction < 0) {
        direction += 360;
    }

}

/**
 * @brief Snake::checkDirection
 *  retourne une pair d'entier en fonction de la direction de la tete
 *  entier1 pour droite ou gauche
 *  entier2 pour haut ou bas
 * @return
 */
std::pair<int, int>* Snake::checkDirection()
{
    int ret = -1;
    int ret2 = -1;

    if (direction>=90 && direction<270) {
        ret = Snake::GAUCHE;
    } else {
        ret = Snake::DROITE;
    }

    if (direction>180 && direction<=360) {
        ret2 = Snake::HAUT;
    } else {
        ret2 = Snake::BAS;
    }

    return new std::pair<int,int>(ret, ret2);
}

/**
 * @brief Snake::commitSuicide
 *  death of this
 */
void Snake::commitSuicide()
{
    life = false;
}

/**
 * @brief Snake::randomizePath
 *  donne un temps pendant lequel on va imprimer une trace
 *  et un temps pendant lequel on n'imprimera plus
 */
void Snake::randomizePath()
{
    cptPath = rand() % Config::TIC_PATH_MIN + Config::TIC_PATH_MAX;
    //qDebug()<<this->name<<":"<<cptPath;
    cptHole = Config::TIC_HOLE;
}

/**
 * @brief Snake::updateScore
 *  actualisation du score
 *  le score augmente de 1
 */
void Snake::updateScore()
{
    if (life) {
        score++;
    }
}

/**
 * @brief Snake::reverseKey
 *  met le serpent en touche retourne
 *  pour la vue la tete devient bleu si les touches sont retournées
 *  sinon jaune
 */
void Snake::reverseKey()
{
    reverse = !reverse;
    //qDebug()<<this->getName()<<":"<<reverse;
    if (reverse) {
        this->setBrush(QBrush(Qt::blue));
    } else {
        this->setBrush(QBrush(Qt::yellow));
    }
}

/**
 * @brief Snake::checkColisions
 *  controle les collisions avec les autres items de la scene de jeu
 *  et reagit en fonction de la collision
 * @return true si une collision est fatale au serpent
 */
bool Snake::checkColisions()
{
    QList<QGraphicsItem *> list = collidingItems();//recuperation des collisions avec tout type d'autre item graphic
    int p = 0;

    //pour chacun des items colisionnés
    foreach(QGraphicsItem * i , list)
    {
        Bonus * bonus = dynamic_cast<Bonus*>(i);
        if (bonus) {//si c'est un bonus
            //executer le bonus
            bonus->execute(this);
            //le retirer de la list de colision puisque non letal
            list.removeAt(p);
            //supprimer le bonus
            delete bonus;
            bonus = NULL;
        } else {
            if (!hidden) {//si pas avec le pouvoir de traverser les murs
                QGraphicsPathItem * path = dynamic_cast<QGraphicsPathItem*>(i);
                if (path) {//si c'est un item de type trace de serpent

                    QPainterPathStroker * testColisions = new QPainterPathStroker();
                    testColisions->setWidth(Config::SIZE_SNAKE);

                    //est ce que la tete est contenu dans la trace
                    if (testColisions->createStroke(path->path()).contains(QPointF(this->x()+this->getSize(), this->y()+this->getSize()))) {
                    }
                    else if (testColisions->createStroke(path->path()).contains(QPointF(this->x(), this->y()))) {
                    }
                    else {//sinon pas contenu alors on peux ignorer
                        list.removeAt(p);
                    }

                } else {
                    CorpsSnake * itemCorps = dynamic_cast<CorpsSnake*>(i);
                    if (itemCorps) {//si c'est le corps d'un serpent
                        int size = corps.size();
                        for (int i = 0; i < size ; i++) {
                            if (itemCorps == corps[i]) {//si c'est mon corps, j'ignore
                                list.removeAt(p);
                            }
                        }
                    } else {
                        Snake * item = dynamic_cast<Snake*>(i);
                        if (item)//si c'est une autre tete, on ignore
                        {
                            list.removeAt(p);
                        } else {
                            p++;//sinon passer au suivant
                        }
                    }
                }

            } else {//si avec le pouvoir de traverser les murs on ignore tout
                list.removeAt(p);
            }

        }

    }
    return (list.size() > 0) ;
}

/**
 * @brief Snake::addTrace
 *  actualise le tracer d'un serpent
 */
void Snake::addTrace()
{
    bodyFollowHead();
    //recuperation de la position du dernier corps
    float xpos = corps.back()->x();
    float ypos = corps.back()->y();

    scene->removeItem(pathCourbe);//remove pour actualiser avant de repaint, sinon ajout cumulatif = performance ammoindri

    if ((cptHole > 0 && cptPath <= 0) || hidden) {
        //si entrain de faire un trou OU le joueur a le pouvoir de traverser les mur
        //ALORS pas de trace
        courbe.moveTo(xpos+getSize()/2, ypos+getSize()/2);
    } else {
        //sinon faire une ligne jusqu'a la position du dernier corps
        courbe.lineTo(xpos+getSize()/2, ypos+getSize()/2);
    }

    pathCourbe = new QGraphicsPathItem(courbe);

    //applique un pinceau a la trace (couleur, epaisseur, lissage)
    pathCourbe->setPen(QPen(QBrush(QColor(couleur)), getSize(), Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    scene->addItem(pathCourbe);
}

/**
 * @brief Snake::clearPath
 *  supprime la trace et le corps du serpent
 */
void Snake::clearPath()
{
    scene->removeItem(pathCourbe);
    courbe = QPainterPath();
    int size = corps.size();
    for (int c = 0; c < size; c++) {
        scene->removeItem(corps[c]);
    }

}

/**
 * @brief Snake::traceCorps
 *  trace le corps du serpent derriere sa tete en ligne
 *  calcul trigonometrique
 */
void Snake::traceCorps()
{
    int r = getSize()/2;
    int xCHead = x() + getSize()/2;
    int yCHead = y() + getSize()/2;
    float radToDeg = (direction+180) * M_PI / 180;

    int size = corps.size();
    float x3 = xCHead+r*cos(radToDeg);
    float y3 = yCHead+r*sin(radToDeg);
    for (int c = 0; c < size; c++) {
        QGraphicsEllipseItem * item = dynamic_cast<QGraphicsEllipseItem*>(corps[c]);
        if (item) {
            item->setPos(x3-r,y3-r);
            x3 = x3+r*cos(radToDeg);
            y3 = y3+r*sin(radToDeg);
            scene->addItem(corps[c]);
        }
    }
}

/**
 * @brief Snake::bodyFollowHead
 *  en fonction de la position et de la direction de la tete
 *  positionne le corps du serpent
 */
void Snake::bodyFollowHead()
{
    CorpsSnake * co = corps.back();//on prend le dernier corp de la liste
    corps.pop_back();
    co->setPos(x(),y());//on redessine la fin du corp au niveau de la tete
    corps.insert(corps.begin(), co);//on le replace dans le tableau du corp (la trace se dessine avec le dernier de cette liste)
}

/**
 * @brief Snake::operator ++
 *  redefinition d'operateur
 * @return
 */
Snake& Snake::operator++() {
    this->updateScore();//actualisation du score
    return *this;
}

/*******************
 ***** SETTERS *****
 *******************/

void Snake::setScore(QString val)
{
    score = val.toInt();
}

void Snake::setHidden(bool b)
{
    hidden = b;
}

void Snake::setKeyRight(bool press)
{
    this->keyRight = press;
}

void Snake::setKeyLeft(bool press)
{
    this->keyLeft = press;
}

/**
 * initialize the key to turn on right
 * @brief Snake::setKeyOnRight
 * @param val
 */
void Snake::setKeyOnRight(QString val)
{
    QKeySequence seq = QKeySequence(val.toInt()).toString();
    keyOnRight = seq[0];
}

void Snake::setKeyOnLeft(QString val)
{
    QKeySequence seq = QKeySequence(val.toInt()).toString();
    keyOnLeft = seq[0];
}

/**
 * @brief Snake::getOutOfHell
 *  ranime un serpent
 */
void Snake::getOutOfHell()
{
    life = true;
}

void Snake::resetScore()
{
    this->score = 0;
}

/**
 * @brief Snake::setPosInit
 *  positionne this en x,y
 *  trace le corps derriere la tete et initialise la position de tracage de la trace du serpent
 * @param x
 * @param y
 */
void Snake::setPosInit(float x, float y)
{
    //TODO actualiser la position de la courbe en fonction de la pos du snake
    QGraphicsItem::setPos(x, y);
    traceCorps();
    float xpos = corps[corps.size()-1]->x();
    float ypos = corps[corps.size()-1]->y();
    this->courbe.moveTo(xpos+getSize()/2,ypos+getSize()/2);

}

/**
 * @brief Snake::setScene
 * @param scene
 */
void Snake::setScene(QGraphicsScene *scene)
{
    this->scene = scene;
    pathCourbe = new QGraphicsPathItem(courbe);
    scene->addItem(pathCourbe);
}

/**
 * @brief Snake::setColor
 *  change la couleur de la tete
 *  change la couleur du corps du snake
 * @param color
 */
void Snake::setColor(QString color)
{
    couleur = color;
    int size = corps.size();
    for (int i = 0; i < size ; i++) {
        CorpsSnake * item = dynamic_cast<CorpsSnake*>(corps[i]);
        if (item) {
            item->setBrush(QBrush(QColor(couleur)));
            item->setPen(QPen(Qt::NoPen));
        }
    }
}

/*******************
 ***** GETTERS *****
 *******************/

/**
 * check if the right key is pressing
 * @brief Snake::getKeyOnRight
 * @returnfor
 */
int Snake::getKeyOnRight() const
{
    return keyOnRight;
}

int Snake::getKeyOnLeft() const
{
    return keyOnLeft;
}

QString Snake::getName()
{
    return name;
}

int Snake::getScore()
{
    return score;
}

bool Snake::isAlive()
{
    return life;
}

qreal Snake::getSize() const
{
    return size;
}
