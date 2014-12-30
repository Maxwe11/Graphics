#include "detail.h"
#include "matrix.h"
#include "primitives.h"

Detail::Detail()
{
    length_                = 160;
    height_                = 170;
    small_circle_d         = 28;
    big_circle_d           = 50;
    outside_r              = 64;
    inside_r1              = 32;
    inside_r2              = 80;
    inside_r3              = 52;
}

void Detail::DrawDetail(float angle, const Matrix& m, bool show_points)
{
    Recalc(angle);
    //отверстия
    Primitives::DrawCircle(points[0].x(), points[0].y(), 0.5f * small_circle_d, m);
    Primitives::DrawCircle(points[1].x(), points[1].y(), 0.5f * big_circle_d, m);
    Primitives::DrawCircle(points[2].x(), points[2].y(), 0.5f * big_circle_d, m);

    Primitives::DrawLine(points[6].x(), points[6].y(), points[7].x(), points[7].y(), m);
    Primitives::DrawLine(points[8].x(), points[8].y(), points[9].x(), points[9].y(), m);

    Primitives::DrawArc(points[0].x(), points[0].y(), inside_r1, inside1_angle_begin, inside1_angle_end, m);
    Primitives::DrawArc(points[1].x(), points[1].y(), inside_r3, inside3_angle_begin, inside3_angle_end, m);
    Primitives::DrawArc(points[2].x(), points[2].y(), inside_r2, inside2_angle_begin, inside2_angle_end, m);
    Primitives::DrawArc(points[3].x(), points[3].y(), outside_r, outside_angle_begin, outside_angle_end, m);
//drawing dots
    if (show_points == true)
    {
        for (int i = 0; i < 10; ++i)
            Primitives::DrawDot(points[i].x(), points[i].y(), 10.0);
    }
}

void Detail::Recalc(float angle)
{
    GLfloat len = 0.5f * length_;
    GLfloat hgt = 0.5f * height_;

    double t1 = std::cos(angle);
    double t2 = std::sin(angle);
    Matrix m(t1, t2, 0.0, -t2, t1, 0.0, 0.0, 0.0, 1.0);

    points[0] = m.map(QPointF(-len, -hgt));
    points[1] = m.map(QPointF(-len,  hgt));
    points[2] = m.map(QPointF( len,  0.0));

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
        outside_x = -len - (std::sqrt(r2 * r2 - tmp * tmp));
        outside_y =  hgt - tmp;

        tmp = Primitives::AngleLine(outside_x, outside_y, -len, -hgt);
        outside_angle_begin = Primitives::RadianToDegree(tmp + angle);

        tmp = Primitives::AngleLine(outside_x, outside_y, -len,  hgt);
        outside_angle_end   = Primitives::RadianToDegree(tmp + angle);

        inside1_angle_begin = 180.0 + outside_angle_begin;
        inside3_angle_end   = 180.0 + outside_angle_end;

        outside_x_begin = -len + (inside_r1 * std::cos(Primitives::DegreeToRadian(inside1_angle_begin)));
        outside_y_begin = -hgt + (inside_r1 * std::sin(Primitives::DegreeToRadian(inside1_angle_begin)));

        outside_x_end   = -len + (inside_r3 * std::cos(Primitives::DegreeToRadian(inside3_angle_end)));
        outside_y_end   =  hgt + (inside_r3 * std::sin(Primitives::DegreeToRadian(inside3_angle_end)));

        points[3] = m.map(QPointF(outside_x, outside_y));
        points[4] = m.map(QPointF(outside_x_begin, outside_y_begin));
        points[5] = m.map(QPointF(outside_x_end, outside_y_end));
    }
//внунтр. сопряжение
    {
        GLfloat base_hip = std::sqrt(length_ * length_ + hgt * hgt);

        inside3_angle_begin =  std::atan(length_ / hgt);
        inside1_angle_end   = -std::atan(length_ / hgt);

        if (inside_r2 >= inside_r3)
            inside3_angle_begin += 0.5 * Primitives::Pi - std::acos((inside_r2 - inside_r3) / base_hip);
        else
            inside3_angle_begin -= 0.5 * Primitives::Pi - std::acos((inside_r3 - inside_r2) / base_hip);

        if (inside_r2 >= inside_r1)
            inside1_angle_end += -0.5 * Primitives::Pi + std::acos((inside_r2 - inside_r1) / base_hip);
        else
            inside1_angle_end -= -0.5 * Primitives::Pi + std::acos((inside_r1 - inside_r2) / base_hip);

        hx1 = (inside_r3 * std::cos(inside3_angle_begin)) - len;
        hy1 = (inside_r3 * std::sin(inside3_angle_begin)) + hgt;

        hx2 = (inside_r2 * std::cos(inside3_angle_begin)) + len;
        hy2 = (inside_r2 * std::sin(inside3_angle_begin));

        lx1 = (inside_r1 * std::cos(inside1_angle_end)) - len;
        ly1 = (inside_r1 * std::sin(inside1_angle_end)) - hgt;

        lx2 = (inside_r2 * std::cos(inside1_angle_end)) + len;
        ly2 = (inside_r2 * std::sin(inside1_angle_end));

        points[6] = m.map(QPointF(hx1, hy1));
        points[7] = m.map(QPointF(hx2, hy2));
        points[8] = m.map(QPointF(lx1, ly1));
        points[9] = m.map(QPointF(lx2, ly2));

        inside1_angle_end    = Primitives::RadianToDegree(inside1_angle_end + angle);
        inside3_angle_begin  = Primitives::RadianToDegree(inside3_angle_begin + angle);
        inside2_angle_begin  = inside1_angle_end;
        inside2_angle_end    = inside3_angle_begin;
        inside1_angle_end   += 360.0;
    }
}
