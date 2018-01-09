#include "bonus_closepath.h"

/**
 * @brief Bonus_closepath::Bonus_closepath
 *  constructeur initialisant le nom de l'image de ce bonus
 * @param snakes la liste des serpents d'une partie
 */
Bonus_closepath::Bonus_closepath(std::vector<Snake *> *snakes)
{
    filename = ":/bonus/bonus/closepath.png";
    Bonus::init(snakes);
}

/**
 * @brief Bonus_closepath::execute
 *  pour chaque serpent de la partie
 *  la trace est effacée
 *  la trace est recréer a partir de la position actuelle du serpent
 * @param s le serpent a l'origine du declenchement du bonus
 */
void Bonus_closepath::execute(Snake *s)
{
    qDebug()<<"CLEAR_PATH :"<<s->getName();

    int size = snakes->size();
    for (int n = 0; n < size; n++) {
        Snake * item = dynamic_cast<Snake*>(snakes->at(n));
        if (item)
        {
            item->clearPath();//suppression de la trace
            item->setPosInit(item->x(), item->y());//nouvelle trace créée
        }
    }
}
