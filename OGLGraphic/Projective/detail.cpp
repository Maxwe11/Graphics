#include "detail.h"
#include "matrix.h"
#include "primitives.h"

Detail::Detail()
{
    length_                = 80;
    height_                = 85;
    small_circle_d         = 14;
    big_circle_d           = 25;
    outside_r              = 32;
    inside_r1              = 16;
    inside_r2              = 40;
    inside_r3              = 26;
}

void Detail::DrawDetail(const Matrix& m, bool show_points)
{
    Recalc();
    //отверстия
    Primitives::DrawCircle(points[0], 0.5f * small_circle_d, m);
    Primitives::DrawCircle(points[1], 0.5f * big_circle_d, m);
    Primitives::DrawCircle(points[2], 0.5f * big_circle_d, m);

    Primitives::DrawLine(points[6], points[7], m);
    Primitives::DrawLine(points[8], points[9], m);

    Primitives::DrawArc(points[0], inside_r1, inside1_angle_begin, inside1_angle_end, m);
    Primitives::DrawArc(points[1], inside_r3, inside3_angle_begin, inside3_angle_end, m);
    Primitives::DrawArc(points[2], inside_r2, inside2_angle_begin, inside2_angle_end, m);
    Primitives::DrawArc(points[3], outside_r, outside_angle_begin, outside_angle_end, m);
//drawing dots
    if (show_points == true)
    {
        for (int i = 0; i < 10; ++i);
//            Primitives::DrawDot(points[i].x(), points[i].y(), 10.0);
    }
}

void Detail::Recalc()
{
    GLfloat len = 0.5f * length_;
    GLfloat hgt = 0.5f * height_;

    points[0] = QPointF(inside_r3, inside_r1);
    points[1] = QPointF(inside_r3, height_ + inside_r1);
    points[2] = QPointF( length_ + inside_r3,  hgt + inside_r1);

    GLfloat outside_x, outside_y;
    GLfloat outside_x_begin, outside_y_begin;
    GLfloat outside_x_end, outside_y_end;
    GLfloat hx1, hy1, hx2, hy2;
    GLfloat lx1, ly1, lx2, ly2;
//внешнее сопряжение
    {
        GLfloat r1 = (inside_r1 + outside_r);
        GLfloat r2 = (inside_r3 + outside_r);

        GLfloat tmp = (r2 * r2 - r1 * r1 + height_ * height_) / (2.0f * height_);
        outside_x = inside_r3 - (qSqrt(r2 * r2 - tmp * tmp));
        outside_y =  height_ + inside_r1 - tmp;

        tmp = Primitives::AngleLine(outside_x, outside_y, inside_r3, inside_r1);
        outside_angle_begin = Primitives::RadianToDegree(tmp);

        tmp = Primitives::AngleLine(outside_x, outside_y, inside_r3,  height_ + inside_r1);
        outside_angle_end   = Primitives::RadianToDegree(tmp);

        inside1_angle_begin = 180.0 + outside_angle_begin;
        inside3_angle_end   = 180.0 + outside_angle_end;

        outside_x_begin = inside_r3 + (inside_r1 * qCos(Primitives::DegreeToRadian(inside1_angle_begin)));
        outside_y_begin = inside_r1 + (inside_r1 * qSin(Primitives::DegreeToRadian(inside1_angle_begin)));

        outside_x_end   = inside_r3 + (inside_r3 * qCos(Primitives::DegreeToRadian(inside3_angle_end)));
        outside_y_end   = height_ + inside_r1 + (inside_r3 * qSin(Primitives::DegreeToRadian(inside3_angle_end)));

        points[3] = QPointF(outside_x, outside_y);
        points[4] = QPointF(outside_x_begin, outside_y_begin);
        points[5] = QPointF(outside_x_end, outside_y_end);
    }
//внунтр. сопряжение
    {
        GLfloat base_hip = qSqrt(length_ * length_ + hgt * hgt);

        inside3_angle_begin =  qAtan(length_ / hgt);
        inside1_angle_end   = -qAtan(length_ / hgt);

        if (inside_r2 >= inside_r3)
            inside3_angle_begin += 0.5 * Primitives::Pi - qAcos((inside_r2 - inside_r3) / base_hip);
        else
            inside3_angle_begin -= 0.5 * Primitives::Pi - qAcos((inside_r3 - inside_r2) / base_hip);

        if (inside_r2 >= inside_r1)
            inside1_angle_end += -0.5 * Primitives::Pi + qAcos((inside_r2 - inside_r1) / base_hip);
        else
            inside1_angle_end -= -0.5 * Primitives::Pi + qAcos((inside_r1 - inside_r2) / base_hip);

        hx1 = inside_r3 + (inside_r3 * qCos(inside3_angle_begin));
        hy1 = inside_r1 + height_ + (inside_r3 * qSin(inside3_angle_begin));

        hx2 = inside_r3 + length_ + (inside_r2 * qCos(inside3_angle_begin));
        hy2 = inside_r1 + hgt + (inside_r2 * qSin(inside3_angle_begin));

        lx1 = inside_r3 + (inside_r1 * qCos(inside1_angle_end));
        ly1 = inside_r1 + (inside_r1 * qSin(inside1_angle_end));

        lx2 = inside_r3 + length_ + (inside_r2 * qCos(inside1_angle_end));
        ly2 = inside_r1 + hgt + (inside_r2 * qSin(inside1_angle_end));

        points[6] = QPointF(hx1, hy1);
        points[7] = QPointF(hx2, hy2);
        points[8] = QPointF(lx1, ly1);
        points[9] = QPointF(lx2, ly2);

        inside1_angle_end    = Primitives::RadianToDegree(inside1_angle_end);
        inside3_angle_begin  = Primitives::RadianToDegree(inside3_angle_begin);
        inside2_angle_begin  = inside1_angle_end;
        inside2_angle_end    = inside3_angle_begin;
        inside1_angle_end   += 360.0;
    }
}
