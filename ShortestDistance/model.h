#ifndef MODEL_H
#define MODEL_H

#include "bezier.h"
#include <QtCore/QVector>
#include <QtCore/QPointF>

struct Model
{
    Model();
public:
    Bezier<3> curve[2];
    QVector<QPointF> crv[2];
};

#endif // MODEL_H
