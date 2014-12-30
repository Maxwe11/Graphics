#include <QDebug>
#include <GL/glu.h>

#include "glwidget.h"
#include "primitives.h"

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SingleBuffer), parent)
    , x_transl(0), y_transl(0), z_transl(0)
    , x_rot(0), y_rot(0), z_rot(0)
    , duck_u_transl(0.0), duck_v_transl(0.0)
    , param(4.0f)
{
    duckPos << (QVector< QPointF >() << QPointF(-128.0, -123) << QPointF(-185.0, -51) << QPointF(-185.0, -41) << QPointF(-272.0, -33))
            << (QVector< QPointF >() << QPointF(-272.0, -33)  << QPointF(-189.0, -33) << QPointF(-182.0, -23) << QPointF(-193.0, 38))
            << (QVector< QPointF >() << QPointF(-193.0, 38)   << QPointF(-170.0, 214) << QPointF(10.0, 293)   << QPointF(95.0, 109))
            << (QVector< QPointF >() << QPointF(95.0, 109)    << QPointF(81.0, 73)    << QPointF(58.0, 110)   << QPointF(19.0, 117))
            << (QVector< QPointF >() << QPointF(19.0, 117)    << QPointF(2.0, 137)    << QPointF(-22.0, 151)  << QPointF(-42.0, 146))
            << (QVector< QPointF >() << QPointF(-42.0, 146)   << QPointF(-17.0, 101)  << QPointF(-100.0, 163) << QPointF(-133.0, 100))
            << (QVector< QPointF >() << QPointF(-133.0, 100)  << QPointF(-114.0, 117) << QPointF(-92.0, 148)  << QPointF(-9.0, 105))
            << (QVector< QPointF >() << QPointF(-9.0, 105)    << QPointF(-12.0, 118)  << QPointF(-2.0, 128)   << QPointF(57.0, 99))
            << (QVector< QPointF >() << QPointF(57.0, 99)     << QPointF(68.0, 90)    << QPointF(44.0, 107)   << QPointF(79.0, 81))
            << (QVector< QPointF >() << QPointF(79.0, 81)     << QPointF(72.0, 67)    << QPointF(57.0, 56)    << QPointF(50.0, 34))
            << (QVector< QPointF >() << QPointF(50.0, 34)     << QPointF(117.0, 18)   << QPointF(245.0, -22)  << QPointF(273.0, 22))
            << (QVector< QPointF >() << QPointF(273.0, 22)    << QPointF(260.0, 48)   << QPointF(211.0, 54)   << QPointF(179.0, 55))
            << (QVector< QPointF >() << QPointF(179.0, 55)    << QPointF(155.0, 68)   << QPointF(128.0, 85)   << QPointF(95.0, 109))
            << (QVector< QPointF >() << QPointF(95.0, 109)    << QPointF(84.0, 82)    << QPointF(68.0, 58)    << QPointF(48.0, 34))
            << (QVector< QPointF >() << QPointF(48.0, 34)     << QPointF(23.0, 33)    << QPointF(-97.0, 45)   << QPointF(68.0, -67))
            << (QVector< QPointF >() << QPointF(68.0, -67)    << QPointF(112.0, -114) << QPointF(147.0, -166) << QPointF(-128.0, -123));

    for (QVector< QVector< QPointF > >::iterator it = duckPos.begin(); it != duckPos.end(); ++it)
    {
        for (QVector< QPointF >::iterator i = it->begin(); i != it->end(); ++i)
            i->setY(i->y() + 330.0);
    }
}

GLWidget::~GLWidget()
{
    qDebug() << "GLWidget destr called";
}

