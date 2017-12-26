#include "snake.h"

#include <QDebug>

Snake::Snake(QString name)
{
    this->name = name;
    //this->score = 0;
    this->step = 1;
    size = Config::SIZE_SNAKE;
    hidden = false;

    this->setBrush(QBrush(Qt::yellow));
    this->setPen(QPen(Qt::NoPen));

    this->keyLeft = false;
    this->keyRight = false;
    this->angle = 2;
    this->direction = (rand() + 359) % 360;
    life = true;
    setColor(QString("white"));//couleur par default
//    head = new QGraphicsEllipseItem();
    this->setRect(0,0,Config::SIZE_SNAKE, Config::SIZE_SNAKE);
    setZValue(1);

    this->compteurPrint = Config::COMPTEUR_PRINT;

    for (int i = 0; i < 4 ; i++) {
        CorpsSnake * item = new CorpsSnake(Config::SIZE_SNAKE);
        corps.push_back(item);
    }

    randomizePath();

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

            //new pos of snake
            setPos(x2, y2);

            cptPath--;
            if (cptPath <= 0) {
                cptHole--;
                if (cptHole <= 0) {
                    randomizePath();
                }
            }


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


}

void Snake::randomizePath()
{
    cptPath = rand() % Config::TIC_PATH_MIN + Config::TIC_PATH_MAX;
    //qDebug()<<this->name<<":"<<cptPath;
    cptHole = Config::TIC_HOLE;
}

void Snake::updateScore()
{
    if (life) {
        score++;
    }
}

void Snake::setScore(QString val)
{
    score = val.toInt();

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
        QGraphicsPathItem * path = dynamic_cast<QGraphicsPathItem*>(i);
        if (path) {

            QPainterPathStroker * testColisions = new QPainterPathStroker();

            testColisions->setWidth(Config::SIZE_SNAKE);

            // TODO BETTER

            if (testColisions->createStroke(path->path()).contains(QPointF(this->x()+this->getSize(), this->y()+this->getSize()))) {
            }
            else if (testColisions->createStroke(path->path()).contains(QPointF(this->x(), this->y()))) {
            }
            else {
                list.removeAt(p);
            }

        } else {
            CorpsSnake * itemCorps = dynamic_cast<CorpsSnake*>(i);
            if (itemCorps) {
                int size = corps.size();
                for (int i = 0; i < size ; i++) {
                    if (itemCorps == corps[i]) {
                        list.removeAt(p);
                    }
                }
            } else {
                Snake * item = dynamic_cast<Snake*>(i);
                if (item)
                {
                    //if snake type : ignore
                    list.removeAt(p);
                } else {
                    p++;//sinon passer au suivant
                }
            }
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

void Snake::setScene(QGraphicsScene *scene)
{
    this->scene = scene;
    pathCourbe = new QGraphicsPathItem(courbe);
    scene->addItem(pathCourbe);
}

void Snake::setColor(QString color)
{
    couleur = color;

    int size = corps.size();
    for (int i = 0; i < size ; i++) {
        CorpsSnake * item = dynamic_cast<CorpsSnake*>(corps[i]);
        if (item) {
            //item->setBrush(QBrush(QColor(QString("pink"))));
            item->setBrush(QBrush(QColor(couleur)));
            item->setPen(QPen(Qt::NoPen));
        }
    }
}

qreal Snake::getSize() const
{
    return size;
}

void Snake::growUp()
{
    //TODO
}

void Snake::addTrace()
{
    bodyFollowHead();
    float xpos = corps.back()->x();
    float ypos = corps.back()->y();

    scene->removeItem(pathCourbe);

    if (cptHole > 0 && cptPath <= 0) {
        courbe.moveTo(xpos+getSize()/2, ypos+getSize()/2);
    } else {
        courbe.lineTo(xpos+getSize()/2, ypos+getSize()/2);
    }

    pathCourbe = new QGraphicsPathItem(courbe);

    pathCourbe->setPen(QPen(QBrush(QColor(couleur)), getSize(), Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    scene->addItem(pathCourbe);
}

void Snake::setPosInit(float x, float y)
{
    //TODO actualiser la position de la courbe en fonction de la pos du snake
    QGraphicsItem::setPos(x, y);
    traceCorps();
    float xpos = corps[corps.size()-1]->x();
    float ypos = corps[corps.size()-1]->y();
    this->courbe.moveTo(xpos+getSize()/2,ypos+getSize()/2);

}

void Snake::clearPath()
{
    scene->removeItem(pathCourbe);
    //TODO besoin de delete courbe avant ??
    courbe = QPainterPath();
    int size = corps.size();
    for (int c = 0; c < size; c++) {
        scene->removeItem(corps[c]);
    }
}

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

void Snake::bodyFollowHead()
{
    CorpsSnake * co = corps.back();
    corps.pop_back();
    co->setPos(x(),y());
    corps.insert(corps.begin(), co);
}
