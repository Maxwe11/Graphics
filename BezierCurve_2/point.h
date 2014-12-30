#ifndef POINT_H
#define POINT_H

#include <QtWidgets/QGraphicsItem>

class Point : public QGraphicsItem {
public:
    Point(const QPointF&, QGraphicsScene* s);
    virtual ~Point();

    QRectF boundingRect() const;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setNeighbors(Point* t1, Point* t2);
protected:
//    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    qreal   radius;
    Point* p1;
    Point* p2;
};

#endif // POINT_H
