#ifndef BEZIER_H
#define BEZIER_H

#include <QGraphicsItem>

class QGraphicsScene;

class Bezier : public QGraphicsItem {
public:
    Bezier(QGraphicsItem* k1, QGraphicsItem* k2, QGraphicsItem* k3, QGraphicsItem* k4, QGraphicsScene* s);
    ~Bezier();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *p, const QStyleOptionGraphicsItem *opt, QWidget *wgt);
    void showLines(bool val);
private:
    bool m_showLines;
    QGraphicsItem* p1;
    QGraphicsItem* p2;
    QGraphicsItem* p3;
    QGraphicsItem* p4;
};

#endif // BEZIER_H
