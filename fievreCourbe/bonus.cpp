#include "bonus.h"

#include "QDebug"

Bonus::Bonus() : QGraphicsPixmapItem()
{

}

void Bonus::init()
{
    QImage image(filename);
    QPixmap pixmap = QPixmap::fromImage(image);
    //pixmap.scaledToHeight(300);

    this->setPixmap(pixmap);

    this->setOffset(50, 50);
}

void Bonus::execute()
{
    qDebug()<<"execution du bonus";
}

