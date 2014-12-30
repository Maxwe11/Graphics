#include "face.h"
#include "primitives.h"
#include "glwidget.h"
#include <QColor>
#include <QDebug>

GLWidget* Face3D::mGl = 0;

Face3D::Face3D(const QVector4D &p1, const QVector4D &p2, const QVector4D &p3)
{
    mPoints[0] = p1;
    mPoints[1] = p2;
    mPoints[2] = p3;
}

void Face3D::draw() const
{
    if (!isVisible())
        return;

    float step = 0.05f;
    for (float u = 0.0f; u <= 1.0f; u += step)
    {
        float i1 = u * mDepth[0] + (1.0 - u) * mDepth[1];
        QVector4D p1 = u * mPoints[0] + (1.0 - u) * mPoints[1];

        float i2 = u * mDepth[0] + (1.0 - u) * mDepth[2];
        QVector4D p2 = u * mPoints[0] + (1.0 - u) * mPoints[2];

        for (float w = 0.0f; w <= 1.0f; w += step)
        {
            float ii = (w * i1 + (1.0 - w) * i2);
            //qDebug() << ii;
            QVector4D pp1 = w * p1 + (1.0 - w) * p2;

            if (mGl != 0)
            {
                if (ii > 255)
                    ii = 255;
                mGl->qglColor(QColor((int)ii, (int)ii, (int)ii));
            }
            Primitives::DrawLine(pp1.x(), pp1.y(), pp1.x() + 0.01, pp1.y() + 0.01);
        }
    }
}
//    for (float u = 0.0f; u <= 1.0f; u += step)
//    {
//        float i1 = u * mDepth[0] + (1.0 - u) * mDepth[1];
//        QVector4D p1 = u * mPoints[0] + (1.0 - u) * mPoints[1];

//        for (float v = 0.0f; v <= 1.0f; v += step)
//        {
//            float i2 = v * mDepth[0] + (1.0 - v) * mDepth[2];
//            QVector4D p2 = v * mPoints[0] + (1.0 - v) * mPoints[2];

//            for (float w = 0.0f; w <= 1.0f; w += step)
//            {
//                float ii = (w * i1 + (1.0 - w) * i2);
//                qDebug() << ii;
//                QVector4D pp1 = w * p1 + (1.0 - w) * p2;

//                if (mGl != 0)
//                {
//                    if (ii > 255)
//                        ii = 255;
//                    mGl->qglColor(QColor((int)ii, (int)ii, (int)ii));
//                }
//                Primitives::DrawLine(pp1.x(), pp1.y(), pp1.x() + 0.01, pp1.y() + 0.01);
//            }
//        }
//    }
//}

void Face3D::draw(const QMatrix4x4 &projection) const
{
    if (!isVisible())
        return;

    auto p1 = projection.map(mPoints[0]);
    auto p2 = projection.map(mPoints[1]);
    auto p3 = projection.map(mPoints[2]);

    Primitives::DrawLine(p1.x(), p1.y(), p2.x(), p2.y());
    Primitives::DrawLine(p1.x(), p1.y(), p3.x(), p3.y());
    Primitives::DrawLine(p3.x(), p3.y(), p2.x(), p2.y());
}

void Face3D::drawNormal(const QMatrix4x4 &projection) const
{
    if (!isVisible())
        return;

    QVector4D pp1((mPoints[0].x() + mPoints[1].x() + mPoints[2].x()) / 3.0,
                  (mPoints[0].y() + mPoints[1].y() + mPoints[2].y()) / 3.0,
                  (mPoints[0].z() + mPoints[1].z() + mPoints[2].z()) / 3.0,
                  1.0f);

    QVector4D ap1 = mPoints[1] - pp1;
    QVector4D ap2 = mPoints[2] - pp1;
    QVector4D pp2;

    pp2.setX(ap1.y() * ap2.z() - ap1.z() * ap2.y());
    pp2.setY(ap1.z() * ap2.x() - ap1.x() * ap2.z());
    pp2.setZ(ap1.x() * ap2.y() - ap1.y() * ap2.x());

    auto length = pp2.length();
    pp2.setX(pp1.x() + pp2.x() / length);
    pp2.setY(pp1.y() + pp2.y() / length);
    pp2.setZ(pp1.z() + pp2.z() / length);

    pp1 = projection.map(pp1);
    pp2 = projection.map(pp2);
    Primitives::DrawLine(pp1.x(), pp1.y(), pp2.x(), pp2.y());
}

void Face3D::transform(const QMatrix4x4 &transformation)
{
    for (int i = 0; i < 3; ++i)
        mPoints[i] = transformation.map(mPoints[i]);
}

QVector4D Face3D::buildNormal(const QVector4D& p) const
{
    QVector4D pp1;

    if (p.isNull())
    {
        pp1 = QVector4D{(mPoints[0].x() + mPoints[1].x() + mPoints[2].x()) / 3.0f,
                        (mPoints[0].y() + mPoints[1].y() + mPoints[2].y()) / 3.0f,
                        (mPoints[0].z() + mPoints[1].z() + mPoints[2].z()) / 3.0f,
                        1.0f};
    }
    else
    {
        pp1 = p;
    }

    QVector4D ap1 = mPoints[1] - pp1;
    QVector4D ap2 = mPoints[2] - pp1;
    QVector4D pp2;

    pp2.setX(ap1.y() * ap2.z() - ap1.z() * ap2.y());
    pp2.setY(ap1.z() * ap2.x() - ap1.x() * ap2.z());
    pp2.setZ(ap1.x() * ap2.y() - ap1.y() * ap2.x());

    auto length = pp2.length();
    pp2.setX(pp2.x() / length);
    pp2.setY(pp2.y() / length);
    pp2.setZ(pp2.z() / length);
    float d = -(pp1.x() * pp2.x() + pp1.y() * pp2.y() + pp1.z() * pp2.z());
    return QVector4D(pp2.x(), pp2.y(), pp2.z(), d);
}
