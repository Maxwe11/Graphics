#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL/QGLWidget>

#include "cartesianleaf.h"

class GLWidget : public QGLWidget {
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
private:
    void DrawGrid();
    void DrawAxis();
signals:
public slots:
    void TranslateX(int);
    void TranslateY(int);
    void Rotate(int);
    void showFlower(bool);
private:
    int grid_step;
    QMatrix m_matr;
    bool flower;
public:
    CartesianLeaf* leaf;
};

#endif // GLWIDGET_H
