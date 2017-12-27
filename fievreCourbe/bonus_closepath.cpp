#include "bonus_closepath.h"

#include <QDebug>

Bonus_closepath::Bonus_closepath()
{
    qDebug()<<"closepath bonus";
    filename = "./bonus/test.jpeg";
    Bonus::init();
}


void Bonus_closepath::execute()
{
    qDebug()<<"execution du vrai bonus";
}
