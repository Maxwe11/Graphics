#include "glwidget.h"
#include "primitives.h"


GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SingleBuffer), parent)
    , grid_step(20)
    , m_matr(
              20.0 * grid_step,  1.0 * grid_step,    5.0,
               1.0 * grid_step, 20.0 * grid_step,    5.0,
                           0.0,              0.0, 1000.0
            )
    , d_matr(m_matr)
{
    this->det = new Detail();
}

GLWidget::~GLWidget()
{
    delete this->det;
}

void GLWidget::initializeGL()
{
    glClearColor(10.0, 10.0, 100.0, 0.0);

    glEnable(GL_LINE_SMOOTH);

//    QPainter p(this);
//    p.setRenderHint(QPainter::HighQualityAntialiasing);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glLineWidth(1.0f);
    qglColor(Qt::blue);
    DrawGrid();

    glLineWidth(1.0f);
    qglColor(Qt::red);
    DrawAxis();

    glLineWidth(3.0f);
    qglColor(Qt::yellow);
    this->det->DrawDetail(d_matr, false);
}

void GLWidget::resizeGL(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    QRectF rec(-width / 2.0 + 180.0, height / 2.0 + 150.0, (qreal)width, -(qreal)height);
    glOrtho(rec.left(), rec.right(), rec.bottom(), rec.top(), -1.0, 1.0);
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void GLWidget::XxChanged(int val)
{
    this->m_matr.M11() = val * grid_step;
    this->d_matr.M11() = val * grid_step;
    emit this->updateGL();
}

void GLWidget::XyChanged(int val)
{
    this->m_matr.M21() = val * grid_step;
    this->d_matr.M21() = val * grid_step;
    emit this->updateGL();
}

void GLWidget::YxChanged(int val)
{
    this->m_matr.M12() = val * grid_step;
    this->d_matr.M12() = val * grid_step;
    emit this->updateGL();
}

void GLWidget::YyChanged(int val)
{
    this->m_matr.M22() = val * grid_step;
    this->d_matr.M22() = val * grid_step;
    emit this->updateGL();
}

void GLWidget::WxChanged(int val)
{
    this->m_matr.M13() = val;
    this->d_matr.M13() = val;
    emit this->updateGL();
}

void GLWidget::WyChanged(int val)
{
    this->m_matr.M23() = val;
    this->d_matr.M23() = val;
    emit this->updateGL();
}

void GLWidget::W0Changed(int val)
{
    this->m_matr.M33() = val;
    this->d_matr.M33() = val;
    emit this->updateGL();
}

void GLWidget::X0Changed(int val)
{
    this->d_matr.M31() = val * grid_step;
    emit this->updateGL();
}

void GLWidget::Y0Changed(int val)
{
    this->d_matr.M32() = val * grid_step;
    emit this->updateGL();
}

void GLWidget::DrawGrid()
{
    static qreal tmp;
    static QPointF p1, p2;

    p1.setY(0.0);
    p2.setY(m_matr.M22());

    for (int i = 1, s = (int)m_matr.M11() / grid_step; i<= s; ++i)
    {
        tmp = i * grid_step;
        p1.setX(tmp);
        p2.setX(tmp);
        Primitives::DrawLine(p1, p2, m_matr);
    }

    p1.setX(0.0);
    p2.setX(m_matr.M11());

    for (int i = 1, s = (int)m_matr.M22() / grid_step; i<= s; ++i)
    {
        tmp = i * grid_step;
        p1.setY(tmp);
        p2.setY(tmp);
        Primitives::DrawLine(p1, p2, m_matr);
    }
}

void GLWidget::DrawAxis()
{
    Primitives::DrawLine(QPointF(0.0, 0.0), QPointF(0.0, m_matr.M22()), m_matr);
    Primitives::DrawLine(QPointF(0.0, 0.0), QPointF(m_matr.M11(), 0.0), m_matr);
}
