/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGraphicsView *graphicsView;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(220, 354);
        graphicsView = new QGraphicsView(Dialog);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 200, 240));
        doubleSpinBox = new QDoubleSpinBox(Dialog);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(40, 260, 62, 22));
        doubleSpinBox->setMinimum(1);
        doubleSpinBox->setMaximum(1000.99);
        doubleSpinBox->setValue(100);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 260, 21, 16));
        doubleSpinBox_2 = new QDoubleSpinBox(Dialog);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(140, 260, 62, 22));
        doubleSpinBox_2->setMinimum(1);
        doubleSpinBox_2->setMaximum(1000.99);
        doubleSpinBox_2->setValue(100);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 260, 21, 16));
        doubleSpinBox_3 = new QDoubleSpinBox(Dialog);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(40, 290, 62, 22));
        doubleSpinBox_3->setMinimum(1);
        doubleSpinBox_3->setMaximum(1000.99);
        doubleSpinBox_3->setValue(100);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 290, 21, 16));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 320, 75, 23));

        retranslateUi(Dialog);
        QObject::connect(doubleSpinBox, SIGNAL(valueChanged(double)), Dialog, SLOT(setW1(double)));
        QObject::connect(doubleSpinBox_2, SIGNAL(valueChanged(double)), Dialog, SLOT(setW2(double)));
        QObject::connect(doubleSpinBox_3, SIGNAL(valueChanged(double)), Dialog, SLOT(setW3(double)));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        label->setText(QApplication::translate("Dialog", "W1", 0));
        label_2->setText(QApplication::translate("Dialog", "W2", 0));
        label_3->setText(QApplication::translate("Dialog", "W3", 0));
        pushButton->setText(QApplication::translate("Dialog", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
