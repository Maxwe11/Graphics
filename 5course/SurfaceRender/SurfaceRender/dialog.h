#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <QtCore/QVector>
#include <QMatrix4x4>

namespace Ui {
class Dialog;
}

class Point;
class Bezier;

class Dialog : public QDialog
{
    Q_OBJECT    
public:
    explicit Dialog(QVector<QVector4D>& vec, QWidget *parent = 0);
    ~Dialog();  
private slots:
    void on_pushButton_clicked();
    void setW1(double);
    void setW2(double);
    void setW3(double);
private:
    Ui::Dialog *ui;
    QVector<QVector4D>& mVec;
    QGraphicsScene mScene;
    QVector<Point*> mPoints;
    Bezier* mBezier;
};

#endif // DIALOG_H