void GLWidget::initializeGL()
{
    qglClearColor(Qt::white);
    glEnable(GL_LINE_SMOOTH_HINT);
    glEnable(GL_POINT_SMOOTH_HINT);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    qglColor(Qt::red);
    Primitives::DrawLine(-12.0, 0.0, 0.0, 12.0, 0.0, 0.0);

    qglColor(Qt::blue);
    Primitives::DrawLine(0.0, -12.0, 0.0, 0.0, 12.0, 0.0);

    qglColor(Qt::green);
    Primitives::DrawLine(0.0, 0.0, -18.0, 0.0, 0.0, 18.0);

    qglColor(Qt::black);

    glLineWidth(1.0f);

    glPushMatrix();

    glRotatef(GLfloat(x_rot), 1.0f, 0.0f, 0.0f);
    glRotatef(GLfloat(y_rot), 0.0f, 1.0f, 0.0f);
    glRotatef(GLfloat(z_rot), 0.0f, 0.0f, 1.0f);

    glTranslatef(GLfloat(x_transl), GLfloat(y_transl), GLfloat(z_transl));

    for (qreal u = -1.57; u <= 1.57; u += 0.3)
    {
        for (qreal v = 0.0; v <= 6.28; v += 0.01)
        {
            qreal z = param * qCos(v), z1 = param * qCos(v + 0.01);
            if (z > 0.5 * param)
                Primitives::DrawLine(param * qSin(v) * qCos(u), param * qSin(v) * qSin(u), z + 2.5 * param * qPow(z / param - 0.5, 2.0),
                                 param * qSin(v+0.01) * qCos(u), param * qSin(v+0.01) * qSin(u), z1 + 2.5 * param * qPow(z1 / param - 0.5, 2.0));
            else
                Primitives::DrawLine(param * qSin(v) * qCos(u), param * qSin(v) * qSin(u), z,
                                 param * qSin(v+0.01) * qCos(u), param * qSin(v+0.01) * qSin(u), z1);

//            Primitives::DrawLine(param * qSin(v) * qCos(u), param * qSin(v) * qSin(u),
//                                 param * qSin(v+0.01) * qCos(u), param * qSin(v+0.01) * qSin(u));
        }
    }

    for (qreal v = 0.0; v <= 6.28; v += 0.4)
    {
        qreal z = param * qCos(v);
        if (z > 0.5 * param)
            z += 2.5 * param * qPow(z / param - 0.5, 2.0);

        for (qreal u = 0.0; u <= 6.28; u += 0.01)
        {
            Primitives::DrawLine(param * qSin(v) * qCos(u), param * qSin(v) * qSin(u), z,
                             param * qSin(v) * qCos(u + 0.01), param * qSin(v) * qSin(u + 0.01), z);
//            Primitives::DrawLine(param * qSin(v) * qCos(u), param * qSin(v) * qSin(u),
//                                 param * qSin(v) * qCos(u + 0.01), param * qSin(v) * qSin(u + 0.01));
        }
    }

    qglColor(Qt::red);
    glLineWidth(1.5f);
    static QPointF t1, t2;
    for (int i = 0; i < duckPos.size(); ++i)
    {
        t1 = duckPos[i][0];
        for (qreal u = 0.01; u <= 1.0; u += 0.01)
        {
            t2 = duckPos[i][0] * qPow(1.0 - u, 3.0) + duckPos[i][1] * 3 * qPow(1.0 - u, 2.0) * u +
                 duckPos[i][2] * 3 * (1.0 - u) * u * u + duckPos[i][3] * u * u * u;

            QPointF p1(t1.x() * M_PI / 900.0, t1.y() * M_PI / 1800.0), p2(t2.x() * M_PI / 900.0, t2.y() * M_PI / 1800.0);
            qreal z = param * qCos(p1.y() + duck_v_transl), z1 = param * qCos(p2.y() + duck_v_transl);
            if (z > 0.5 * param)
            {
                 z += 2.5 * param * qPow(z / param - 0.5, 2.0);
                 z1 += 2.5 * param * qPow(z1 / param - 0.5, 2.0);
            }
            Primitives::DrawLine(param * qSin(p1.y() + duck_v_transl) * qCos(p1.x() + duck_u_transl), param * qSin(p1.y() + duck_v_transl) * qSin(p1.x() + duck_u_transl), z,
                                param * qSin(p2.y() + duck_v_transl) * qCos(p2.x() + duck_u_transl), param * qSin(p2.y() + duck_v_transl) * qSin(p2.x() + duck_u_transl), z1);

            t1 = t2;
        }
    }

    glPopMatrix();
}

void GLWidget::resizeGL(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-12.0, 12.0, -12.0, 12.0, -20.0, 20.0);
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void GLWidget::translateX(int val)
{
    this->x_transl = val;
    this->updateGL();
}

void GLWidget::translateY(int val)
{
    this->y_transl = val;
    this->updateGL();
}

void GLWidget::translateZ(int val)
{
    this->z_transl = val;
    this->updateGL();
}

void GLWidget::rotateX(int val)
{
    this->x_rot = val;
    this->updateGL();
}

void GLWidget::rotateY(int val)
{
    this->y_rot = val;
    this->updateGL();
}

void GLWidget::rotateZ(int val)
{
    this->z_rot = val;
    this->updateGL();
}

void GLWidget::changeParam(double val)
{
    this->param = static_cast<float>(val);
    this->updateGL();
}

void GLWidget::translateU(double val)
{
    this->duck_u_transl = static_cast<float>(val);
    this->updateGL();
}

void GLWidget::translateV(double val)
{
    this->duck_v_transl = static_cast<float>(val);
    this->updateGL();
}
