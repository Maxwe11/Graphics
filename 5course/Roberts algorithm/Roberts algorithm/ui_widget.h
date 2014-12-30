/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    GLWidget *glWidget;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *XTransl;
    QSpinBox *YTransl;
    QSpinBox *ZTransl;
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QSpinBox *XRot;
    QSpinBox *YRot;
    QSpinBox *ZRot;
    QLabel *label_5;
    QLabel *label_6;
    QGroupBox *groupBox_4;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *label_7;
    QSpinBox *projectionA;
    QLabel *label_9;
    QDoubleSpinBox *projectionF;
    QGroupBox *groupBox_5;
    QRadioButton *surface_1;
    QRadioButton *surface_2;
    QLabel *label_8;
    QPushButton *curvePoints;
    QDoubleSpinBox *parabParam;
    QCheckBox *showNormals;
    QCheckBox *shading;
    QGroupBox *groupBox_6;
    QRadioButton *orthoProjection;
    QRadioButton *surface_6;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(760, 570);
        glWidget = new GLWidget(Widget);
        glWidget->setObjectName(QStringLiteral("glWidget"));
        glWidget->setGeometry(QRect(10, 10, 630, 551));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(650, 360, 100, 100));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 81, 74));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        XTransl = new QSpinBox(formLayoutWidget);
        XTransl->setObjectName(QStringLiteral("XTransl"));
        XTransl->setMinimum(-10);
        XTransl->setMaximum(10);

        formLayout->setWidget(0, QFormLayout::FieldRole, XTransl);

        YTransl = new QSpinBox(formLayoutWidget);
        YTransl->setObjectName(QStringLiteral("YTransl"));
        YTransl->setMinimum(-10);
        YTransl->setMaximum(10);

        formLayout->setWidget(1, QFormLayout::FieldRole, YTransl);

        ZTransl = new QSpinBox(formLayoutWidget);
        ZTransl->setObjectName(QStringLiteral("ZTransl"));
        ZTransl->setMinimum(-10);
        ZTransl->setMaximum(10);

        formLayout->setWidget(2, QFormLayout::FieldRole, ZTransl);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(650, 460, 100, 100));
        formLayoutWidget_2 = new QWidget(groupBox_2);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 20, 81, 74));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(formLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        XRot = new QSpinBox(formLayoutWidget_2);
        XRot->setObjectName(QStringLiteral("XRot"));
        XRot->setMinimum(-360);
        XRot->setMaximum(360);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, XRot);

        YRot = new QSpinBox(formLayoutWidget_2);
        YRot->setObjectName(QStringLiteral("YRot"));
        YRot->setMinimum(-360);
        YRot->setMaximum(360);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, YRot);

        ZRot = new QSpinBox(formLayoutWidget_2);
        ZRot->setObjectName(QStringLiteral("ZRot"));
        ZRot->setMinimum(-360);
        ZRot->setMaximum(360);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, ZRot);

        label_5 = new QLabel(formLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(formLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_6);

        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(650, 270, 100, 81));
        formLayoutWidget_3 = new QWidget(groupBox_4);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(10, 20, 81, 48));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(formLayoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_7);

        projectionA = new QSpinBox(formLayoutWidget_3);
        projectionA->setObjectName(QStringLiteral("projectionA"));
        projectionA->setMinimum(0);
        projectionA->setMaximum(90);
        projectionA->setValue(45);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, projectionA);

        label_9 = new QLabel(formLayoutWidget_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_9);

        projectionF = new QDoubleSpinBox(formLayoutWidget_3);
        projectionF->setObjectName(QStringLiteral("projectionF"));
        projectionF->setMinimum(-5);
        projectionF->setMaximum(5);
        projectionF->setSingleStep(0.05);
        projectionF->setValue(1);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, projectionF);

        groupBox_5 = new QGroupBox(Widget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(650, 10, 100, 181));
        surface_1 = new QRadioButton(groupBox_5);
        surface_1->setObjectName(QStringLiteral("surface_1"));
        surface_1->setGeometry(QRect(10, 20, 82, 17));
        surface_1->setChecked(false);
        surface_2 = new QRadioButton(groupBox_5);
        surface_2->setObjectName(QStringLiteral("surface_2"));
        surface_2->setGeometry(QRect(10, 40, 82, 17));
        surface_2->setChecked(true);
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 100, 81, 21));
        curvePoints = new QPushButton(groupBox_5);
        curvePoints->setObjectName(QStringLiteral("curvePoints"));
        curvePoints->setGeometry(QRect(10, 150, 81, 21));
        parabParam = new QDoubleSpinBox(groupBox_5);
        parabParam->setObjectName(QStringLiteral("parabParam"));
        parabParam->setGeometry(QRect(10, 120, 62, 22));
        parabParam->setDecimals(1);
        parabParam->setMinimum(-5);
        parabParam->setMaximum(5);
        parabParam->setSingleStep(0.5);
        parabParam->setValue(1);
        showNormals = new QCheckBox(groupBox_5);
        showNormals->setObjectName(QStringLiteral("showNormals"));
        showNormals->setGeometry(QRect(10, 60, 70, 17));
        shading = new QCheckBox(groupBox_5);
        shading->setObjectName(QStringLiteral("shading"));
        shading->setGeometry(QRect(10, 80, 70, 17));
        groupBox_6 = new QGroupBox(Widget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(650, 200, 100, 61));
        orthoProjection = new QRadioButton(groupBox_6);
        orthoProjection->setObjectName(QStringLiteral("orthoProjection"));
        orthoProjection->setGeometry(QRect(10, 20, 82, 17));
        orthoProjection->setChecked(true);
        surface_6 = new QRadioButton(groupBox_6);
        surface_6->setObjectName(QStringLiteral("surface_6"));
        surface_6->setGeometry(QRect(10, 40, 82, 17));

        retranslateUi(Widget);
        QObject::connect(XTransl, SIGNAL(valueChanged(int)), glWidget, SLOT(translateX(int)));
        QObject::connect(YTransl, SIGNAL(valueChanged(int)), glWidget, SLOT(translateY(int)));
        QObject::connect(ZTransl, SIGNAL(valueChanged(int)), glWidget, SLOT(translateZ(int)));
        QObject::connect(XRot, SIGNAL(valueChanged(int)), glWidget, SLOT(rotateX(int)));
        QObject::connect(YRot, SIGNAL(valueChanged(int)), glWidget, SLOT(rotateY(int)));
        QObject::connect(ZRot, SIGNAL(valueChanged(int)), glWidget, SLOT(rotateZ(int)));
        QObject::connect(projectionA, SIGNAL(valueChanged(int)), glWidget, SLOT(projectionA(int)));
        QObject::connect(projectionF, SIGNAL(valueChanged(double)), glWidget, SLOT(projectionF(double)));
        QObject::connect(surface_1, SIGNAL(toggled(bool)), glWidget, SLOT(changeSurface(bool)));
        QObject::connect(parabParam, SIGNAL(valueChanged(double)), glWidget, SLOT(parabolaParam(double)));
        QObject::connect(showNormals, SIGNAL(toggled(bool)), glWidget, SLOT(showNormalsForFace(bool)));
        QObject::connect(curvePoints, SIGNAL(clicked()), glWidget, SLOT(editCurve()));
        QObject::connect(orthoProjection, SIGNAL(toggled(bool)), glWidget, SLOT(changeProjection(bool)));
        QObject::connect(shading, SIGNAL(toggled(bool)), glWidget, SLOT(setShadind(bool)));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        groupBox->setTitle(QApplication::translate("Widget", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265", 0));
        label->setText(QApplication::translate("Widget", "X:", 0));
        label_2->setText(QApplication::translate("Widget", "Y:", 0));
        label_3->setText(QApplication::translate("Widget", "Z:", 0));
        groupBox_2->setTitle(QApplication::translate("Widget", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265", 0));
        label_4->setText(QApplication::translate("Widget", "X:", 0));
        label_5->setText(QApplication::translate("Widget", "Y:", 0));
        label_6->setText(QApplication::translate("Widget", "Z:", 0));
        groupBox_4->setTitle(QApplication::translate("Widget", "\320\232\320\276\321\201\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\260\321\217 \320\277\321\200.", 0));
        label_7->setText(QApplication::translate("Widget", "a:", 0));
        label_9->setText(QApplication::translate("Widget", "f:", 0));
        groupBox_5->setTitle(QApplication::translate("Widget", "\320\236\320\261\321\212\320\265\320\272\321\202", 0));
        surface_1->setText(QApplication::translate("Widget", "\320\242\320\265\320\273\320\276 1", 0));
        surface_2->setText(QApplication::translate("Widget", "\320\242\320\265\320\273\320\276 2", 0));
        label_8->setText(QApplication::translate("Widget", "\320\232\320\276\320\265\321\204. \320\277\320\260\321\200\320\260\320\261\320\276\320\273\321\213:", 0));
        curvePoints->setText(QApplication::translate("Widget", "\320\242\320\276\321\207\320\272\320\270 \320\272\321\200\320\270\320\262\320\276\320\271", 0));
        showNormals->setText(QApplication::translate("Widget", "\320\275\320\276\321\200\320\274\320\260\320\273\320\270", 0));
        shading->setText(QApplication::translate("Widget", "\320\267\320\260\320\272\321\200\320\260\321\201\320\272\320\260", 0));
        groupBox_6->setTitle(QApplication::translate("Widget", "\320\237\321\200\320\276\320\265\320\272\321\206\320\270\321\217", 0));
        orthoProjection->setText(QApplication::translate("Widget", "\320\272\320\276\321\201\320\276\321\203\320\263\320\276\320\273-\321\217", 0));
        surface_6->setText(QApplication::translate("Widget", "\320\276\321\200\321\202\320\276\320\263\320\276\320\275\320\260\320\273-\321\217", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
