#include <QDebug>
#include <GL/glu.h>

#include "glwidget.h"
#include "primitives.h"
#include "model.h"

GLWidget::GLWidget(QWidget* parent)
    : QGLWidget(QGLFormat(QGL::SingleBuffer), parent)
    , m_model(0)
{}

void GLWidget::setModel(Model* m)
{
    m_model = m;
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

    glLineWidth(1.0f);

    qglColor(Qt::yellow);
    Primitives::DrawLine(0.0, 0.0, 0.0, 300.0, 0.0, 0.0);

    qglColor(Qt::blue);
    Primitives::DrawLine(0.0, 0.0, 0.0, 0.0, 300.0, 0.0);

    qglColor(Qt::green);
    Primitives::DrawLine(0.0, 0.0, 0.0, 0.0, 0.0, 300.0);

    glLineWidth(2.0f);
    qglColor(Qt::red);

    QVector3D P0, P1;
    float h = 0.05f;
    //u = const
    for (float u = 0.00f; u <= 1.0f + h; u += h)
    {
        P0 = Model::func(u, 0.0, *m_model);
        for (float v = h; v < 1.0f + h; v += h)
        {
            P1 = Model::func(u, v, *m_model);
            Primitives::DrawLine(P0.x(), P0.y(), P0.z(), P1.x(), P1.y(), P1.z());
            P0 = P1;
        }
    }
    //v = const
    for (float v = 0.00f; v <= 1.0f + h; v += h)
    {
        P0 = Model::func(0.0, v, *m_model);
        for (float u = h; u < 1.0f + h; u += h)
        {
            P1 = Model::func(u, v, *m_model);
            Primitives::DrawLine(P0.x(), P0.y(), P0.z(), P1.x(), P1.y(), P1.z());
            P0 = P1;
        }
    }
}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    qreal aspect = width / height, left = -250.0, right = 250.0;
    glOrtho(left * aspect, right * aspect, left, right, left, right);
    gluLookAt(-5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
