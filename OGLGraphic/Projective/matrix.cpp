#include <QPointF>

#include "matrix.h"

Matrix::Matrix(double v11, double v12, double v13,
               double v21, double v22, double v23,
               double v31, double v32, double v33)
{
    m11 = v11; m12 = v12; m13 = v13;
    m21 = v21; m22 = v22; m23 = v23;
    m31 = v31; m32 = v32; m33 = v33;
}

QPointF Matrix::map(const QPointF& p) const
{
    return QPointF((m31 * m33 + p.x() * m11 * m13 + p.y() * m21 * m23) / (m33 + p.x() * m13 + p.y() * m23),
                   (m32 * m33 + p.x() * m12 * m13 + p.y() * m22 * m23) / (m33 + p.x() * m13 + p.y() * m23));
//    return QPointF(p.x() * m11 + p.y() * m21 + m31, p.x() * m12 + p.y() * m22 + m32);
}

void Matrix::setMatrix(double v11, double v12, double v13,
                       double v21, double v22, double v23,
                       double v31, double v32, double v33)
{
    m11 = v11; m12 = v12; m13 = v13;
    m21 = v21; m22 = v22; m23 = v23;
    m31 = v31; m32 = v32; m33 = v33;
}

void Matrix::reset()
{
    m11 = 1.0; m12 = 0.0; m13 = 0.0;
    m21 = 0.0; m22 = 1.0; m23 = 0.0;
    m31 = 0.0; m32 = 0.0; m33 = 1.0;
}
