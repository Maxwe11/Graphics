#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <QtOpenGL>

class Primitives {
public:
    static const double Pi = 3.1415926535897932;
public:
    static void DrawDot(GLfloat x, GLfloat y, GLfloat w);
    static void DrawLine(const QPointF& p1, const QPointF& p2,const QMatrix& m);
//    static void DrawArc(GLfloat x, GLfloat y, GLfloat radius, GLfloat start_angle, GLfloat end_angle, const Matrix&);
//    static void DrawCircle(GLfloat x, GLfloat y, GLfloat radius, const Matrix&);

    static double LenghtBetweenPoints(const QPointF& p1, const QPointF& p2);
    static double AngleLine(float x1, float y1, float x2, float y2);
    static double RadianToDegree(double);
    static double DegreeToRadian(double);
};

#endif // PRIMITIVES_H
