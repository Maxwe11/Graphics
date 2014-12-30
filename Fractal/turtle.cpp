#include <QtCore/qmath.h>

#include "turtle.h"

turtle::turtle(qreal len, qreal angl, const state &cur)
    : length_(len), angle_(angl)
    , current_state(cur)
{
}

void turtle::setState(const state &st)
{
    this->current_state = st;
}

QPointF turtle::nextStep() const
{
    return QPointF(
                    current_state.p.x() + length_ * qCos(current_state.angle * M_PI / 180.0),
                    current_state.p.y() + length_ * qSin(current_state.angle * M_PI / 180.0)
                  );
}

QPointF turtle::currentState() const
{
    return current_state.p;
}

void turtle::forward()
{
    current_state.p = nextStep();
//    current_state.angle = 0.0;
}



void turtle::turnLeft()
{
    current_state.angle += angle_;
}

void turtle::turnRight()
{
    current_state.angle -= angle_;
}

void turtle::pushState()
{
    stack.push(current_state);
}

void turtle::popState()
{
    current_state = stack.pop();
}
