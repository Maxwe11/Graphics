#include <QtOpenGL/QtOpenGL>
#include <cmath>

#include "scenewidget.h"
#include "primitives.h"
#include "detail.h"
#include "matrix.h"

SceneWidget::SceneWidget(QWidget* parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
    , rect(QRectF(QPointF(-350.0, 240.0), QSizeF(700.0, -480.0)))
    , bmatr()
    , dmatr()
    , transl()
    , dcenter()
    , show_points(false)
    , angle(0.0f)
    , scn_axis(false)
    , grid_step(20)
    , cur_tr(1)
{
    this->detail = new Detail();
}

SceneWidget::~SceneWidget()
{
    delete detail;
}

void SceneWidget::initializeGL()
{
    qglClearColor(Qt::white);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    QPainter p(this);
    p.setRenderHint(QPainter::HighQualityAntialiasing);
}

void SceneWidget::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glLineWidth(1.0f);
    qglColor(Qt::cyan);
    DrawGrid();

    glLineWidth(2.0f);
    qglColor(Qt::black);
    DrawAxis();

    glLineWidth(2.6f);

    this->detail->DrawDetail(Primitives::DegreeToRadian(angle), dmatr, show_points);

    if (cur_tr == 2)
    {
        qglColor(Qt::red);
        Primitives::DrawDot(transl.x(), transl.y(), 10.0);
    }
    if (scn_axis == true)
    {
        qglColor(Qt::red);
        if (cur_tr == 1)
            DrawAxis(transl.x(), transl.y());
        else
        {
            DrawAxis(dcenter.x(), dcenter.y());
            Primitives::DrawDot(transl.x(), transl.y(), 10.0);
        }
    }
}

void SceneWidget::resizeGL(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    this->rect.setRect(-width / 2.0, height / 2.0, (qreal)width, -(qreal)height);
    glOrtho(this->rect.left(), this->rect.right(), this->rect.bottom(), this->rect.top(), -1.0, 1.0);
    glViewport(0, 0, (GLint)width, (GLint)height);
}

void SceneWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::RightButton && (cur_tr == 1 || cur_tr == 2))
    {
        scn_axis = !scn_axis;

        this->setMouseTracking(scn_axis);

        qreal x = ( event->x() - this->rect.right()) / grid_step;
        qreal y = (-event->y() +   this->rect.top()) / grid_step;
        Round(&x, &y);

        if (cur_tr == 1)
        {
            transl.setX(grid_step * x);
            transl.setY(grid_step * y);
            double t1 = std::cos(angle);
            double t2 = std::sin(angle);
            this->dmatr.setMatrix(t1, t2, -t2, t1, transl.x(), transl.y());
        }
        else if (cur_tr == 2)
        {
            dcenter.setX(grid_step * x);
            dcenter.setY(grid_step * y);
        }

        emit this->updateX(static_cast<int>(x));
        emit this->updateY(static_cast<int>(y));
        emit this->updateGL();
    }
}

void SceneWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (scn_axis == true)
    {
        qreal x = ( event->x() - this->rect.right()) / grid_step;
        qreal y = (-event->y() +   this->rect.top()) / grid_step;
        Round(&x, &y);

        if (cur_tr == 1)
        {
            transl.setX(grid_step * x);
            transl.setY(grid_step * y);
            double t1 = std::cos(angle);
            double t2 = std::sin(angle);
            this->dmatr.setMatrix(t1, t2, -t2, t1, transl.x(), transl.y());
        }
        else if (cur_tr == 2)
        {
            dcenter.setX(grid_step * x);
            dcenter.setY(grid_step * y);
        }

        emit this->updateX(static_cast<int>(x));
        emit this->updateY(static_cast<int>(y));
        emit this->updateGL();
    }
}

void SceneWidget::LengthChanged(int val)
{
    this->detail->length_ = val;
    float t1 = Primitives::LenghtBetweenPoints(detail->points[0].x(), detail->points[0].y()
                                               , detail->points[2].x(), detail->points[2].x())
               - 0.5f * detail->small_circle_d;
    float t2 = Primitives::LenghtBetweenPoints(detail->points[1].x(), detail->points[1].y()
                                               , detail->points[2].x(), detail->points[2].x())
               - 0.5f * detail->big_circle_d;
    float t3 = Primitives::LenghtBetweenPoints(detail->points[3].x(), detail->points[3].y()
                                               , detail->points[2].x(), detail->points[2].x())
               - detail->outside_r;
    emit this->MinLength(qMin(qMin(t1, t2), t3));
    emit this->updateGL();
}

void SceneWidget::HeightChanged(int val)
{
    this->detail->height_ = val;
    emit this->MinHeight(detail->small_circle_d / 2 + detail->big_circle_d / 2);
    emit this->MaxHeight(detail->inside_r1 + 2 * detail->outside_r + detail->inside_r3);
    emit this->updateGL();
}

void SceneWidget::R1Changed(int val)
{
    this->detail->inside_r1 = val;
    emit this->MinR1(detail->small_circle_d / 2);
    emit this->updateGL();
}

