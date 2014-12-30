#include "dialog.h"
#include "ui_dialog.h"

#include "point.h"
#include "bezier.h"
#include <QtCore/QDebug>

Dialog::Dialog(QVector<QVector4D> &vec, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    mVec(vec)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&mScene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setMatrix(QMatrix(1.0, 0.0, 0.0, -1.0, 0.0, 0.0));
    mScene.setSceneRect(0.0, 0.0, 195.0, 235.0);

    for (int i = 0; i < 3; ++i)
        mPoints.append(new Point(QPointF(mVec[i].x() * 20.0, mVec[i].y() * 20.0), mVec[i].w(), &mScene));

    ui->doubleSpinBox->setValue(mVec[0].w() * 1000.0);
    ui->doubleSpinBox_2->setValue(mVec[1].w() * 1000.0);
    ui->doubleSpinBox_3->setValue(mVec[2].w() * 1000.0);

    mBezier = new Bezier(mPoints[0], mPoints[1], mPoints[2], &mScene);
}

Dialog::~Dialog()
{
    for (auto p : mPoints)
        delete p;

    delete mBezier;

    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    for (int i = 0; i < 3; ++i)
    {
        mVec[i].setX(mPoints[i]->x() / 20.0);
        mVec[i].setY(mPoints[i]->y() / 20.0);
    }

    accept();
}

void Dialog::setW1(double value)
{
    mVec[0].setW(value / 1000.0);
    mPoints[0]->setWeight(mVec[0].w());
    mScene.update(mScene.sceneRect());
}

void Dialog::setW2(double value)
{
    mVec[1].setW(value / 1000.0);
    mPoints[1]->setWeight(mVec[1].w());
    mScene.update(mScene.sceneRect());
}

void Dialog::setW3(double value)
{
    mVec[2].setW(value / 1000.0);
    mPoints[2]->setWeight(mVec[2].w());
    mScene.update(mScene.sceneRect());
}
