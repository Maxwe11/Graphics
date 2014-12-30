#include "model.h"

Model::Model() : m_points(9)
{
}

QVector3D& Model::operator [] (int i)
{
    return m_points[i];
}

const QVector3D& Model::operator [] (int i) const
{
    return m_points[i];
}

QVector3D& Model::operator () (int i, int j)
{
    return m_points[i * 3 + j];
}

const QVector3D& Model::operator () (int i, int j) const
{
    return m_points[i * 3 + j];
}

QVector3D Model::func(qreal u, const QVector3D &r0, const QVector3D &r1, const QVector3D &r2)
{
    return QVector3D(
                        Model::func(u, r0.x(), r1.x(), r2.x()),
                        Model::func(u, r0.y(), r1.y(), r2.y()),
                        Model::func(u, r0.z(), r1.z(), r2.z())
                    );
}

qreal Model::func(qreal u, qreal r0, qreal r1, qreal r2)
{
    return r0 * (1 - u) * (1 - u) + 2 * r1 * (1 - u) * u + r2 * u * u;
}
