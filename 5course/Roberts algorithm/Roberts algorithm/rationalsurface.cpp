#include "rationalsurface.h"
#include <qmath.h>

RationalSurface::RationalSurface()
{
}

void RationalSurface::setPoints(const QVector<QVector4D> &points)
{
    mFaces.clear();
    mPoints = points;
}

QVector<QVector4D> RationalSurface::getPoints() const
{
    return mPoints;
}

void RationalSurface::build() const
{
    if (mPoints.empty())
        return;

    QVector<QVector4D> vec;
    vec.reserve(110);

    QPointF t1, t2;
    QPointF p[] = { mPoints[0].toPointF(), mPoints[1].toPointF(), mPoints[2].toPointF() };
    t1 = p[0];
    vec.push_back(QVector4D(t1.x(), t1.y(), 0.0f, 1.0f));

    for (qreal u = 0.0; u <= 1.0; u += 0.2)
    {
        auto u1 = (1.0 - u) * (1.0 - u) * mPoints[0].w();
        auto u2 = 2 * (1.0 - u) * u * mPoints[1].w();
        auto u3 = u * u * mPoints[2].w();

        t2 = (p[0] * u1 + p[1] * u2 + p[2] * u3) / (u1 + u2 + u3);

        t1 = t2;
        vec.push_back(QVector4D(t2.x(), t2.y(), 0.0f, 1.0f));
    }

    for (float u = 0.0f, step = 36.0 * M_PI / 180.0; u < 2 * M_PI; u += step)
    {
        QMatrix4x4 rot_1, rot_2;
        rot_1.rotate(180.0 * u / M_PI, 0.0f, 1.0f, 0.0f);
        rot_2.rotate(180.0 * (u + step) / M_PI, 0.0f, 1.0f, 0.0f);

        for (int i = 0; i < vec.size() - 1; ++i)
        {
            auto p1 = vec[i], p2 = vec[i];
            auto p3 = vec[i + 1], p4 = vec[i + 1];

            p1 = rot_1.map(p1);
            p2 = rot_2.map(p2);
            p3 = rot_1.map(p3);
            p4 = rot_2.map(p4);

            mFaces.push_back({p2, p3, p1});
            mFaces.push_back({p3, p2, p4});
        }
    }
}
