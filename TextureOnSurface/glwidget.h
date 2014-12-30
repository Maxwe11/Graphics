#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL/QGLWidget>

#include <QVector>

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

    void translateU(double);
    void translateV(double);
private:
    int x_transl, y_transl, z_transl;
    int x_rot, y_rot, z_rot;
    float duck_u_transl, duck_v_transl;
    float param;
    QVector< QVector< QPointF > > duckPos;
};

#endif // GLWIDGET_H
