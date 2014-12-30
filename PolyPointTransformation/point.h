#ifndef POINT_H
#define POINT_H

#include <QtWidgets/QGraphicsItem>

class Point : public QGraphicsItem {
public:
    Point(const QPointF& p, qreal radius = 0.0, QGraphicsScene* s = 0);
    ~Point();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);
    void setInit(bool);
private:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
private:
    qreal   radius;
};

#endif // POINT_H
