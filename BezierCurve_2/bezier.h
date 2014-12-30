#ifndef BEZIER_H
#define BEZIER_H

#include <QtWidgets/QGraphicsItem>

class QGraphicsScene;
class Point;

class Bezier : public QGraphicsItem {
public:
    Bezier(Point* k1, Point* k2, Point* k3, Point* k4, QGraphicsScene* s);
    ~Bezier();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *p, const QStyleOptionGraphicsItem *opt, QWidget *wgt);
    void showLines(bool val);
private:
    bool m_showLines;
    Point* p1;
    Point* p2;
    Point* p3;
    Point* p4;
};

#endif // BEZIER_H
