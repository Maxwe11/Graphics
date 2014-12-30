#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QVector>

class QGraphicsScene;
class Point;
class Polygon;

class View : public QGraphicsView {
    Q_OBJECT
public:
    explicit View(QWidget *parent = 0);
    ~View();
//private:
//    void mousePressEvent(QMouseEvent*);
private:
    Polygon* polygon;
    QVector<QPointF> m_points;
};

#endif // VIEW_H
