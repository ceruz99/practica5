#include "muros.h"

muros::muros()
{

}

muros::muros(int x, int y, int _ancho, int _alto)
{
    this->posx=x;
    this->posy=y;
    this->ancho=_ancho;
    this->alto=_alto;
    setPos(posx,posy);
}

QRectF muros::boundingRect() const
{
    return QRectF(posx,posy,ancho,alto);
}

void muros::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}
