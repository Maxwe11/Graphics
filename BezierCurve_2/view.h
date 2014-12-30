#ifndef VIEW_H
#define VIEW_H

#include <QtWidgets/QGraphicsView>
#include <QVector>

class QGraphicsScene;
class Point;
class Bezier;

class View : public QGraphicsView {
    Q_OBJECT
public:
    explicit View(QWidget *parent = 0);
    ~View();
public slots:
    void enableEditMode(bool);
    void showPoints(bool);
    void showLines(bool);
    void sharkToDuck();
    void duckToShark();
    void save();
private:
    void mousePressEvent(QMouseEvent*);
private:
    bool editMode;
    QGraphicsPixmapItem* duck;
    QGraphicsPixmapItem* shark;
    QVector<Point*> points;
    QVector<Bezier*> curves;
    QVector<QPointF> duckPos;
    QVector<QPointF> sharkPos;
};

#endif // VIEW_H
