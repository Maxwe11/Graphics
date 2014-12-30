#include "model.h"

Model::Model() : m_points(16)
{
}

QVector4D& Model::operator [] (int i)
{
    return m_points[i];
}

const QVector4D &Model::operator [](int i) const
{
    return m_points[i];
}

QVector4D& Model::operator () (int i, int j)
{
    return m_points[i * 4 + j];
}

const QVector4D &Model::operator ()(int i, int j) const
{
    return m_points[i * 4 + j];
}

QVector3D Model::func(qreal u, const QVector4D &r0, const QVector4D &r1, const QVector4D &r2, const QVector4D &r3)
{
    return QVector3D(
                        Model::func(u, r0.x(), r0.w(), r1.x(), r1.w(), r2.x(), r2.w(), r3.x(), r3.w()),
                        Model::func(u, r0.y(), r0.w(), r1.y(), r1.w(), r2.y(), r2.w(), r3.y(), r3.w()),
                        Model::func(u, r0.z(), r0.w(), r1.z(), r1.w(), r2.z(), r2.w(), r3.z(), r3.w())
                    );
}

qreal Model::func(qreal t, qreal r0, qreal w0, qreal r1, qreal w1, qreal r2, qreal w2, qreal r3, qreal w3)
{
    qreal first = w0 * (1 - t) * (1 - t) * (1 - t);
    qreal second = 3 * w1 * (1 - t) * (1 - t) * t;
    qreal third = 3 * w2 * (1 - t) * t * t;
    qreal fourth = w3 * t * t * t;
    return (r0 * first + r1 * second + r2 * third + r3 * fourth) / (first + second + third + fourth);
}

qreal Model::func(qreal t, qreal w0, qreal w1, qreal w2, qreal w3)
{
    return w0 * (1 - t) * (1 - t) * (1 - t) + 3 * w1 * (1 - t) * (1 - t) * t + 3 * w2 * (1 - t) * t * t + w3 * t * t * t;
}
