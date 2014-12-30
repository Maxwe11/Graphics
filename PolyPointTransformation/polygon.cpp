#include "polygon.h"

#include <QtCore/QDebug>
#include <QtWidgets/QStyle>
#include <QtWidgets/QGraphicsScene>
#include <QPainter>
#include <QtWidgets/QStyleOptionGraphicsItem>
#include <QtCore/qmath.h>

#include "point.h"

Polygon::Polygon(const QPolygonF& p, const QVector<QPointF>& points, QGraphicsScene* s)
    : QGraphicsItem(0)
{
    s->addItem(this);
    this->setAcceptHoverEvents(true);

    for (auto i = p.begin(); i != p.end(); ++i)
        m_vertices << new Point(*i, 3.4, s);

    for (int i = 0; i < 30; ++i)
        m_points[i] = points[i];

//    qreal a[7] = { (m_vertices[1]->pos().y() - m_vertices[0]->pos().y()) /
//                  (m_vertices[1]->pos().x() - m_vertices[0]->pos().x()),

//                  (m_vertices[2]->pos().y() - m_vertices[1]->pos().y()) /
//                  (m_vertices[2]->pos().x() - m_vertices[1]->pos().x()),

//                  (m_vertices[2]->pos().y() - m_vertices[0]->pos().y()) /
//                  (m_vertices[2]->pos().x() - m_vertices[0]->pos().x())
//                };

//    qreal b[7] = { -1.0, -1.0, -1.0 };

//    qreal c[7] = { m_vertices[0]->pos().y() - a[0] * m_vertices[0]->pos().x(),
//				  m_vertices[1]->pos().y() - a[1] * m_vertices[1]->pos().x(),
//				  m_vertices[2]->pos().y() - a[2] * m_vertices[2]->pos().x()
//				};

//	m_j[0] = a[0] * m_p->pos().x() + b[0] * m_p->pos().y() + c[0];
//    m_j[1] = a[1] * m_p->pos().x() + b[1] * m_p->pos().y() + c[1];
//    m_j[2] = a[2] * m_p->pos().x() + b[2] * m_p->pos().y() + c[2];


    for (int i = 0; i < 6; ++i)
    {
        qreal a = (m_vertices[i + 1]->pos().y() - m_vertices[i]->pos().y()) /
                  (m_vertices[i + 1]->pos().x() - m_vertices[i]->pos().x());
        qreal b = -1.0;
        qreal c = m_vertices[i]->pos().y() - a * m_vertices[i]->pos().x();

        for (int j = 0; j < 30; ++j)
            m_j[j][i] = a * m_points[j].x() + b * m_points[j].y() + c;
    }

    qreal a = (m_vertices[0]->pos().y() - m_vertices[6]->pos().y()) /
              (m_vertices[0]->pos().x() - m_vertices[6]->pos().x());
    qreal b = -1.0;
    qreal c = m_vertices[6]->pos().y() - a * m_vertices[6]->pos().x();

    for (int j = 0; j < 30; ++j)
        m_j[j][6] = a * m_points[j].x() + b * m_points[j].y() + c;
}

Polygon::~Polygon()
{
    qDebug() << "curve dest called";

    for(auto p = m_vertices.begin(); p != m_vertices.end(); ++p)
        delete *p;
}

QRectF Polygon::boundingRect() const
{
    QPolygonF plg;

    for (auto p = m_vertices.begin(); p != m_vertices.end(); ++p)
        plg << (*p)->pos();

    return mapFromScene(plg).boundingRect();
}

QPainterPath Polygon::shape() const
{
    QPainterPath path;
    QPolygonF plg;

    for (auto p = m_vertices.begin(); p != m_vertices.end(); ++p)
        plg << (*p)->pos();

    path.addPolygon(mapFromScene(plg));
    return path;
}

void Polygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *opt, QWidget *wgt)
{
    Q_UNUSED(wgt);
    Q_UNUSED(opt);

    static QPen pen(Qt::black);
    pen.setStyle(Qt::SolidLine);
    pen.setWidthF(1.0);
    painter->setPen(pen);

    QPolygonF plg;

    for (auto p = m_vertices.begin(); p != m_vertices.end(); ++p)
        plg << (*p)->pos();

    plg = mapFromScene(plg);

//    pen.setColor(Qt::lightGray);
//    pen.setStyle(Qt::DashDotLine);
//    pen.setWidthF(0.0);

//    painter->setPen(pen);
    painter->drawPolygon(plg);

    qreal A[7], B[7], C[7];
    for (int i = 0; i < 6; ++i)
    {
        A[i] = (m_vertices[i + 1]->pos().y() - m_vertices[i]->pos().y()) /
                  (m_vertices[i + 1]->pos().x() - m_vertices[i]->pos().x());
        B[i] = -1.0;
        C[i] = m_vertices[i]->pos().y() - A[i] * m_vertices[i]->pos().x();
    }
    A[6] = (m_vertices[0]->pos().y() - m_vertices[6]->pos().y()) /
           (m_vertices[0]->pos().x() - m_vertices[6]->pos().x());
    B[6] = -1.0;
    C[6] = m_vertices[6]->pos().y() - A[6] * m_vertices[6]->pos().x();

    QPointF arr[30];
    for (int i = 0; i < 30; ++i)
    {
        qreal a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0;
        for (int j = 0; j < 7; ++j)
        {
            a += A[j] * A[j] / (m_j[i][j] * m_j[i][j]);
            b += A[j] * B[j] / (m_j[i][j] * m_j[i][j]);
            c += A[j] / m_j[i][j] - A[j] * C[j] / (m_j[i][j] * m_j[i][j]);
            d += B[j] * B[j] / (m_j[i][j] * m_j[i][j]);
            e += B[j] / m_j[i][j] - B[j] * C[j] / (m_j[i][j] * m_j[i][j]);
        }

        m_points[i].ry() = (a * e - b * c) / (a * d - b * b);
        m_points[i].rx() = (c - b * m_points[i].y()) / a;
        arr[i] = /*mapFromParent(*/m_points[i]/*)*/;
    }

    for (int i = 0; i < 29; ++i)
        painter->drawLine(arr[i], arr[i + 1]);
    painter->drawLine(arr[0], arr[29]);
//	qreal A[] = { (m_vertices[1]->pos().y() - m_vertices[0]->pos().y()) /
//                  (m_vertices[1]->pos().x() - m_vertices[0]->pos().x()),

//                  (m_vertices[2]->pos().y() - m_vertices[1]->pos().y()) /
//                  (m_vertices[2]->pos().x() - m_vertices[1]->pos().x()),

//                  (m_vertices[2]->pos().y() - m_vertices[0]->pos().y()) /
//                  (m_vertices[2]->pos().x() - m_vertices[0]->pos().x())
//                };


//    qreal B[] = { -1.0, -1.0, -1.0 };

//	qreal C[] = { m_vertices[0]->pos().y() - A[0] * m_vertices[0]->pos().x(),
//				  m_vertices[1]->pos().y() - A[1] * m_vertices[1]->pos().x(),
//				  m_vertices[2]->pos().y() - A[2] * m_vertices[2]->pos().x()
//				};
//	qreal a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0;
//	for (int i = 0; i < 3; ++i)
//	{
//		a += A[i] * A[i] / (m_j[i] * m_j[i]);
//		b += A[i] * B[i] / (m_j[i] * m_j[i]);
//		c += A[i] / m_j[i] - A[i] * C[i] / (m_j[i] * m_j[i]);
//		d += B[i] * B[i] / (m_j[i] * m_j[i]);
//		e += B[i] / m_j[i] - B[i] * C[i] / (m_j[i] * m_j[i]);
//	}

//	qreal y = (a * e - b * c) / (a * d - b * b);
//	qreal x = (c - b * y) / a;

//	m_p->setPos(x, y);
}

void Polygon::recalculate(QPointF& p)
{

}
