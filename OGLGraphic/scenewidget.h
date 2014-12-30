#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QtOpenGL/QGLWidget>

#include "matrix.h"

class Detail;

class SceneWidget : public QGLWidget {
    Q_OBJECT
public:
    SceneWidget(QWidget* parent = 0);
    ~SceneWidget();
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
signals:
    void MinLength(int);
    void MinHeight(int);
    void MaxHeight(int);
    void MinR1(int);
    void MinR2(int);
    void MinR3(int);
    void Min_r(int);
    void MaxD(int);
    void Max_d(int);
    void updateX(int);
    void updateY(int);
public slots:
    //Detail params
    void LengthChanged(int);
    void HeightChanged(int);
    void R1Changed(int);
    void R2Changed(int);
    void R3Changed(int);
    void rChanged(int);
    void DChanged(int);
    void dChanged(int);
    //View params
    void showPoints(bool);
    void angleChanged(int);
    void gridValueChanged(int);
    void currentTr(int);
    void XxChanged(int);
    void XyChanged(int);
    void YxChanged(int);
    void YyChanged(int);
private:
    void DrawGrid();
    void DrawAxis(qreal c_x = 0.0, qreal c_y = 0.0);
    void Round(qreal* x, qreal* y);
private:
    QRectF           rect;
    Matrix           bmatr;
    Matrix           dmatr;
    QPointF          transl;
    QPointF          dcenter;
    bool             show_points;
    float            angle;
    bool             scn_axis;
    int              grid_step;
    int              cur_tr; //1, 2, 3, 4
    Detail*          detail;
};

#endif // SCENEWIDGET_H
