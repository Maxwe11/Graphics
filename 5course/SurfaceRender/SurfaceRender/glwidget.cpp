#include <QDebug>
#include <GL/glu.h>

#include "glwidget.h"
#include "primitives.h"
#include "dialog.h"

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
    , x_transl(0), y_transl(0), z_transl(0)
    , x_rot(0), y_rot(0), z_rot(0)
    , projA(M_PI_4), projF(1.0)
    , parabParam(1.0)
    , surfaceN(1)
    , xAxis(10.0f, 0.0f, 0.0f, 1.0f)
    , yAxis(0.0f, 10.0f, 0.0f, 1.0f)
    , zAxis(0.0f, 0.0f, 10.0f, 1.0f)
    , normals(false)
{
    mCurve.push_back({4.0f, 2.0f, 0.0f, 0.1f});
    mCurve.push_back({2.0f, 4.0f, 0.0f, 0.1f});
    mCurve.push_back({4.0f, 6.0f, 0.0f, 0.1f});
    build();
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

    QMatrix4x4 projection;
    projection(2, 0) = projF * qCos(projA);
    projection(2, 1) = projF * qSin(projA);
    projection = projection.transposed();
    QVector4D axis[] = { projection.map(xAxis), projection.map(yAxis), projection.map(zAxis) };
    Qt::GlobalColor color[] = { Qt::red, Qt::green, Qt::blue };

    qglColor(Qt::black);

    auto* arr = surfaceN == 1 ? &surface1 : &surface2;
    const auto& ref = *arr;

    for (int i = 0; i < ref.size(); ++i)
    {
        Primitives::DrawLine(ref[i].edge1.x(), ref[i].edge1.y(), ref[i].edge2.x(), ref[i].edge2.y());
        Primitives::DrawLine(ref[i].edge1.x(), ref[i].edge1.y(), ref[i].edge3.x(), ref[i].edge3.y());
        Primitives::DrawLine(ref[i].edge3.x(), ref[i].edge3.y(), ref[i].edge2.x(), ref[i].edge2.y());
    }

    if (normals)
    {
        auto* arr = surfaceN == 1 ? &normal1 : &normal2;
        const auto& ref = *arr;

        qglColor(Qt::magenta);
        for (int i = 0; i < ref.size(); ++i)
            Primitives::DrawLine(ref[i].x1(), ref[i].y1(), ref[i].x2(), ref[i].y2());
    }

    for (int i = 0; i < 3; ++i)
    {
        qglColor(color[i]);
        Primitives::DrawLine(0.0f, 0.0f, axis[i].x(), axis[i].y());
    }
}

