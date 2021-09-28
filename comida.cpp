#include "comida.h"

comida::comida(int x, int y)
{
    this->posx=x;
    this->posy=y;
    this->radio=8;
    setPos(posx,posy);
}

QRectF comida::boundingRect() const
{
    return QRectF(0,0,radio*2,radio*2);
}

void comida::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
}
