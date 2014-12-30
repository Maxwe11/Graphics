#include <QResizeEvent>

#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    this->ui->setupUi(this);
    this->ui->LEdit->init(0, 450, 160);
    this->ui->HEdit->init(0, 350, 170);
    this->ui->R1Edit->init(0, 500, 32);
    this->ui->R2Edit->init(0, 210, 80);
    this->ui->R3Edit->init(0, 500, 52);
    this->ui->rEdit->init(0, 500, 64);
    this->ui->DEdit->init(0, 500, 50);
    this->ui->dEdit->init(0, 500, 28);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::resizeEvent(QResizeEvent*)
{
    this->ui->ParamsTabWidget->move(10, this->height() - 140);
    this->ui->scene->resize(this->width() - 20, this->height() - 160);
}

void MainWidget::on_Translation_toggled(bool checked)
{
    if (checked == true)
    {
        this->ui->scene->currentTr(1);
        this->reset();
    }
}

void MainWidget::on_Rotation_toggled(bool checked)
{
    if (checked == true)
    {
        this->ui->scene->currentTr(2);
        this->reset();
    }
}

void MainWidget::on_AffineTr_toggled(bool checked)
{
    if (checked == true)
    {
        this->ui->scene->currentTr(3);
        this->ui->AngleEdit->setValue(0);
        this->reset();
    }
}

void MainWidget::on_ProjTr_toggled(bool checked)
{
    if (checked == true)
    {
        this->ui->scene->currentTr(4);
        this->ui->AngleEdit->setValue(0);
        this->reset();
    }
}

void MainWidget::reset()
{
    this->ui->CenterXEdit->setValue(0);
    this->ui->CenterYEdit->setValue(0);
    this->ui->XxEdit->setValue(1);
    this->ui->YxEdit->setValue(0);
    this->ui->XyEdit->setValue(0);
    this->ui->YyEdit->setValue(1);
}
