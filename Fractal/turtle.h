#ifndef FRACTAL_H
#define FRACTAL_H

#include <QString>
#include <QPointF>
#include <QStack>
#include <QMap>

class turtle {
public:
    struct state {
        QPointF p;
        qreal angle;

        state(qreal x_ = 0.0, qreal y_ = 0.0, qreal angle_ = 0.0)
            : p(x_, y_), angle(angle_)
        {}
    };
public:
    turtle(qreal len, qreal angl, const state& cur);
    void setState(const state& st);
    void setLength(qreal);
    void setAngle(qreal);
    QPointF nextStep() const;
    QPointF currentState() const;
    //commands
    void forward();   //F
    void turnLeft();  //+
    void turnRight(); //-
    void pushState(); //[
    void popState();  //]
//private:
    qreal length_;
    qreal angle_;
    state current_state;
    QStack< state > stack;
};

#endif // FRACTAL_H
