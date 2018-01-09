#include "bonus_ghost.h"

/**
 * @brief Bonus_closepath::Bonus_closepath
 *  constructeur initialisant le nom de l'image de ce bonus
 * @param snakes la liste des serpents d'une partie
 */
Bonus_ghost::Bonus_ghost(std::vector<Snake *> *snakes)
{
    filename = ":/bonus/bonus/ghost.png";
    Bonus::init(snakes);
}

/**
 * @brief Bonus_ghost::execute
 *  pour chaque serpent de la partie
 *  s devient caché
 *  tous les autres deviennent visible
 * @param s le serpent a l'origine du declenchement du bonus
 */
void Bonus_ghost::execute(Snake *s)
{
    qDebug()<<"GHOST:"<<s->getName();

    int size = snakes->size();
    for (int n = 0; n < size; n++) {
        Snake * item = dynamic_cast<Snake*>(snakes->at(n));
        if (item)
        {
            if (item != s) {
                item->setHidden(false);
            } else {
                item->setHidden(true);
            }
        }
    }
}
