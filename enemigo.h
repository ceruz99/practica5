#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <QGraphicsItem>
#include <QPainter>

class enemigo : public QGraphicsItem
{
private:
    int posx;
    int posy;
    int radio;
    int velocidad;
public:
    enemigo();
    enemigo(int x, int y, int r);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
};

#endif // ENEMIGO_H
