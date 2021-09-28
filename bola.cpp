#include "bola.h"

bola::bola()
{

}

bola::bola(int x, int y, int r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
    this->velocidad=5;
    setPos(posx,posy);
}

QRectF bola::boundingRect() const
{
    return QRectF(0,0,radio*2,radio*2);
}

void bola::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}

void bola::moveRight()
{
    this->posx+=velocidad;
    setPos(posx,posy);
}

void bola::moveLeft()
{
    this->posx-=velocidad;
    setPos(posx,posy);
}

void bola::moveUp()
{
    this->posy-=velocidad;
    setPos(posx,posy);
}

void bola::moveDown()
{
    this->posy+=velocidad;
    setPos(posx,posy);
}
