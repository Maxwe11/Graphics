#include "view.h"

#include <QDebug>
#include <QTimeLine>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QtCore/qmath.h>
#include <QGraphicsItemAnimation>

#include "point.h"
#include "polygon.h"

View::View(QWidget *parent)
    : QGraphicsView(parent)
{
    this->setRenderHint(QPainter::Antialiasing);
    this->setMatrix(QMatrix(1.0, 0.0, 0.0, -1.0, 0.0, 0.0));
    this->setScene(new QGraphicsScene(-0.5 * this->width(), 0.5 * this->height(), this->width(), -this->height()));

    QPolygonF plg;
    plg << QPointF(-150.0, 0.0) << QPointF(-75.0, 150.0) << QPointF(0.0, 150.0)
        << QPointF(75.0, 150.0) << QPointF(150.0, 0.0)   << QPointF(75.0, -150.0)
        << QPointF(-75.0, -150.0);
//    plg << QPointF(-100.0, 0.0) << QPointF(0.0, 100.0) << QPointF(50.0, -100.0);

    qreal rad = 100.0;
    for (qreal i = 0.0, end = 2 * M_PI; i < end; i += 12.0 * M_PI / 180.0 )
        m_points.push_back(QPointF(rad * qCos(i), rad * qSin(i)));

    qDebug() << "lines count: " << m_points.count();
    polygon = new Polygon(plg, m_points, this->scene());
}

View::~View()
{
    qDebug() << "view destr called";
    delete polygon;
}

//void View::mousePressEvent(QMouseEvent* e)
//{
//    QGraphicsView::mousePressEvent(e);
//}
