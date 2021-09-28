#ifndef MUROS_H
#define MUROS_H
#include <QGraphicsItem>
#include <QPainter>

class muros: public QGraphicsItem
{
public:
    muros();
    int posx;
    int posy;
    int ancho;
    int alto;
    muros(int x, int y, int _ancho, int _alto);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget = nullptr);
};

#endif // MUROS_H
