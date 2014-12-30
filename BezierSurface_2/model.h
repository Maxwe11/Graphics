#ifndef MODEL_H
#define MODEL_H

#include <QtCore/QVector>
#include <QtGui/QVector3D>
#include <QtGui/QVector4D>

class Model
{
public:
    Model();

    QVector4D& operator [] (int i);
    const QVector4D& operator [] (int i) const;
    QVector4D& operator () (int i, int j);
    const QVector4D& operator () (int i, int j) const;
public:
    static QVector3D func(qreal u, const QVector4D& r0, const QVector4D& r1, const QVector4D& r2, const QVector4D& r3);
    static qreal func(qreal u, qreal r0, qreal w0, qreal r1, qreal w1, qreal r2, qreal w2, qreal r3, qreal w3);
    static qreal func(qreal t, qreal w0, qreal w1, qreal w2, qreal w3);
private:
    QVector<QVector4D> m_points;
};

#endif // MODEL_H
