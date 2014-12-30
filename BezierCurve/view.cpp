#include <QDebug>
#include <QTimeLine>
#include <QMouseEvent>
#include <QtWidgets/QGraphicsScene>
#include <QtCore/qmath.h>
#include <QtWidgets/QGraphicsItemAnimation>

#include "view.h"
#include "point.h"
#include "bezier.h"

View::View(QWidget *parent)
    : QGraphicsView(parent)
    , editMode(true)
{
    this->setRenderHint(QPainter::Antialiasing);
    this->setMatrix(QMatrix(1.0, 0.0, 0.0, -1.0, 0.0, 0.0));
    this->setScene(new QGraphicsScene(-600, 330, 1200, -660));

    //points.push_back(new Point(QPointF(), this->scene()));

//        QPixmap duck("1.bmp");
//        duck = duck.transformed(QTransform(1.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 1.0));
//        this->duck = this->scene()->addPixmap(duck);
//        this->duck->setPos(-275.0, -218.0);
//        this->duck->setZValue(-1.0);
//        this->duck->setVisible(true);

//        QPixmap shark("2.bmp");
//        shark = shark.transformed(QTransform(1.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 1.0));
//        this->shark = this->scene()->addPixmap(shark);
//        this->shark->setPos(-275.0, -218.0);
//        this->shark->setZValue(-1.0);
//        this->shark->setVisible(true);

    sharkPos     << QPointF(-157, 41)  << QPointF(-343, 12)  << QPointF(-295, -106)
                 << QPointF(-87, -112) << QPointF(-19, -236) << QPointF(22, -270)
                 << QPointF(-26, -92)  << QPointF(-4, -85)   << QPointF(24, -80)
                 << QPointF(50, -77)   << QPointF(71, -107)  << QPointF(92, -117)
                 << QPointF(82, -71)   << QPointF(94, -67)   << QPointF(111, -64)
                 << QPointF(125, -62)  << QPointF(140, -87)  << QPointF(151, -110)
                 << QPointF(156, -122) << QPointF(173, -139) << QPointF(210, -177)
                 << QPointF(227, -158) << QPointF(99, -47)   << QPointF(273, -14)
                 << QPointF(246, 110)  << QPointF(227, 44)   << QPointF(152, -44)
                 << QPointF(75, -2)    << QPointF(74, 22)    << QPointF(92, 46)
                 << QPointF(91, 59)    << QPointF(73, 73)    << QPointF(42, 40)
                 << QPointF(30, 16)    << QPointF(17, 22)    << QPointF(7, 26)
                 << QPointF(7, 26)     << QPointF(13, 60)    << QPointF(20, 96)
                 << QPointF(50, 135)   << QPointF(29, 170)   << QPointF(-46, 105)
                 << QPointF(-100, 63)  << QPointF(-130, 113) << QPointF(-154, 152)
                 << QPointF(-179, 156) << QPointF(-187, 130) << QPointF(-169, 80);

        duckPos << QPointF(-128, -123) << QPointF(-185, -51) << QPointF(-185, -41)
                << QPointF(-272, -33)  << QPointF(-189, -33) << QPointF(-182, -23)
                << QPointF(-193, 38)   << QPointF(-170, 214) << QPointF(10, 293)
                << QPointF(95, 109)    << QPointF(81, 73)    << QPointF(58, 110)
                << QPointF(19, 117)    << QPointF(2, 137)    << QPointF(-22, 151)
                << QPointF(-42, 146)   << QPointF(-17, 101)  << QPointF(-100, 163)
                << QPointF(-133, 100)  << QPointF(-114, 117) << QPointF(-92, 148)
                << QPointF(-9, 105)    << QPointF(-12, 118)  << QPointF(-2, 128)
                << QPointF(57, 99)     << QPointF(68, 90)    << QPointF(44, 107)
                << QPointF(79, 81)     << QPointF(72, 67)    << QPointF(57, 56)
                << QPointF(50, 34)     << QPointF(117, 18)   << QPointF(245, -22)
                << QPointF(273, 22)    << QPointF(260, 48)   << QPointF(211, 54)
                << QPointF(179, 55)    << QPointF(155, 68)   << QPointF(128, 85)
                << QPointF(95, 109)    << QPointF(84, 82)    << QPointF(68, 58)
                << QPointF(48, 34)     << QPointF(23, 33)    << QPointF(-97, 45)
                << QPointF(68, -67)    << QPointF(112, -114) << QPointF(147, -166);


    for (int i = 0; i < duckPos.size(); ++i)
    {
        points.push_back(new Point(duckPos[i], this->scene()));
    }

    curves.push_back(new Bezier(points[ 0], points[ 1], points[ 2], points[ 3], this->scene()));
    curves.push_back(new Bezier(points[ 3], points[ 4], points[ 5], points[ 6], this->scene()));
    curves.push_back(new Bezier(points[ 6], points[ 7], points[ 8], points[ 9], this->scene()));
    curves.push_back(new Bezier(points[ 9], points[10], points[11], points[12], this->scene()));
    curves.push_back(new Bezier(points[12], points[13], points[14], points[15], this->scene()));
    curves.push_back(new Bezier(points[15], points[16], points[17], points[18], this->scene()));
    curves.push_back(new Bezier(points[18], points[19], points[20], points[21], this->scene()));
    curves.push_back(new Bezier(points[21], points[22], points[23], points[24], this->scene()));
    curves.push_back(new Bezier(points[24], points[25], points[26], points[27], this->scene()));
    curves.push_back(new Bezier(points[27], points[28], points[29], points[30], this->scene()));
    curves.push_back(new Bezier(points[30], points[31], points[32], points[33], this->scene()));
    curves.push_back(new Bezier(points[33], points[34], points[35], points[36], this->scene()));
    curves.push_back(new Bezier(points[36], points[37], points[38], points[39], this->scene()));
    curves.push_back(new Bezier(points[39], points[40], points[41], points[42], this->scene()));
    curves.push_back(new Bezier(points[42], points[43], points[44], points[45], this->scene()));
    curves.push_back(new Bezier(points[45], points[46], points[47], points[ 0], this->scene()));
}

