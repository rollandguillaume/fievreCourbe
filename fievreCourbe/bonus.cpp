#include "bonus.h"

#include "QDebug"

Bonus::Bonus() : QGraphicsPixmapItem()
{

}

void Bonus::init(int x, int y)
{
    QImage image(filename);
    QImage imageResize = image.scaled(Config::SIZE_BONUS, Config::SIZE_BONUS);
    QPixmap pixmap = QPixmap::fromImage(imageResize);

    this->setPixmap(pixmap);

    this->setOffset(x, y);
}

void Bonus::execute(Snake *s)
{
    qDebug()<<"execution du bonus"<<s->getName();
}

