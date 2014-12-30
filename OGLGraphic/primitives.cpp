#include "primitives.h"
#include "matrix.h"

 const double Primitives::Pi = 3.1415926535897932;

void Primitives::DrawDot(GLfloat x, GLfloat y, GLfloat w)
{
    glPointSize(w);
    glBegin(GL_POINTS);
      glVertex2f(x, y);
    glEnd();
}

void Primitives::DrawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, const Matrix& m)
{
    QPointF p1(x1, y1), p2(x2, y2);
    p1 = m.map(p1);
    p2 = m.map(p2);
    glBegin(GL_LINES);
      glVertex2d(p1.x(), p1.y());
      glVertex2d(p2.x(), p2.y());
    glEnd();
}

void Primitives::DrawArc(GLfloat x, GLfloat y, GLfloat radius, GLfloat start_angle, GLfloat end_angle, const Matrix& m)
{
    start_angle *= Pi / 180.0;
    end_angle   *= Pi / 180.0;

    GLfloat start_x = x + radius * std::cos(start_angle);
    GLfloat start_y = y + radius * std::sin(start_angle);

    GLfloat step = (end_angle - start_angle) / 24.0f;
    end_angle += step;
    for (GLfloat i = start_angle + step; i < end_angle; i += step)
    {
        GLfloat new_x = x + (radius * std::cos(i));
        GLfloat new_y = y + (radius * std::sin(i));

        DrawLine(start_x, start_y, new_x, new_y, m);

        start_x = new_x;
        start_y = new_y;
    }
}

void Primitives::DrawCircle(GLfloat x, GLfloat y, GLfloat radius, const Matrix& m)
{
    DrawArc(x, y, radius, 0.0f, 360.0f, m);
}

float Primitives::LenghtBetweenPoints(float x1, float y1, float x2, float y2)
{
    return (float)std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double Primitives::AngleLine(float x1, float y1, float x2, float y2)
{
    return std::atan((y2 - y1) / (x2 - x1));
}

double Primitives::RadianToDegree(double val)
{
    return val * 180.0 / Pi;
}

double Primitives::DegreeToRadian(double val)
{
    return val * Pi / 180.0;
}
