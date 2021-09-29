#include "enemigo.h"

enemigo::enemigo()
{

}

enemigo::enemigo(int x, int y, int r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
    this->velocidad=5;
    setPos(posx,posy);
}

QRectF enemigo::boundingRect() const
{
    return QRectF(0,0,radio*2,radio*2);
}

void enemigo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void enemigo::moveRight()
{
    this->posx+=velocidad;
    setPos(posx,posy);
}

void enemigo::moveLeft()
{
    this->posx-=velocidad;
    setPos(posx,posy);
}

void enemigo::moveUp()
{
    this->posy-=velocidad;
    setPos(posx,posy);
}

void enemigo::moveDown()
{
    this->posy+=velocidad;
    setPos(posx,posy);
}
