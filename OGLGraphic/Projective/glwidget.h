#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL/QGLWidget>

#include "matrix.h"
#include "detail.h"

class Detail;

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
    void XxChanged(int);
    void XyChanged(int);
    void YxChanged(int);
    void YyChanged(int);
    void WxChanged(int);
    void WyChanged(int);
    void W0Changed(int);
    void X0Changed(int);
    void Y0Changed(int);
private:
    void DrawGrid();
    void DrawAxis();
private:
    int grid_step;
    Matrix m_matr;
    Matrix d_matr;
    Detail* det;
};

#endif // GLWIDGET_H
