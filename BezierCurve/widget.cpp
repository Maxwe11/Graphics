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
    this->ui->graphicsView->resize(width() - 130, height() - 20);
    this->ui->groupBox->move(width() - 110, 10);
    this->ui->groupBox2->move(width() - 110, 140);
}
