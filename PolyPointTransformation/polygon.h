#ifndef BEZIER_H
#define BEZIER_H

#include <QtWidgets/QGraphicsItem>
#include <QtCore/QVector>

class QGraphicsScene;
class Point;

class Polygon : public QGraphicsItem {
public:
    Polygon(const QPolygonF& p, const QVector<QPointF>& points, QGraphicsScene* s);
    ~Polygon();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *p, const QStyleOptionGraphicsItem *opt, QWidget *wgt);
private:
    void recalculate(QPointF&);
private:
    QVector<Point*> m_vertices;
    QPointF m_points[30];
    qreal m_j[30][7];
};

#endif // BEZIER_H
