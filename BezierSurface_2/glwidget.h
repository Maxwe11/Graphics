#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL/QGLWidget>

class Model;

class GLWidget : public QGLWidget {
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    void setModel(Model* m);
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
private:
    Model* m_model;
};

#endif // GLWIDGET_H
