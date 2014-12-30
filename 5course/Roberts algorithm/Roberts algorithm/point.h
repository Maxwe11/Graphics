#ifndef POINT_H
#define POINT_H

#include <QGraphicsItem>

class Point : public QGraphicsItem {
public:
    Point(const QPointF&, qreal weight, QGraphicsScene* s);
    ~Point();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);

    qreal weight() const;
    void setWeight(qreal value);
private:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
private:
    qreal   mRadius;
    qreal   mWeight;
};

#endif // POINT_H
