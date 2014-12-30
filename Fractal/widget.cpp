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
    delete ui;
}

void Widget::resizeEvent(QResizeEvent*)
{
    this->ui->graphicsView->resize(this->width() - 90, this->height() - 20);
    this->ui->groupBox->move(this->width() - 70, 10);
}

void Widget::on_pushButton_clicked()
{

}
