#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/QtOpenGLVersion>

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
    void changeParam(double);
private:
    int x_transl, y_transl, z_transl;
    int x_rot, y_rot, z_rot;
    float param;
};

#endif // GLWIDGET_H
