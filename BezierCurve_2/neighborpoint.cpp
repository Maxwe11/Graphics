#include <QDebug>
#include <QtWidgets/QStyle>
#include <QPainter>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QStyleOptionGraphicsItem>

#include "neighborpoint.h"

NeighborPoint::NeighborPoint(const QPointF& c, QGraphicsScene *s)
    : Point(c, s)
{
}

NeighborPoint::~NeighborPoint()
{
    qDebug() << "Neigbor destr called";
}

void NeighborPoint::paint(QPainter *p, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    Q_UNUSED(widget);

    static QColor color(Qt::blue);
    static QBrush brush(color);

    if (item->state & QStyle::State_MouseOver)
        color.setRgb(0, 255, 0);
    else
        color.setRgb(0, 0, 255);

    brush.setColor(color);
    p->setBrush(brush);
    p->drawEllipse(QPointF(0.0, 0.0), radius, radius);
}

QVariant NeighborPoint::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionHasChanged && p1 != 0 && p2 != 0)
    {
        QPointF d(p1->pos() * 2 - value.toPointF());
        this->p2->setPos(d);
    }
    this->scene()->update();
    return QGraphicsItem::itemChange(change, value);
}
