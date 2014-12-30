#include <QDebug>

#include <GL/gl.h>
#include <GL/glu.h>
#include "glwidget.h"
#include "primitives.h"

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SingleBuffer), parent)
    , x_transl(0), y_transl(0), z_transl(0)
    , x_rot(0), y_rot(0), z_rot(0)
    , param(0.5f)
{
}

GLWidget::~GLWidget()
{
    qDebug() << "GLWidget destr called";
}

void GLWidget::initializeGL()
{
    qglClearColor(Qt::black);
    glEnable(GL_LINE_SMOOTH_HINT);
    glEnable(GL_POINT_SMOOTH_HINT);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    qglColor(Qt::red);
    Primitives::DrawLine(-9.0, 0.0, 0.0, 9.0, 0.0, 0.0);

    qglColor(Qt::blue);
    Primitives::DrawLine(0.0, -9.0, 0.0, 0.0, 9.0, 0.0);

    qglColor(Qt::green);
    Primitives::DrawLine(0.0, 0.0, -9.0, 0.0, 0.0, 9.0);

    qglColor(Qt::white);

    glPushMatrix();

    glRotatef(GLfloat(x_rot), 1.0f, 0.0f, 0.0f);
    glRotatef(GLfloat(y_rot), 0.0f, 1.0f, 0.0f);
    glRotatef(GLfloat(z_rot), 0.0f, 0.0f, 1.0f);

    glTranslatef(GLfloat(x_transl), GLfloat(y_transl), GLfloat(z_transl));

    for (GLfloat i = 0.0f, w = 6.0f; i < 2.5f; i += 0.5f, w -= 0.5)
    {
        Primitives::DrawLine(i, 2.0f  * i * param, i, w, 2.0f  * i * param, i);
        Primitives::DrawLine(i, 2.0f  * i * param, i, i, 2.0f  * i * param, w);
        Primitives::DrawLine(w, 2.0f  * i * param, i, w, 2.0f  * i * param, w);
        Primitives::DrawLine(i, 2.0f  * i * param, w, w, 2.0f  * i * param, w);
    }

    Primitives::DrawCircle(3.0f, 3.0f, 4.0f * param, qSqrt(0.8));

    Primitives::DrawLine(0.0f, 0.0f, 0.0f, 2.0f, 4.0f * param, 2.0f);
    Primitives::DrawLine(6.0f, 0.0f, 0.0f, 4.0f, 4.0f * param, 2.0f);
    Primitives::DrawLine(6.0f, 0.0f, 6.0f, 4.0f, 4.0f * param, 4.0f);
    Primitives::DrawLine(0.0f, 0.0f, 6.0f, 2.0f, 4.0f * param, 4.0f);

//    for (
//            GLfloat i = 0.0f, j = 6.28f / 36, x1, y1, x2, y2;
//            i <= 6.28f;
//            i += j
//        )
//    {
//        x1 = 2.0f * qCos(i), y1 = 2.0f * qSin(i);
//        x2 = 2.0f * qCos(i + j), y2 = 2.0f * qSin(i + j);
//        Primitives::DrawLine(x1, 0.0f, y1, x2, 0.0f, y2);
//        Primitives::DrawLine(x1 * 1.3, 6.0f, y1 * 1.3, x2 * 1.3, 6.0f, y2 * 1.3);
//        Primitives::DrawLine(x1, 0.0f, y1, x1 * 1.3, 6.0f, y1 * 1.3);
//    }

    glPopMatrix();
}

void GLWidget::resizeGL(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -20.0, 20.0);
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //1.0, 1.5, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0
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
