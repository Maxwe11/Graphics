#include <QtCore/QDebug>
#include <string>
#include <QtWidgets/QGraphicsScene>
#include <QtCore/qmath.h>

#include "view.h"

View::View(QWidget *parent)
    : QGraphicsView(parent)
    , turt(20.0, 60.0, turtle::state(0.0, 680.0, 0.0))
{
    this->setRenderHint(QPainter::Antialiasing);
    this->setMatrix(QMatrix(1.0, 0.0, 0.0, -1.0, 0.0, 0.0));
    this->setScene(new QGraphicsScene(0.0, 2.0 * 680.0, 2.0 * 1240.0, -680.0 * 2.0));
}

View::~View()
{
    qDebug() << "view destr called";
}

void View::draw(int amount)
{
    foreach(QGraphicsItem* p, this->scene()->items())
        this->scene()->removeItem(p);

    static const std::string x("[-F+F[Y]+F][+F-F-F]");
//    static const std::string x("[-F+F[Y]+F][+F-F[X]-F");
    static std::string str(x);

    for (int i = 0; i < amount; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            turt.setState(turtle::state(0.0 + i * 30.0, 680.0 + i * 10.0 * qSqrt(3.0) - j * 20.0 * qSqrt(3.0), 0.0));
            for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
            {
                switch (*it)
                {
                case '+':
                    turt.turnLeft();
                    break;
                case '-':
                    turt.turnRight();
                    break;
                case 'F':
                    this->scene()->addLine(QLineF(turt.currentState(), turt.nextStep()));
                    turt.forward();
                    break;
                case '[':
                    turt.pushState();
                    break;
                case ']':
                    turt.popState();
                    break;
                default:
                    break;
                }
            }
        }
    }
    this->scene()->update();
}
