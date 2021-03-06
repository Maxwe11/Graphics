#include <QtCore/QDebug>
#include <QtWidgets/QGraphicsScene>
#include "point.h"

Point::Point(const QPointF& c, QGraphicsScene* s)
    : QGraphicsItem(0)
    , radius(3.4)
    , p1(0), p2(0)
{
    s->addItem(this);
    this->setPos(c);
    this->setFlags(ItemIsSelectable | ItemIsMovable | ItemSendsGeometryChanges);
    this->setAcceptHoverEvents(true);
    this->setZValue(1.0);
}

Point::~Point()
{
    qDebug() << "point dest called";
}

QRectF Point::boundingRect() const
{
    return QRectF(-radius - 0.5, -radius - 0.5, 2 * radius + 1.0, 2 * radius + 1.0);
}

void Point::setNeighbors(Point *t1, Point *t2)
{
    this->p1 = t1;
    this->p2 = t2;
}

//void Point::paint(QPainter *p, const QStyleOptionGraphicsItem *item, QWidget *widget)
//{
//    Q_UNUSED(widget);

//    static QColor color(Qt::blue);
//    static QBrush brush(color);

//    if (item->state & QStyle::State_MouseOver)
//        color.setRgb(0, 255, 0);
//    else
//        color.setRgb(0, 0, 255);

//    brush.setColor(color);
//    p->setBrush(brush);
//    p->drawEllipse(QPointF(0.0, 0.0), radius, radius);
//}

//QVariant Point::itemChange(GraphicsItemChange change, const QVariant &value)
//{
//    this->scene()->update();
//    return QGraphicsItem::itemChange(change, value);
//}
