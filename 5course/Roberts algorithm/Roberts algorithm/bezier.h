#ifndef BEZIER_H
#define BEZIER_H

#include <QGraphicsItem>

class QGraphicsScene;
class Point;

class Bezier : public QGraphicsItem {
public:
    Bezier(Point* k1, Point* k2, Point* k3, QGraphicsScene* s);
    ~Bezier();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *p, const QStyleOptionGraphicsItem *opt, QWidget *wgt);
    void showLines(bool val);

    bool m_showLines;
    Point* p1;
    Point* p2;
    Point* p3;
};

#endif // BEZIER_H
