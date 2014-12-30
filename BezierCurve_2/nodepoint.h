#ifndef NODEPOINT_H
#define NODEPOINT_H

#include "point.h"

class NodePoint : public Point {
public:
    NodePoint(const QPointF&, QGraphicsScene* s);
    ~NodePoint();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
};

#endif // NODEPOINT_H
