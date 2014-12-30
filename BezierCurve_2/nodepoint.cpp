#include <QDebug>
#include <QtWidgets/QStyle>
#include <QPainter>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QStyleOptionGraphicsItem>

#include "nodepoint.h"

NodePoint::NodePoint(const QPointF& c, QGraphicsScene *s)
    : Point(c, s)
{
}

NodePoint::~NodePoint()
{
    qDebug() << "Nodepoint destr called";
}

void NodePoint::paint(QPainter *p, const QStyleOptionGraphicsItem *item, QWidget *wgt)
{
    Q_UNUSED(wgt);

    static QColor color(Qt::blue);
    static QBrush brush(color);

    if (item->state & QStyle::State_MouseOver)
        color.setRgb(255, 0, 0);
    else
        color.setRgb(0, 0, 255);

    brush.setColor(color);
    p->setBrush(brush);
    p->drawEllipse(QPointF(0.0, 0.0), radius, radius);
}

QVariant NodePoint::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange && p1 != 0 && p2 != 0)
    {
        QPointF d(value.toPointF() - this->pos());
        this->p1->setPos(p1->pos() + d);
        this->p2->setPos(p2->pos() + d);
    }

    QGraphicsItem::scene()->update();
    return QGraphicsItem::itemChange(change, value);
}
