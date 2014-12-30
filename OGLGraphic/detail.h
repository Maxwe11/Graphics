#ifndef DETAIL_H
#define DETAIL_H

#include <QPointF>

#include "scenewidget.h"

class Matrix;

class Detail {
    friend class SceneWidget;
public:
    Detail();
    void DrawDetail(float angle, const Matrix&, bool);
private:
    int length_;
    int height_;
    int small_circle_d;
    int big_circle_d;
    int outside_r;
    int inside_r1;
    int inside_r2;
    int inside_r3;
    //view params
    QPointF points[10];
    //angles
    float inside1_angle_begin, inside1_angle_end;
    float inside2_angle_begin, inside2_angle_end;
    float inside3_angle_begin, inside3_angle_end;
    float outside_angle_begin, outside_angle_end;
    //func
    void Recalc(float angle);
};

#endif // DETAIL_H
