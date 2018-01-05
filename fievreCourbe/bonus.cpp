#include "bonus.h"

/**
 * @brief Bonus::Bonus
 */
Bonus::Bonus() : QGraphicsPixmapItem()
{

}

/**
 * @brief Bonus::init
 *  creation du bonus a partir d'une image à partir de son attribut filename
 *  et redimentionnement de celle-ci en fonction de la configuration size_bonus
 * @param snakes la liste des serpents de la partie
 */
void Bonus::init(std::vector<Snake *> *snakes)
{
    this->snakes = snakes;

    QImage image(filename);
    QImage imageResize = image.scaled(Config::SIZE_BONUS, Config::SIZE_BONUS);
    QPixmap pixmap = QPixmap::fromImage(imageResize);

    this->setPixmap(pixmap);

}

/**
 * @brief Bonus::posAlea
 *  positionne le bonus en x,y sur la zone de jeu
 * @param x
 * @param y
 */
void Bonus::posAlea(int x, int y)
{
    this->setOffset(x, y);
}

/**
 * @brief Bonus::execute
 * @param s le serpent a l'origine du déclenchement du bonus
 */
void Bonus::execute(Snake *s)
{
    qDebug()<<"execution du bonus"<<s->getName();
}