void SceneWidget::R2Changed(int val)
{
    this->detail->inside_r2 = val;
    emit this->MinR2(detail->big_circle_d / 2);
    emit this->updateGL();
}

void SceneWidget::R3Changed(int val)
{
    this->detail->inside_r3 = val;
    emit this->MinR3(detail->big_circle_d / 2);
    emit this->updateGL();
}

void SceneWidget::rChanged(int val)
{
    this->detail->outside_r = val;
    emit this->Min_r((detail->height_ - detail->inside_r3 - detail->inside_r1) / 2);
    emit this->updateGL();
}

void SceneWidget::DChanged(int val)
{
    this->detail->big_circle_d = val;
    emit this->MaxD(qMin(2 * detail->inside_r2, 2 * detail->inside_r3));
    emit this->updateGL();
}

void SceneWidget::dChanged(int val)
{
    this->detail->small_circle_d = val;
    emit this->Max_d(2 * detail->inside_r1);
    emit this->updateGL();
}

void SceneWidget::showPoints(bool val)
{
    this->show_points = val;
    emit this->updateGL();
}

void SceneWidget::angleChanged(int val)
{
    this->angle = Primitives::DegreeToRadian(static_cast<float>(val));
    double t1 = std::cos(angle);
    double t2 = std::sin(angle);
    this->dmatr.setMatrix(t1, t2, -t2, t1,
                          transl.x() + dcenter.x() * t1 - t2 * dcenter.y(),
                          transl.y() + dcenter.x() * t2 + t1 * dcenter.y());
    emit this->updateGL();
}

void SceneWidget::gridValueChanged(int val)
{
    this->grid_step = val;
    emit this->updateGL();
}

void SceneWidget::currentTr(int val)
{
    cur_tr = val;
    switch (cur_tr)
    {
    case 1:
        dcenter.setX(0.0);
        dcenter.setY(0.0);
        bmatr.reset();
        break;
    case 2:
        bmatr.reset();
        break;
    case 3:
        bmatr.reset();
        dmatr.reset();
        dcenter.setX(0.0);
        dcenter.setY(0.0);
        transl.setX(0.0);
        transl.setY(0.0);
        break;
    }
    emit this->updateGL();
}

void SceneWidget::XxChanged(int val)
{
    this->bmatr.M11() = static_cast<double>(val);
    this->dmatr.M11() = static_cast<double>(val);
    emit this->updateGL();
}

void SceneWidget::XyChanged(int val)
{
    this->bmatr.M21() = static_cast<double>(val);
    this->dmatr.M21() = static_cast<double>(val);
    emit this->updateGL();
}

void SceneWidget::YxChanged(int val)
{
    this->bmatr.M12() = static_cast<double>(val);
    this->dmatr.M12() = static_cast<double>(val);
    emit this->updateGL();
}

void SceneWidget::YyChanged(int val)
{
    this->bmatr.M22() = static_cast<double>(val);
    this->dmatr.M22() = static_cast<double>(val);
    emit this->updateGL();
}


void SceneWidget::DrawGrid()
{
    int delta = this->rect.right() / this->grid_step, tmp;

    QPointF p1, p2;
    for (int i = -delta; i <= delta; ++i)
    {
        tmp = i * this->grid_step;
        p1 = bmatr.map(QPointF(tmp, this->rect.bottom()));
        p2 = bmatr.map(QPointF(tmp,    this->rect.top()));
        Primitives::DrawLine(p1.x(), p1.y(), p2.x(), p2.y(), bmatr);
    }

    delta = this->rect.top() / this->grid_step;
    for (int i = -delta; i <= delta; ++i)
    {
        tmp = i * this->grid_step;
        p1 = bmatr.map(QPointF( this->rect.left(), tmp));
        p2 = bmatr.map(QPointF(this->rect.right(), tmp));
        Primitives::DrawLine(p1.x(), p1.y(), p2.x(), p2.y(), bmatr);
    }
}

void SceneWidget::DrawAxis(qreal c_x, qreal c_y)
{
    QPointF p1, p2;
    p1 = bmatr.map(QPointF(this->rect.right(), c_y));
    p2 = bmatr.map(QPointF( this->rect.left(), c_y));
    Primitives::DrawLine(p1.x(), p1.y(), p2.x(), p2.y(), bmatr);
    p1 = bmatr.map(QPointF(p1.x() - 15.0, -15.0));
    this->renderText(p1.x(), p1.y(), 0.0, "X");

    p1 = bmatr.map(QPointF(c_x, this->rect.bottom()));
    p2 = bmatr.map(QPointF(c_x,    this->rect.top()));
    Primitives::DrawLine(p1.x(), p1.y(), p2.x(), p2.y(), bmatr);
    p1 = bmatr.map(QPointF(5.0, p2.y() - 15.0));
    this->renderText(p1.x(), p1.y(), 0.0, "Y");
}

void SceneWidget::Round(qreal* x, qreal* y)
{
    if (*x <= 0.0)
    {
        *x = std::floor(*x);
    }
    else
    {
        *x = std::ceil(*x);
    }

    if (*y <= 0.0)
    {
        *y = std::floor(*y);
    }
    else
    {
        *y = std::ceil(*y);
    }
}
