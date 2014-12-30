#include <QDebug>

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    qDebug() << "widget destr called";
    delete ui;
}

void Widget::resizeEvent(QResizeEvent*)
{
    QSize size(width() - 20, height() - 20);

    this->ui->graphicsView->resize(size);

    size.rheight() -= 5;
    size.rwidth() -= 5;
    this->ui->graphicsView->scene()->setSceneRect(-0.5 * size.width(), 0.5 * size.height(), size.width(), -size.height());

    qDebug() << "w: " << this->ui->graphicsView->width();
    qDebug() << "h: " << this->ui->graphicsView->height();
}