View::~View()
{
    qDebug() << "view destr called";
    foreach(QGraphicsItem* p, curves)
        delete p;
    foreach(QGraphicsItem* p, points)
        delete p;
}

void View::enableEditMode(bool val)
{
    this->editMode = val;
}

void View::showPoints(bool val)
{
    foreach(QGraphicsItem* item, points)
        item->setVisible(val);
    this->scene()->update();
}

void View::showLines(bool val)
{
    foreach(Bezier* item, curves)
        item->showLines(val);
    this->scene()->update();
}

void View::sharkToDuck()
{
    QTimeLine* timer = new QTimeLine(4000, this);
    timer->setFrameRange(0, 100);

    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation [points.size()]();
    for (int i = 0; i < points.size(); ++i)
    {
        animation[i].setItem(points[i]);
        animation[i].setTimeLine(timer);
        animation[i].setPosAt(0.0, sharkPos[i]);
        animation[i].setPosAt(1.0, duckPos[i]);
    }
    timer->start();
}

void View::duckToShark()
{
    QTimeLine* timer = new QTimeLine(4000, this);
    timer->setFrameRange(0, 100);

    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation [points.size()]();
    for (int i = 0; i < points.size(); ++i)
    {
        animation[i].setItem(points[i]);
        animation[i].setTimeLine(timer);
        animation[i].setPosAt(0.0, duckPos[i]);
        animation[i].setPosAt(1.0, sharkPos[i]);
    }
    timer->start();
}

//void View::save()
//{
//    foreach(QGraphicsItem* p, points)
//        qDebug() << p->pos();
//}

void View::mousePressEvent(QMouseEvent* e)
{
    static uint counter(0);
    static Point* p[3];

    if (editMode == true)
    {
        QGraphicsView::mousePressEvent(e);
    }
    else
    {
        p[counter++] = new Point(mapToScene(e->pos()), this->scene());
        if (counter == 3)
        {
            curves.push_back(new Bezier(points.back(), p[0], p[1], p[2], this->scene()));
            points.push_back(p[0]);
            points.push_back(p[1]);
            points.push_back(p[2]);
            counter = 0;
        }
    }
}
