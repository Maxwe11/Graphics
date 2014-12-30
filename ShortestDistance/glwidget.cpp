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

        QLineF line(model.crv[0][0], model.crv[1][0]);
        qreal length = line.length();
        for (int i = 0; i < model.crv[0].count(); ++i)
        {
            for (int j = 0; j < model.crv[1].count(); ++j)
            {
                QLineF line1(model.crv[0][i], model.crv[1][j]);
                qreal len = line1.length();
                if (len < length)
                {
                    line = line1;
                    length = len;
                }
            }
        }

        qglColor(Qt::red);
        Primitives::DrawLine(line.x1(), line.y1(), line.x2(), line.y2());
    }
}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, 0.0, height, -1.0, 1.0);
}
