#ifndef NEIGHBORPOINT_H
#define NEIGHBORPOINT_H

#include "point.h"

class NeighborPoint : public Point {
public:
    NeighborPoint(const QPointF&, QGraphicsScene* s);
    ~NeighborPoint();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
};

#endif // NEIGHBORPOINT_H
