#include "corpssnake.h"

/**
 * @brief CorpsSnake::CorpsSnake
 *  constructeur pour le corp de chaque serpent
 * @param size la taille du corps
 */
CorpsSnake::CorpsSnake(int size) :
    QGraphicsEllipseItem(0,0,size,size)
{

}

