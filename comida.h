#ifndef COMIDA_H
#define COMIDA_H
#include <QGraphicsItem>
#include <QPainter>

class comida : public QGraphicsItem
{
private:
    int posx;
    int posy;
    int radio;
public:
    comida(int x,int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
};

#endif // COMIDA_H
