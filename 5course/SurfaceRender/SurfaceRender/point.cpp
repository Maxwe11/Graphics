#include <QtCore/QDebug>
#include <QtWidgets/QStyle>
#include <QPainter>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QStyleOptionGraphicsItem>

#include "point.h"

Point::Point(const QPointF& c, qreal w, QGraphicsScene* s)
    : QGraphicsItem(0)
    , mRadius(3.4)
    , mWeight(w)
{
    s->addItem(this);
    this->setPos(c);
    this->setFlags(ItemIsSelectable | ItemIsMovable | ItemSendsScenePositionChanges);
    this->setAcceptHoverEvents(true);
    this->setZValue(1.0);
}

Point::~Point()
{
    qDebug() << "point dest called";
}

QRectF Point::boundingRect() const
{
    return QRectF(-mRadius - 0.5, -mRadius - 0.5, 2 * mRadius + 1.0, 2 * mRadius + 1.0);
}

void Point::paint(QPainter *p, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    Q_UNUSED(widget);

    static QColor color(Qt::blue);
    static QBrush brush(color);

    if (item->state & QStyle::State_MouseOver)
        color.setRgb(255, 0, 0);
    else
        color.setRgb(0, 0, 255);

    brush.setColor(color);
    p->setBrush(brush);
    p->drawEllipse(QPointF(0.0, 0.0), mRadius, mRadius);
}

qreal Point::weight() const
{
    return mWeight;
}

void Point::setWeight(qreal value)
{
    mWeight = value;
}

QVariant Point::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (QGraphicsScene* scene = this->scene())
        scene->update();

    return QGraphicsItem::itemChange(change, value);
}
