#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <QtCore/QVector>
#include <QMatrix4x4>

//#include "face.h"
#include "paraboliccylinder.h"
#include "rationalsurface.h"
#include "cube.h"

class Surface;

class GLWidget : public QGLWidget {
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
public slots:
    void translateX(int);
    void translateY(int);
    void translateZ(int);
    void rotateX(int);
    void rotateY(int);
    void rotateZ(int);
    void projectionA(int value);
    void projectionF(double);
    void parabolaParam(double value);
    void changeSurface(bool value);
    void showNormalsForFace(bool value);
    void setShadind(bool value);
    void editCurve();
    void changeProjection(bool value);
private:
    int x_transl, y_transl, z_transl;
    int x_rot, y_rot, z_rot;
    double projA, projF;
    QMatrix4x4* projection;
    QMatrix4x4 mProjections[2];
    ParabolicCylinder mCylinder;
    RationalSurface mRationalSurface;
    Cube mCube;
    QVector<Surface*> mSurfaces;
    Surface* mCurrentSurface;
};

#endif // GLWIDGET_H
