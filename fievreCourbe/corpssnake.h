#ifndef CORPSSNAKE_H
#define CORPSSNAKE_H

#include <QGraphicsEllipseItem>

/**
 * @brief The CorpsSnake class
 *  represente le corps du serpent
 *  une petite longueur suivant la tete
 *  permettant de connaitre ca couleur notamment
 */
class CorpsSnake : public QGraphicsEllipseItem
{
public:
    CorpsSnake(int size);
};

#endif // CORPSSNAKE_H
