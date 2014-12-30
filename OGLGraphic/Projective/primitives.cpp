#include "primitives.h"

const double Primitives::Pi = 3.1415926535897932;

//void Primitives::DrawDot(GLfloat x, GLfloat y, GLfloat w)
//{
//    glPointSize(w);
//    glBegin(GL_POINTS);
//      glVertex2f(x, y);
//    glEnd();
//}

void Primitives::DrawLine(const QPointF &p1, const QPointF &p2, const Matrix &m)
{
    static QPointF n, k;
    n = m.map(p1);
    k = m.map(p2);
    glBegin(GL_LINES);
      glVertex2d(n.x(), n.y());
      glVertex2d(k.x(), k.y());
    glEnd();
}

void Primitives::DrawArc(const QPointF &p, GLfloat radius, GLfloat start_angle, GLfloat end_angle, const Matrix& m)
{
    start_angle *= Pi / 180.0;
    end_angle   *= Pi / 180.0;

    static QPointF p1, p2;

    p1.setX(p.x() + radius * qCos(start_angle));
    p1.setY(p.y() + radius * qSin(start_angle));

    GLfloat step = (end_angle - start_angle) / 24.0f;
    end_angle += step;
    for (GLfloat i = start_angle + step; i < end_angle; i += step)
    {
        p2.setX(p.x() + radius * qCos(i));
        p2.setY(p.y() + radius * qSin(i));

        DrawLine(p1, p2, m);

        p1 = p2;
    }
}

void Primitives::DrawCircle(const QPointF &p, GLfloat radius, const Matrix& m)
{
    DrawArc(p, radius, 0.0f, 360.0f, m);
}

float Primitives::LenghtBetweenPoints(float x1, float y1, float x2, float y2)
{
    return (float)qSqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double Primitives::AngleLine(float x1, float y1, float x2, float y2)
{
    return qAtan((y2 - y1) / (x2 - x1));
}

double Primitives::RadianToDegree(double val)
{
    return val * 180.0 / Pi;
}

double Primitives::DegreeToRadian(double val)
{
    return val * Pi / 180.0;
}
