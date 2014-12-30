#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <QtOpenGL>

class Primitives {
public:
    static constexpr double Pi = 3.1415926535897932;
public:
    static void DrawDot(GLfloat x, GLfloat y, GLfloat w);
    static void DrawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
    static void DrawLine(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2);
    static void DrawArc(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLfloat start_angle, GLfloat end_angle);
    static void DrawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius);

//    static float LenghtBetweenPoints(float x1, float y1, float x2, float y2);
//    static double AngleLine(float x1, float y1, float x2, float y2);
//    static double RadianToDegree(double);
//    static double DegreeToRadian(double);
};

#endif // PRIMITIVES_H
