#ifndef BOLA_H
#define BOLA_H
#include <QGraphicsItem>
#include <QPainter>

class bola: public QGraphicsItem
{
    int posx;
    int posy;
    int radio;
    int velocidad;

public:
    bola();
    bola(int x, int y, int r);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
};

#endif // BOLA_H
