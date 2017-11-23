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
            int width = Config::WIDTH; //TODO a trouver ailleur : une classe Config Static ??
            int height = Config::HEIGHT;

            std::vector<int> dir = checkDirection();
            int lr = dir[0];
            int hb = dir[1];

            int boundWidth = boundingRect().width()/2;
            int boundHeight = boundingRect().height()/2;

            if (x2<=-boundWidth && lr==Snake::GAUCHE) {
                x2 += width;
            } else if (x2+boundWidth >= width && lr==Snake::DROITE) {
                x2 -= width;
            }
            if (y2<=-boundHeight && hb==Snake::HAUT) {
                y2 += height;
            } else if (y2+boundHeight >= height && hb==Snake::BAS) {
                y2 -= height;
            }

            addTrace();
            //new pos of snake
            setPos(x2, y2);
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

std::vector<int> Snake::checkDirection()
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
    std::vector<int> vect;
    vect.push_back(ret);
    vect.push_back(ret2);


    return vect;
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
void Snake::setKeyOnRight(std::__cxx11::string val)
{
    QKeySequence seq = QKeySequence(QString::fromStdString(val));
    keyOnRight = seq[0];
}

void Snake::setKeyOnLeft(std::__cxx11::string val)
{
    QKeySequence seq = QKeySequence(QString::fromStdString(val));
    keyOnLeft = seq[0];
}

/**
 * check if the right key is pressing
 * @brief Snake::getKeyOnRight
 * @return
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

    return false;
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
}

void Snake::setColor(QString color)
{
    couleur = color;
}

void Snake::addTrace()
{
    QGraphicsEllipseItem * trace = new QGraphicsEllipseItem();

    trace->setRect(0,0,Config::SIZE_SNAKE, Config::SIZE_SNAKE);
    trace->setPos(this->x(), this->y());
    trace->setBrush(QBrush(QColor(couleur)));
    trace->setPen(QPen(Qt::NoPen));

    scene->addItem(trace);

//    delete trace;
}





