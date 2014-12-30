#ifndef VIEW_H
#define VIEW_H

#include <QtWidgets/QGraphicsView>

#include "turtle.h"

class QGraphicsScene;

class View : public QGraphicsView {
    Q_OBJECT
public:
    explicit View(QWidget *parent = 0);
    ~View();
public slots:
    void draw(int);
private:
    turtle turt;
};

#endif // VIEW_H
