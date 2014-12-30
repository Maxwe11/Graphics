#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <QtOpenGL>

#include "matrix.h"

class Primitives {
public:
    static const double Pi;
public:
//    static void DrawDot(GLfloat x, GLfloat y, GLfloat w);
    static void DrawLine(const QPointF& p1, const QPointF& p2,const Matrix& m);
    static void DrawArc(const QPointF& p, GLfloat radius, GLfloat start_angle, GLfloat end_angle, const Matrix&);
    static void DrawCircle(const QPointF& p, GLfloat radius, const Matrix&);

    static float LenghtBetweenPoints(float x1, float y1, float x2, float y2);
    static double AngleLine(float x1, float y1, float x2, float y2);
    static double RadianToDegree(double);
    static double DegreeToRadian(double);
};

#endif // PRIMITIVES_H
