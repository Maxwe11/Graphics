#include "model.h"

Model::Model() : m_points(16)
{
}

QVector3D& Model::operator [] (int i)
{
    return m_points[i];
}

const QVector3D &Model::operator [](int i) const
{
    return m_points[i];
}

QVector3D& Model::operator () (int i, int j)
{
    return m_points[i * 4 + j];
}

const QVector3D &Model::operator ()(int i, int j) const
{
    return m_points[i * 4 + j];
}

QVector3D Model::func(qreal u, qreal v, const Model& m)
{
    qreal arr_u[4] = {  (2 * u * u * u - 3 * u * u + 1),
                        (-2 * u * u * u + 3 * u * u),
                        (u * u * u - 2 * u * u + u),
                        (u * u * u - u * u)
    };

    qreal arr_v[4] = {  (2 * v * v * v - 3 * v * v + 1),
                        (-2 * v * v * v + 3 * v * v),
                        (v * v * v - 2 * v * v + v),
                        (v * v * v - v * v)
    };

    qreal x1, x2, x3, x4;
    x1 = (m[0].x() * arr_u[0] + m[2].x() * arr_u[1] + m[4].x() * arr_u[2] + m[6].x() * arr_u[3]) * arr_v[0];
    x2 = (m[1].x() * arr_u[0] + m[3].x() * arr_u[1] + m[5].x() * arr_u[2] + m[7].x() * arr_u[3]) * arr_v[1];
    x3 = (m[8].x() * arr_u[0] + m[10].x() * arr_u[1]) * arr_v[2];
    x4 = (m[9].x() * arr_u[0] + m[11].x() * arr_u[1]) * arr_v[3];
    qreal y1, y2, y3, y4;
    y1 = (m[0].y() * arr_u[0] + m[2].y() * arr_u[1] + m[4].y() * arr_u[2] + m[6].y() * arr_u[3]) * arr_v[0];
    y2 = (m[1].y() * arr_u[0] + m[3].y() * arr_u[1] + m[5].y() * arr_u[2] + m[7].y() * arr_u[3]) * arr_v[1];
    y3 = (m[8].y() * arr_u[0] + m[10].y() * arr_u[1]) * arr_v[2];
    y4 = (m[9].y() * arr_u[0] + m[11].y() * arr_u[1]) * arr_v[3];
    qreal z1, z2, z3, z4;
    z1 = (m[0].z() * arr_u[0] + m[2].z() * arr_u[1] + m[4].z() * arr_u[2] + m[6].z() * arr_u[3]) * arr_v[0];
    z2 = (m[1].z() * arr_u[0] + m[3].z() * arr_u[1] + m[5].z() * arr_u[2] + m[7].z() * arr_u[3]) * arr_v[1];
    z3 = (m[8].z() * arr_u[0] + m[10].z() * arr_u[1]) * arr_v[2];
    z4 = (m[9].z() * arr_u[0] + m[11].z() * arr_u[1]) * arr_v[3];

    return QVector3D(x1 + x2 + x3 + x4, y1 + y2 + y3 + y4, z1 + z2 + z3 + z4);
}
