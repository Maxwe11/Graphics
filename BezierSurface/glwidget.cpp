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

    qglColor(Qt::red);
    Primitives::DrawLine(0.0, 0.0, 0.0, 300.0, 0.0, 0.0);

    qglColor(Qt::blue);
    Primitives::DrawLine(0.0, 0.0, 0.0, 0.0, 300.0, 0.0);

    qglColor(Qt::green);
    Primitives::DrawLine(0.0, 0.0, 0.0, 0.0, 0.0, 300.0);

    glLineWidth(2.0f);
    qglColor(Qt::yellow);

    int counter = 0;
    Model& model = *m_model;
    QVector3D prev(model[0]), next;

    for (qreal step = 0.02, u = step, end = 1.0 + 2 * step; u <= end; u += step, ++counter)
    {
        next = Model::func(u, model[0], model[3], model[6]);
        Primitives::DrawLine(prev.x(), prev.y(), prev.z(), next.x(), next.y(), next.z());

        if (counter % 10 == 0)
        {
            QVector3D innerPrev(prev), innerNext;

            for (qreal v = step; v <= 1.0; v += step)
            {
                innerNext = Model::func(u,
                                        Model::func(v, model(0, 0), model(0, 1), model(0, 2)),
                                        Model::func(v, model(1, 0), model(1, 1), model(1, 2)),
                                        Model::func(v, model(2, 0), model(2, 1), model(2, 2))
                                        );

                Primitives::DrawLine(innerPrev.x(), innerPrev.y(), innerPrev.z(),
                                     innerNext.x(), innerNext.y(), innerNext.z());
                innerPrev = innerNext;
            }
        }

        prev = next;
    }

    QVector3D curr0, curr1, curr2;
    for (double step = 0.02, v = 10 * step; v <= 1 + 5 * step; v += 10 * step)
    {
        curr0 = Model::func(v, model(0, 0), model(0, 1), model(0, 2));
        curr1 = Model::func(v, model(1, 0), model(1, 1), model(1, 2));
        curr2 = Model::func(v, model(2, 0), model(2, 1), model(2, 2));
        QVector3D innerPrev = Model::func(0, curr0, curr1, curr2), innerNext;
        for (double u = step; u <= 1 + 2 * step; u += step)
        {
            innerNext = Model::func(u, curr0, curr1, curr2);
            Primitives::DrawLine(innerPrev.x(), innerPrev.y(), innerPrev.z(),
                                 innerNext.x(), innerNext.y(), innerNext.z());
            innerPrev = innerNext;
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
