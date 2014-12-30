#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <QtOpenGL>
#include <cmath>

class Matrix;

class Primitives {
public:
    static const double Pi;
public:
    static void DrawDot(GLfloat x, GLfloat y, GLfloat w);
    static void DrawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, const Matrix&);
    static void DrawArc(GLfloat x, GLfloat y, GLfloat radius, GLfloat start_angle, GLfloat end_angle, const Matrix&);
    static void DrawCircle(GLfloat x, GLfloat y, GLfloat radius, const Matrix&);

    static float LenghtBetweenPoints(float x1, float y1, float x2, float y2);
    static double AngleLine(float x1, float y1, float x2, float y2);
    static double RadianToDegree(double);
    static double DegreeToRadian(double);
};

#endif // PRIMITIVES_H
