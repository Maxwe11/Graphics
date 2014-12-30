#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/QtOpenGL>
#include <cmath>

#include "cartesianleaf.h"

CartesianLeaf::CartesianLeaf(QObject *parent)
    : QObject(parent)
    , coef(1.0)
    , step(0.01)
    , hot_dot(0)
    , tang_line(false)
{
}

void CartesianLeaf::drawLeaf(const QMatrix& m)
{
    static QPointF p1, p2, d1, d2, tmp;
    static double tmp1, tmp2, t1, t2, dot;

    dot = hot_dot * step;

    for (
            qreal i = -M_PI_4, end = M_PI_2 + 0.99 * M_PI_4;
            i <= end;
            i += step
        )
    {
        tmp1 = qCos(i);
        tmp2 = qSin(i);
        t1   = 30.0 * r(tmp1, tmp2) * tmp1; //1.5 * grid_step
        t2   = 30.0 * r(tmp1, tmp2) * tmp2; //1.5 * grid_step
        p1.setX(t1);
        p1.setY(t2);

        tmp1 = qCos(i + step);
        tmp2 = qSin(i + step);
        t1   = 30.0 * r(tmp1, tmp2) * tmp1; //1.5 * grid_step
        t2   = 30.0 * r(tmp1, tmp2) * tmp2; //1.5 * grid_step
        p2.setX(t1);
        p2.setY(t2);

        Primitives::DrawLine(p1, p2, m);

        if (tang_line && dot >= i && dot <= i + step)
        {
            d1.setX(-40.0 * 20);
            d1.setY(p1.y() + (p2.y() - p1.y()) * (d1.x() - p1.x()) / (p2.x() - p1.x()));
            d2.setX(40.0 * 20);
            d2.setY(p1.y() + (p2.y() - p1.y()) * (d2.x() - p1.x()) / (p2.x() - p1.x()));

            Primitives::DrawLine(d1, d2, m);

            d1.setY(p1.y() - (p2.x() - p1.x()) * (d1.x() - p1.x()) / (p2.y() - p1.y()));
            d2.setY(p1.y() - (p2.x() - p1.x()) * (d2.x() - p1.x()) / (p2.y() - p1.y()));
            Primitives::DrawLine(d1, d2, m);

//            tmp = m.map(QPointF(0.5 * (p1.x() + p2.x()), 0.5 * (p1.y() + p2.y())));
//            Primitives::DrawDot(tmp.x(), tmp.y(), 4.0f);
        }
    }
}

void CartesianLeaf::drawAsymptote(const QMatrix& m)
{
    static QPointF p1, p2;

    p1.setX(-40.0);
    p1.setY(40.0 - coef);
    p2.setX(40.0);
    p2.setY(-40.0 - coef);

    Primitives::DrawLine(20.0 * p1, 20.0 * p2, m); //20 - grid_step
}

void CartesianLeaf::drawJasmine(const QMatrix& m)
{
    static QPointF p1, p2;
    static double tmp1, tmp2, t1, t2;

    for (double i = 0.0; i <= 157.0; i += 1.0)
    {
        tmp1 = qCos(i * step);
        tmp2 = qSin(i * step);
        t1   = 30.0 * r(tmp1, tmp2) * tmp1; //1.5 * grid_step
        t2   = 30.0 * r(tmp1, tmp2) * tmp2; //1.5 * grid_step
        p1.setX(t1);
        p1.setY(t2);

        tmp1 = qCos((i + 1) * step);
        tmp2 = qSin((i + 1) * step);
        t1   = 30.0 * r(tmp1, tmp2) * tmp1; //1.5 * grid_step
        t2   = 30.0 * r(tmp1, tmp2) * tmp2; //1.5 * grid_step
        p2.setX(t1);
        p2.setY(t2);

        Primitives::DrawLine(p1, p2, m);

        p1.setX(-p1.x());
        p2.setX(-p2.x());

        Primitives::DrawLine(p1, p2, m);

        p1.setY(-p1.y());
        p2.setY(-p2.y());

        Primitives::DrawLine(p1, p2, m);

        p1.setX(-p1.x());
        p2.setX(-p2.x());

        Primitives::DrawLine(p1, p2, m);
    }
}

double CartesianLeaf::square() const
{
    return 1.5 * coef * coef;
}

double CartesianLeaf::r(double cos_fi, double sin_fi) const
{
    return 2 * coef * cos_fi * sin_fi / (cos_fi * cos_fi * cos_fi + sin_fi * sin_fi * sin_fi);
}

double CartesianLeaf::dr(double cos, double sin) const
{
    return (3*coef*(cos*cos-sin*sin)*(cos*cos*cos+sin*sin*sin)+3*coef*cos*sin*(3*sin*sin*cos-3*cos*cos*sin))/((cos*cos*cos+sin*sin*sin)*(cos*cos*cos+sin*sin*sin));
}

void CartesianLeaf::AChanged(double val)
{
    this->coef = val;
    static double tmp1, tmp2, t1, t2, length;

    tmp1 = qCos(-0.989*M_PI/4.0);
    tmp2 = qSin(-0.989*M_PI/4.0);
    t1   = qCos(M_PI_2 + 0.99 * M_PI_4);
    t2   = qSin(M_PI_2 + 0.99 * M_PI_4);

    length = qSqrt(r(t1, t2) * r(t1, t2) + dr(t1, t2)*dr(t1, t2)) -
             qSqrt(r(tmp1, tmp2) * r(tmp1, tmp2) + dr(tmp1, tmp2)*dr(tmp1, tmp2));

    emit this->SquareChanged(QString::number(square()));
    emit this->LengthChanged(QString::number(length));
    emit this->Update();
}

void CartesianLeaf::DrawTangLine(bool val)
{
    this->tang_line = val;
    emit this->Update();
}

void CartesianLeaf::ChangeHotDot(int val)
{
    this->hot_dot = val;
    emit this->Update();
}