void GLWidget::resizeGL(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLdouble halfWidth = 0.06 * width;
    GLdouble halfHeight = 0.06 * height;

    gluOrtho2D(-halfWidth, halfWidth, -halfHeight, halfHeight);
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void GLWidget::build()
{
    buildMatrix();
    buildSurface1();
    buildSurface2();
}

void GLWidget::buildMatrix()
{
    projection.setToIdentity();
    projection(2, 0) = projF * qCos(projA);
    projection(2, 1) = projF * qSin(projA);
    projection = projection.transposed();
    projection.translate(x_transl, y_transl, z_transl);
    projection.rotate(z_rot, 0.0f, 0.0f, 1.0f);
    projection.rotate(y_rot, 0.0f, 1.0f, 0.0f);
    projection.rotate(x_rot, 1.0f, 0.0f, 0.0f);
}

void GLWidget::buildSurface1()
{
    surface1.clear();
    normal1.clear();

    QVector<QVector4D> vec;

    for (float step = 0.1f, i = 0.0f, j = step; i < 5.4f; i += step, j += step)
        vec.push_back(QVector4D(i, parabParam * i * i, 0.0f, 1.0f));

    auto reflection = projection;
    reflection(0, 0) *= -1.0f;

    for (float z = 0.0f; z < 9.0f; z += 1.0)
    {
        for (int i = 0; i < vec.size() - 6; i += 6)
        {
            auto p1 = vec[i], p2 = vec[i + 3], p3 = vec[i];
            auto p4 = vec[i + 6], p5 = vec[i + 6];
            p1.setZ(z);
            p2.setZ(z + 0.5f);
            p3.setZ(z + 1.0f);
            p4.setZ(z);
            p5.setZ(z + 1.0f);

            buildNormal(p1, p2, p3, 1);
            buildNormal(p4, p2, p5, 1);
            buildNormal(p1, p2, p4, 1);
            buildNormal(p3, p2, p5, 1);

            p1 = reflection.map(p1);
            p2 = reflection.map(p2);
            p3 = reflection.map(p3);
            p4 = reflection.map(p4);
            p5 = reflection.map(p5);

            surface1.append({p1, p2, p3});
            surface1.append({p4, p2, p5});
            surface1.append({p1, p2, p4});
            surface1.append({p3, p2, p5});

            p1 = vec[i];
            p2 = vec[i + 3];
            p3 = vec[i];
            p4 = vec[i + 6];
            p5 = vec[i + 6];

            p1.setZ(z);
            p2.setZ(z + 0.5f);
            p3.setZ(z + 1.0f);
            p4.setZ(z);
            p5.setZ(z + 1.0f);

            p1 = projection.map(p1);
            p2 = projection.map(p2);
            p3 = projection.map(p3);
            p4 = projection.map(p4);
            p5 = projection.map(p5);

            surface1.append({p1, p2, p3});
            surface1.append({p4, p2, p5});
            surface1.append({p1, p2, p4});
            surface1.append({p3, p2, p5});
        }
    }
}

void GLWidget::buildSurface2()
{
    surface2.clear();
    normal2.clear();

    QVector<QVector4D> vec;

    QPointF t1, t2;
    QPointF p[] = { mCurve[0].toPointF(), mCurve[1].toPointF(), mCurve[2].toPointF() };
    t1 = p[0];
    vec.append(QVector4D(t1.x(), t1.y(), 0.0f, 1.0f));
    for (qreal u = 0.01; u <= 1.0; u += 0.01)
    {
        auto u1 = (1.0 - u) * (1.0 - u) * mCurve[0].w();
        auto u2 = 2 * (1.0 - u) * u * mCurve[1].w();
        auto u3 = u * u * mCurve[2].w();

        t2 = (p[0] * u1 + p[1] * u2 + p[2] * u3) / (u1 + u2 + u3);

        t1 = t2;
        vec.append(QVector4D(t2.x(), t2.y(), 0.0f, 1.0f));
    }

    auto reflection = projection;
    reflection(0, 0) *= -1.0f;

    for (float u = 0.0f, step = 36.0 * M_PI / 180.0; u < 2 * M_PI; u += step)
    {
        QMatrix4x4 rot_1, rot_2, rot_3;
        rot_1.rotate(180.0 * u / M_PI, 0.0f, 1.0f, 0.0f);
        rot_2.rotate(180.0 * (u + step / 2) / M_PI, 0.0f, 1.0f, 0.0f);
        rot_3.rotate(180.0 * (u + step) / M_PI, 0.0f, 1.0f, 0.0f);
        for (int i = 0; i < vec.size() - 9; i += 9)
        {
            auto p1 = vec[i], p2 = vec[i + 5], p3 = vec[i], p4 = vec[i + 9], p5 = vec[i + 9];

            p1 = rot_1.map(p1);
            p2 = rot_2.map(p2);
            p3 = rot_3.map(p3);
            p4 = rot_1.map(p4);
            p5 = rot_3.map(p5);

            buildNormal(p1, p2, p3, 2);
            buildNormal(p4, p2, p5, 2);
            buildNormal(p1, p2, p4, 2);
            buildNormal(p3, p2, p5, 2);

            p1 = projection.map(p1);
            p2 = projection.map(p2);
            p3 = projection.map(p3);
            p4 = projection.map(p4);
            p5 = projection.map(p5);

            surface2.append({p1, p2, p3});
            surface2.append({p4, p2, p5});
            surface2.append({p1, p2, p4});
            surface2.append({p3, p2, p5});
        }
    }
}

void GLWidget::translateX(int val)
{
    this->x_transl = val;
    build();
    this->updateGL();
}

void GLWidget::translateY(int val)
{
    this->y_transl = val;
    build();
    this->updateGL();
}

void GLWidget::translateZ(int val)
{
    this->z_transl = val;
    build();
    this->updateGL();
}

void GLWidget::rotateX(int val)
{
    this->x_rot = val;
    build();
    this->updateGL();
}

void GLWidget::rotateY(int val)
{
    this->y_rot = val;
    build();
    this->updateGL();
}

void GLWidget::rotateZ(int val)
{
    this->z_rot = val;
    build();
    this->updateGL();
}

void GLWidget::projectionA(int val)
{
    this->projA = val * M_PI / 180.0;
    build();
    this->updateGL();
}

void GLWidget::projectionF(double val)
{
    this->projF = val;
    build();
    this->updateGL();
}

void GLWidget::parabolaParam(double val)
{
    this->parabParam = val;
    buildSurface1();
    this->updateGL();
}

void GLWidget::changeSurface(bool val)
{
    this->surfaceN = val ? 1 : 2;
    this->updateGL();
}

void GLWidget::showNormalsForFace(bool val)
{
    this->normals = val;
    this->updateGL();
}

void GLWidget::editCurve()
{
    Dialog d(mCurve);
    d.exec();
    buildSurface2();
    this->updateGL();
}

void GLWidget::buildNormal(const QVector4D& p1, const QVector4D& p2, const QVector4D& p3, int surf)
{
    QVector4D pp1((p1.x() + p2.x() + p3.x()) / 3.0,
                  (p1.y() + p2.y() + p3.y()) / 3.0,
                  (p1.z() + p2.z() + p3.z()) / 3.0,
                  1.0f);

    float a = p1.y() * (p2.z() - p3.z()) +
              p2.y() * (p3.z() - p1.z()) +
              p3.y() * (p1.z() - p2.z());

    float b = p1.z() * (p2.x() - p3.x()) +
              p2.z() * (p3.x() - p1.x()) +
              p3.z() * (p1.x() - p2.x());

    float c = p1.x() * (p2.y() - p3.y()) +
              p2.x() * (p3.y() - p1.y()) +
              p3.x() * (p1.y() - p2.y());

    a += pp1.x() - p1.x();
    b += pp1.y() - p1.y();
    c += pp1.z() - p1.z();

    auto len_x = a - pp1.x();
    auto len_y = b - pp1.y();
    auto len_z = c - pp1.z();
    auto len = qSqrt(len_x * len_x + len_y * len_y + len_z * len_z);
    a = pp1.x() - len_x / len * 6.0;
    b = pp1.y() - len_y / len * 6.0;
    c = pp1.z() - len_z / len * 6.0;
    QVector4D pp2(a, b, c, 1.0f);


    if (surf == 1)
    {
        normal1.push_back(QLineF(projection.map(pp1).toPointF(), projection.map(pp2).toPointF()));
        projection(0, 0) *= -1.0f;
        normal1.push_back(QLineF(projection.map(pp1).toPointF(), projection.map(pp2).toPointF()));
        projection(0, 0) *= -1.0f;
    }
    else
    {
        normal2.push_back(QLineF(projection.map(pp1).toPointF(), projection.map(pp2).toPointF()));
    }
}
