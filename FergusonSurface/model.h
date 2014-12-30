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
    static QVector3D func(qreal u, qreal v, const Model &m);
private:
    QVector<QVector3D> m_points;
};

#endif // MODEL_H
