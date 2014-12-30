#include <QDebug>
#include <GL/glu.h>

#include "glwidget.h"
#include "primitives.h"
#include "dialog.h"

#define IS_CUBE 0

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::DoubleBuffer), parent)
    , x_transl(0), y_transl(0), z_transl(0)
    , x_rot(0), y_rot(0), z_rot(0)
    , projA(M_PI_4), projF(1.0)
{
    QVector<QVector4D> curve;
    curve.push_back({4.0f, 2.0f, 0.0f, 0.1f});
    curve.push_back({2.0f, 4.0f, 0.0f, 0.1f});
    curve.push_back({4.0f, 6.0f, 0.0f, 0.1f});
    mRationalSurface.setPoints(curve);

    mProjections[0](2, 0) = projF * qCos(projA);
    mProjections[0](2, 1) = projF * qSin(projA);
    mProjections[0] = mProjections[0].transposed();

#if IS_CUBE
    mSurfaces.push_back(&mCube);
#else
    mSurfaces.push_back(&mCylinder);
#endif
    mSurfaces.push_back(&mRationalSurface);

#if IS_CUBE
    mCurrentSurface = &mCube;
#else
    //mCurrentSurface = &mCylinder;
    mCurrentSurface = &mRationalSurface;
#endif
    projection = &mProjections[0];

    Face3D::mGl = this;
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

    mCurrentSurface->draw(*projection);

    if (mCurrentSurface->isNormalsDrawn())
    {
        qglColor(Qt::red);
        mCurrentSurface->drawNormals(*projection);
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

void GLWidget::translateX(int val)
{
    QMatrix4x4 m;
    m.translate(val - x_transl, 0.0f, 0.0f);

    for (auto surface : mSurfaces)
        surface->transform(m);

    x_transl = val;
    updateGL();
}

void GLWidget::translateY(int val)
{
    QMatrix4x4 m;
    m.translate(0.0f, val - y_transl, 0.0f);

    for (auto surface : mSurfaces)
        surface->transform(m);

    y_transl = val;
    updateGL();
}

void GLWidget::translateZ(int val)
{
    QMatrix4x4 m;
    m.translate(0.0f, 0.0f, val - z_transl);

    for (auto surface : mSurfaces)
        surface->transform(m);

    z_transl = val;
    updateGL();
}

void GLWidget::rotateX(int val)
{
    QMatrix4x4 m;
    m.rotate(val - x_rot, 1.0f, 0.0f, 0.0f);

    for (auto surface : mSurfaces)
        surface->transform(m);

    x_rot = val;
    updateGL();
}

void GLWidget::rotateY(int val)
{
    QMatrix4x4 m;
    m.rotate(val - y_rot, 0.0f, 1.0f, 0.0f);

    for (auto surface : mSurfaces)
        surface->transform(m);

    y_rot = val;
    updateGL();
}

void GLWidget::rotateZ(int val)
{
    QMatrix4x4 m;
    m.rotate(val - z_rot, 0.0f, 0.0f, 1.0f);

    for (auto surface : mSurfaces)
        surface->transform(m);

    z_rot = val;
    updateGL();
}

void GLWidget::projectionA(int value)
{
    projA = value * M_PI / 180.0;
    mProjections[0].setToIdentity();
    mProjections[0](2, 0) = projF * qCos(projA);
    mProjections[0](2, 1) = projF * qSin(projA);
    mProjections[0] = mProjections[0].transposed();
    updateGL();
}

void GLWidget::projectionF(double val)
{
    projF = val;
    mProjections[0].setToIdentity();
    mProjections[0](2, 0) = projF * qCos(projA);
    mProjections[0](2, 1) = projF * qSin(projA);
    mProjections[0] = mProjections[0].transposed();
    updateGL();
}

void GLWidget::parabolaParam(double value)
{
#if !IS_CUBE
    mCylinder.setParabolaParameter(static_cast<float>(value));
#endif
    QMatrix4x4 m;
    m.translate(x_transl, y_transl, z_transl);
    m.rotate(x_rot, 1.0f, 0.0f, 0.0f);
    m.rotate(y_rot, 0.0f, 1.0f, 0.0f);
    m.rotate(z_rot, 0.0f, 0.0f, 1.0f);
#if !IS_CUBE
    mCylinder.transform(m);
#endif
    updateGL();
}

void GLWidget::changeSurface(bool value)
{
    mCurrentSurface = value ?
            #if IS_CUBE
                              static_cast<Surface*>(&mCube)
            #else
                              static_cast<Surface*>(&mCylinder)
            #endif
                            : static_cast<Surface*>(&mRationalSurface);
    updateGL();
}

void GLWidget::showNormalsForFace(bool value)
{
    for (auto surface : mSurfaces)
        surface->setDrawNormals(value);

    updateGL();
}

void GLWidget::setShadind(bool value)
{
    for (auto surface : mSurfaces)
        surface->setShading(value);

    updateGL();
}

void GLWidget::editCurve()
{
    auto points = mRationalSurface.getPoints();
    Dialog d(points);
    d.exec();
    mRationalSurface.setPoints(points);
    updateGL();
}

void GLWidget::changeProjection(bool value)
{
    projection = value ? &mProjections[0]
                       : &mProjections[1];
    updateGL();
}
