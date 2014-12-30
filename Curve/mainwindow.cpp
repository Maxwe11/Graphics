#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->AParamEdit, SIGNAL(valueChanged(double)), ui->glWidget->leaf, SLOT(AChanged(double)));
    QObject::connect(ui->glWidget->leaf, SIGNAL(SquareChanged(QString)), ui->Square, SLOT(setText(QString)));
    QObject::connect(ui->glWidget->leaf, SIGNAL(LengthChanged(QString)), ui->Length, SLOT(setText(QString)));
    QObject::connect(ui->DrawTangentLine, SIGNAL(toggled(bool)), ui->glWidget->leaf, SLOT(DrawTangLine(bool)));
    QObject::connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->glWidget->leaf, SLOT(ChangeHotDot(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent* e)
{
    this->ui->glWidget->resize(width() - 20, height() - 150);
    this->ui->tabWidget->move(10, height() - 130);
}
