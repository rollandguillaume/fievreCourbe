#include "bonus_reverse.h"

/**
 * @brief Bonus_closepath::Bonus_closepath
 *  constructeur initialisant le nom de l'image de ce bonus
 * @param snakes la liste des serpents d'une partie
 */
Bonus_reverse::Bonus_reverse(std::vector<Snake *> *snakes)
{
    filename = "./bonus/reverse.png";
    Bonus::init(snakes);
}

/**
 * @brief Bonus_ghost::execute
 *  pour chaque serpent de la partie
 *  les serpents qui avait leur touche inverse reviennent a la normale
 *  et ceux qui avaient leur touche normale deviennent inversées
 * @param s le serpent a l'origine du declenchement du bonus
 */
void Bonus_reverse::execute(Snake *s)
{
    qDebug()<<"REVERSE :"<<s->getName();

    int size = snakes->size();
    for (int n = 0; n < size; n++) {
        Snake * item = dynamic_cast<Snake*>(snakes->at(n));
        if (item)
        {
            if (item != s) {
                item->reverseKey();
            }
        }
    }
}
