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
    this->ui->glWidget->resize(this->width() - 130, this->height() - 20);
    this->ui->groupBox->move(this->width() - 110, 10);
    this->ui->groupBox_2->move(this->width() - 110, 120);
    this->ui->groupBox_3->move(this->width() - 110, 320);
    this->ui->groupBox_4->move(this->width() - 110, 230);
}
