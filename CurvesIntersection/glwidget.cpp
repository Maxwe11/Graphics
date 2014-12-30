#include <QtCore/QDebug>
#include <GL/glu.h>

#include "glwidget.h"
#include "model.h"
#include "primitives.h"

GLWidget::GLWidget(QWidget* parent)
    : QGLWidget(QGLFormat(QGL::SingleBuffer), parent)
    , m_pmodel(0)
{}

void GLWidget::setModel(Model *ptr)
{
    m_pmodel = ptr;
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



    if (m_pmodel != 0)
    {
        glLineWidth(1.0f);
        qglColor(Qt::green);

        Model& model = *m_pmodel;

        for (int i = 0; i < 2; ++i)
        {
            if (model.crv[i].empty())
            {
                model.crv[i].push_back(model.curve[i][0]);
                for (qreal u = 0.01; u <= 1.0; u += 0.01)
                    model.crv[i].push_back(model.curve[i].getPoint(u));
            }

            for (int j = 1; j < model.crv[i].count(); ++j)
                Primitives::DrawLine(model.crv[i][j - 1].x(), model.crv[i][j - 1].y(),
                                     model.crv[i][j].x(), model.crv[i][j].y());
        }

        if (model.intersection.empty())
        {
            for (int i = 1; i < model.crv[0].count(); ++i)
            {
                for (int j = 1; j < model.crv[0].count(); ++j)
                {
                    qreal x11 = model.crv[0][i - 1].x(), x12 = model.crv[0][i].x();
                    qreal y11 = model.crv[0][i - 1].y(), y12 = model.crv[0][i].y();
                    qreal k1 = (y12 - y11) / (x12 - x11);
                    qreal b1 = y11 - (y12 - y11) * x11 / (x12 - x11);

                    qreal x21 = model.crv[1][j - 1].x(), x22 = model.crv[1][j].x();
                    qreal y21 = model.crv[1][j - 1].y(), y22 = model.crv[1][j].y();
                    qreal k2 = (y22 - y21) / (x22 - x21);
                    qreal b2 = y21 - (y22 - y21) * x21 / (x22 - x21);

                    qreal x = (b2 - b1) / (k1 - k2);

                    bool in1 = (x >= x11 && x <= x12) || (x >= x12 && x <= x11);
                    bool in2 = (x >= x21 && x <= x22) || (x >= x22 && x <= x21);

                    if (in1 && in2)
                    {
                        qreal y = k1 * x + b1;
                        model.intersection.push_back(QPointF(x, y));
                    }
                }
            }
        }

        qglColor(Qt::blue);
        for (int i = 0; i < model.intersection.count(); ++i)
            Primitives::DrawDot(model.intersection[i].x(), model.intersection[i].y(), 4.0);
    }
}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, 0.0, height, -1.0, 1.0);
}
