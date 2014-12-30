#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <QtCore/QVector>
#include <QVector4D>
#include <QMatrix4x4>
#include <QLineF>

struct Face
{
    QVector4D edge1;
    QVector4D edge2;
    QVector4D edge3;
};

class GLWidget : public QGLWidget {
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void build();
    void buildMatrix();
    void buildSurface1();
    void buildSurface2();
public slots:
    void translateX(int);
    void translateY(int);
    void translateZ(int);
    void rotateX(int);
    void rotateY(int);
    void rotateZ(int);
    void projectionA(int);
    void projectionF(double);
    void parabolaParam(double);
    void changeSurface(bool);
    void showNormalsForFace(bool);
    void editCurve();
    void buildNormal(const QVector4D& p1, const QVector4D& p2, const QVector4D& p3, int surf);
private:
    int x_transl, y_transl, z_transl;
    int x_rot, y_rot, z_rot;
    double projA, projF;
    double parabParam;
    int surfaceN;
    QVector4D xAxis, yAxis, zAxis;
    bool normals;
    QVector<Face> surface1;
    QVector<Face> surface2;
    QMatrix4x4 projection;
    QVector<QLineF> normal1;
    QVector<QLineF> normal2;
    QVector<QVector4D> mCurve;
};

#endif // GLWIDGET_H
