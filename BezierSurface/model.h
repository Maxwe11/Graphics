#ifndef MODEL_H
#define MODEL_H

#include <QtCore/QVector>
#include <QtGui/QVector3D>

class Model
{
public:
    Model();

    QVector3D& operator [] (int i);
    const QVector3D& operator [] (int i) const;
    QVector3D& operator () (int i, int j);
    const QVector3D& operator () (int i, int j) const;
public:
    static QVector3D func(qreal u, const QVector3D& r0, const QVector3D& r1, const QVector3D& r2);
    static qreal func(qreal u, qreal r0, qreal r1, qreal r2);
private:
    QVector<QVector3D> m_points;
};

#endif // MODEL_H
