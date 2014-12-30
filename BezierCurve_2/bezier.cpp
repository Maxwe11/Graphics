#include <QDebug>
#include <QtWidgets/QStyle>
#include <QtWidgets/QGraphicsScene>
#include <QPainter>
#include <QtWidgets/QStyleOptionGraphicsItem>
#include <QtCore/qmath.h>

#include "bezier.h"
#include "point.h"

Bezier::Bezier(Point *k1, Point *k2, Point *k3, Point *k4, QGraphicsScene *s)
    : QGraphicsItem(0)
    , m_showLines(true)
    , p1(k1), p2(k2), p3(k3), p4(k4)
{
    s->addItem(this);
    this->setAcceptHoverEvents(true);
}

Bezier::~Bezier()
{
    qDebug() << "curve dest called";
}

QRectF Bezier::boundingRect() const
{
    return mapFromScene(QPolygonF() << p1->pos() << p2->pos() << p3->pos() << p4->pos()).boundingRect();
}

QPainterPath Bezier::shape() const
{
    QPainterPath path;
    path.addPolygon(mapFromScene(QPolygonF() << p1->pos() << p2->pos() << p3->pos() << p4->pos()));
    return path;
}

void Bezier::paint(QPainter *painter, const QStyleOptionGraphicsItem *opt, QWidget *wgt)
{
    Q_UNUSED(wgt);

        static QColor color(Qt::green);
        static QPen pen(QBrush(color), 2.0);

        if (opt->state & QStyle::State_MouseOver)
            color.setRgb(255, 255, 0);
        else
            color.setRgb(0, 255, 0);

        pen.setColor(color);
        pen.setStyle(Qt::SolidLine);
        pen.setWidthF(1.0);
        painter->setPen(pen);

        static QPointF t1, t2, p[4];
        p[0] = mapFromScene(p1->pos());
        p[1] = mapFromScene(p2->pos());
        p[2] = mapFromScene(p3->pos());
        p[3] = mapFromScene(p4->pos());
        t1 = p[0];
        for (qreal u = 0.01; u <= 1.0; u += 0.01)
        {
            t2 = p[0] * qPow(1.0 - u, 3.0) + p[1] * 3 * qPow(1.0 - u, 2.0) * u +
                 p[2] * 3 * (1.0 - u) * u * u + p[3] * u * u * u;

            painter->drawLine(t1, t2);
            t1 = t2;
        }

        if (m_showLines == true)
        {
            pen.setColor(Qt::lightGray);
            pen.setStyle(Qt::DashDotLine);
            pen.setWidthF(0.0);
            painter->setPen(pen);

            painter->drawLine(p[0], p[1]);
            painter->drawLine(p[1], p[2]);
            painter->drawLine(p[2], p[3]);
            painter->drawLine(p[3], p[0]);
        }
}

void Bezier::showLines(bool val)
{
    m_showLines = val;
}
