#include "snake.h"

#include <QDebug>

Snake::Snake(QString name)
{
    this->name = name;
    this->score = 0;
    this->step = 1;

    this->setBrush(QBrush(Qt::yellow));
    this->setPen(QPen(Qt::NoPen));

    this->keyLeft = false;
    this->keyRight = false;
    this->angle = 2;
    this->direction = 0;
    life = true;
    setColor(QString("white"));
//    head = new QGraphicsEllipseItem();
    this->setRect(0,0,Config::SIZE_SNAKE, Config::SIZE_SNAKE);
    setZValue(1);

    this->compteurPrint = Config::COMPTEUR_PRINT;

}

void Snake::move()
{
    if (isAlive()) {

        rotation();
        float radToDeg = direction * M_PI / 180;
        float x2 = x()+step*cos(radToDeg);
        float y2 = y()+step*sin(radToDeg);

        if (checkColisions()) {
            // Colision so snake must be dead :s
            // The snake stop because his position is not updated anymore
            commitSuicide();

        } else {
            // Gestion sortie fenetre des serpents
            int width = Config::WIDTH;
            int height = Config::HEIGHT;

            std::pair<int, int> * dir = checkDirection();
            int lr = dir->first;
            int hb = dir->second;

            int boundWidth = boundingRect().width()/2;
            int boundHeight = boundingRect().height()/2;

            int delta = getSize()/2;

            if (x2<=-boundWidth && lr==Snake::GAUCHE) {
                x2 += width;
                courbe.moveTo(x2+delta, this->y()+delta);
                qDebug()<<"gauche";
            } else if (x2+boundWidth >= width && lr==Snake::DROITE) {
                x2 -= width;
                qDebug()<<"droite";
                courbe.moveTo(x2+delta, this->y()+delta);
            }
            if (y2<=-boundHeight && hb==Snake::HAUT) {
                y2 += height;
                qDebug()<<"haut";
                courbe.moveTo(this->x()+delta, y2+delta);
            } else if (y2+boundHeight >= height && hb==Snake::BAS) {
                y2 -= height;
                qDebug()<<"bas";
                courbe.moveTo(this->x()+delta, y2+delta);
            }

            //new pos of snake
            setPos(x2, y2);

            if (this->compteurPrint <= 0) {
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
    if (!(keyRight && keyLeft)) {

        if (keyRight) {
            direction += angle;
        } else if (keyLeft) {
            direction -= angle;
        }
    }

    direction = direction % 360;
    if (direction < 0) {
        direction += 360;
    }

}

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

void Snake::commitSuicide()
{
    //TODO faire des trucs
    //comme donner des points aux adverssaires
    life = false;


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

bool Snake::checkColisions()
{
    QList<QGraphicsItem *> list = collidingItems();
    int p = 0;

    foreach(QGraphicsItem * i , list)
    {
        Snake * item= dynamic_cast<Snake*>(i);
        if (item)
        {
            //if snake type
            list.removeAt(p);
        } else {
            p++;
        }
    }

    return (list.size() > 0) ;
}

bool Snake::isAlive()
{
    return life;
}

void Snake::getOutOfHell()
{
    life = true;
}

QString Snake::getName()
{
    return name;
}

int Snake::getScore()
{
    return score;
}

void Snake::resetScore()
{
    this->score = 0;
}

void Snake::addPoint()
{
    this->score++;
}

void Snake::setScene(QGraphicsScene *scene)
{
    this->scene = scene;
    pathCourbe = new QGraphicsPathItem(courbe);
    scene->addItem(pathCourbe);
}

void Snake::setColor(QString color)
{
    couleur = color;
}

qreal Snake::getSize() const
{
    //qd on ajoutera les bonus, il faudra
    return Config::SIZE_SNAKE;
}

void Snake::addTrace()
{
    scene->removeItem(pathCourbe);
    courbe.lineTo(this->x()+getSize()/2,this->y()+getSize()/2);
    pathCourbe = new QGraphicsPathItem(courbe);
    pathCourbe->setPen(QPen(QBrush(QColor(couleur)), getSize()));
    pathCourbe->setBrush(QBrush(QColor(QString("white"))));
    scene->addItem(pathCourbe);

}

void Snake::setPosInit(float x, float y)
{
    //TODO actualiser la position de la courbe en fonction de la pos du snake
    QGraphicsItem::setPos(x, y);

    this->courbe.moveTo(x+getSize()/2,y+getSize()/2);

}





