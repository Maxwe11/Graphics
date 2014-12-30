#include "glwidget.h"
#include "primitives.h"
#include "cartesianleaf.h"

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::DoubleBuffer), parent)
    , grid_step(20)
    , m_matr()
    , flower(false)
{
    leaf = new CartesianLeaf(this);
    QObject::connect(leaf, SIGNAL(Update()), this, SLOT(updateGL()));
}

GLWidget::~GLWidget()
{
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

    glLineWidth(1.0f);
    qglColor(Qt::cyan);
    DrawGrid();

    glLineWidth(1.2f);
    qglColor(Qt::black);
    DrawAxis();

    glLineWidth(2.0f);
    if (flower == false)
    {
        qglColor(Qt::blue);
        leaf->drawLeaf(m_matr);
        qglColor(Qt::red);
        leaf->drawAsymptote(m_matr);
    }
    else
    {
        qglColor(Qt::green);
        leaf->drawJasmine(m_matr);
    }
}

void GLWidget::resizeGL(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    QRectF rec(-width / 2.0, height / 2.0, (qreal)width, -(qreal)height);
    glOrtho(rec.left(), rec.right(), rec.bottom(), rec.top(), -1.0, 1.0);
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void GLWidget::DrawGrid()
{
    static int delta;
    static qreal tmp;
    static QPointF p1;
    static QPointF p2;
    static QMatrix m;

    delta = 0.5 / grid_step * width();
    p1.setY(-0.5 * height());
    p2.setY( 0.5 * height());

    for (int i = -delta; i <= delta; ++i)
    {
        tmp = qreal(i * grid_step);
        p1.setX(tmp);
        p2.setX(tmp);
        Primitives::DrawLine(p1, p2, m);
    }

    delta = 0.5 / grid_step * height();
    p1.setX(-0.5 * width());
    p2.setX( 0.5 * width());

    for (int i = - delta; i <= delta; ++i)
    {
        tmp = qreal(i * grid_step);
        p1.setY(tmp);
        p2.setY(tmp);
        Primitives::DrawLine(p1, p2, m);
    }
}

void GLWidget::DrawAxis()
{
    static QMatrix m;
    static QPointF p1;
    static QPointF p2;

    p1.setX(0.0);  p1.setY( 0.5 * height());
    p2.setX(0.0);  p2.setY(-0.5 * height());
    Primitives::DrawLine(p1, p2, m);
    p1.setX( 0.5 * width());  p1.setY(0.0);
    p2.setX(-0.5 * width());  p2.setY(0.0);
    Primitives::DrawLine(p1, p2, m);
}

void GLWidget::TranslateX(int val)
{
    m_matr.setMatrix(m_matr.m11(), m_matr.m12(), m_matr.m21(), m_matr.m22(), val * grid_step, m_matr.dy());
    emit this->updateGL();
}

void GLWidget::TranslateY(int val)
{
    m_matr.setMatrix(m_matr.m11(), m_matr.m12(), m_matr.m21(), m_matr.m22(), m_matr.dx(), val * grid_step);
    emit this->updateGL();
}

void GLWidget::Rotate(int angle)
{
    qreal i = Primitives::DegreeToRadian(static_cast<qreal>(angle));
    qreal t1 = qCos(i), t2 = qSin(i);
    m_matr.setMatrix(t1, t2, -t2, t1, m_matr.dx(), m_matr.dy());
    emit this->updateGL();
}

void GLWidget::showFlower(bool val)
{
    this->flower = val;
    emit this->updateGL();
}
