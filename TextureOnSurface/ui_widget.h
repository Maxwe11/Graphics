/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Wed 21. Dec 10:59:22 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QGroupBox *groupBox_3;
    QDoubleSpinBox *paramSpinBox;
    QWidget *formLayoutWidget_4;
    QFormLayout *formLayout_4;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QGroupBox *groupBox_4;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *label_7;
    QLabel *label_8;
    QDoubleSpinBox *UTransl;
    QDoubleSpinBox *VTransl;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(760, 495);
        glWidget = new GLWidget(Widget);
        glWidget->setObjectName(QString::fromUtf8("glWidget"));
        glWidget->setGeometry(QRect(10, 10, 630, 470));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(650, 10, 100, 100));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 81, 74));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        XTransl = new QSpinBox(formLayoutWidget);
        XTransl->setObjectName(QString::fromUtf8("XTransl"));
        XTransl->setMinimum(-10);
        XTransl->setMaximum(10);

        formLayout->setWidget(0, QFormLayout::FieldRole, XTransl);

        YTransl = new QSpinBox(formLayoutWidget);
        YTransl->setObjectName(QString::fromUtf8("YTransl"));
        YTransl->setMinimum(-10);
        YTransl->setMaximum(10);

        formLayout->setWidget(1, QFormLayout::FieldRole, YTransl);

        ZTransl = new QSpinBox(formLayoutWidget);
        ZTransl->setObjectName(QString::fromUtf8("ZTransl"));
        ZTransl->setMinimum(-10);
        ZTransl->setMaximum(10);

        formLayout->setWidget(2, QFormLayout::FieldRole, ZTransl);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(650, 120, 100, 100));
        formLayoutWidget_2 = new QWidget(groupBox_2);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 20, 81, 74));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(formLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        XRot = new QSpinBox(formLayoutWidget_2);
        XRot->setObjectName(QString::fromUtf8("XRot"));
        XRot->setMinimum(-360);
        XRot->setMaximum(360);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, XRot);

        YRot = new QSpinBox(formLayoutWidget_2);
        YRot->setObjectName(QString::fromUtf8("YRot"));
        YRot->setMinimum(-360);
        YRot->setMaximum(360);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, YRot);

        ZRot = new QSpinBox(formLayoutWidget_2);
        ZRot->setObjectName(QString::fromUtf8("ZRot"));
        ZRot->setMinimum(-360);
        ZRot->setMaximum(360);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, ZRot);

        label_5 = new QLabel(formLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(formLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_6);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(650, 320, 100, 131));
        paramSpinBox = new QDoubleSpinBox(groupBox_3);
        paramSpinBox->setObjectName(QString::fromUtf8("paramSpinBox"));
        paramSpinBox->setGeometry(QRect(10, 20, 81, 20));
        paramSpinBox->setMinimum(-10);
        paramSpinBox->setMaximum(10);
        paramSpinBox->setSingleStep(0.5);
        paramSpinBox->setValue(4);
        formLayoutWidget_4 = new QWidget(groupBox_3);
        formLayoutWidget_4->setObjectName(QString::fromUtf8("formLayoutWidget_4"));
        formLayoutWidget_4->setGeometry(QRect(10, 50, 84, 71));
        formLayout_4 = new QFormLayout(formLayoutWidget_4);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(formLayoutWidget_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(240, 1, 5, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 106, 108, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(247, 53, 56, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(120, 0, 2, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(160, 0, 3, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(247, 128, 130, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label_9->setPalette(palette);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_9);

        label_11 = new QLabel(formLayoutWidget_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_11);

        label_12 = new QLabel(formLayoutWidget_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_12);

        label_15 = new QLabel(formLayoutWidget_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush9(QColor(255, 0, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush9);
        QBrush brush10(QColor(255, 127, 127, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush10);
        QBrush brush11(QColor(255, 63, 63, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        QBrush brush12(QColor(127, 0, 0, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush12);
        QBrush brush13(QColor(170, 0, 0, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label_15->setPalette(palette1);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_15->setFont(font);
        label_15->setAutoFillBackground(true);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, label_15);

        label_16 = new QLabel(formLayoutWidget_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush14(QColor(0, 0, 255, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush14);
        QBrush brush15(QColor(127, 127, 255, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush15);
        QBrush brush16(QColor(63, 63, 255, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush16);
        QBrush brush17(QColor(0, 0, 127, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush17);
        QBrush brush18(QColor(0, 0, 170, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush18);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush14);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush15);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush16);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush17);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush18);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush18);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label_16->setPalette(palette2);
        label_16->setFont(font);
        label_16->setAutoFillBackground(true);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, label_16);

        label_17 = new QLabel(formLayoutWidget_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush19(QColor(85, 255, 0, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush19);
        QBrush brush20(QColor(170, 255, 127, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush20);
        QBrush brush21(QColor(127, 255, 63, 255));
        brush21.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush21);
        QBrush brush22(QColor(42, 127, 0, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush22);
        QBrush brush23(QColor(56, 170, 0, 255));
        brush23.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush23);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush19);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush20);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush19);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush20);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush21);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush22);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush23);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush19);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush20);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush22);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush19);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush20);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush21);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush22);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush23);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush22);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush22);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush19);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush19);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush19);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label_17->setPalette(palette3);
        label_17->setFont(font);
        label_17->setAutoFillBackground(true);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, label_17);

        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(650, 230, 100, 81));
        formLayoutWidget_3 = new QWidget(groupBox_4);
        formLayoutWidget_3->setObjectName(QString::fromUtf8("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(10, 20, 81, 51));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(formLayoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(formLayoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_8);

        UTransl = new QDoubleSpinBox(formLayoutWidget_3);
        UTransl->setObjectName(QString::fromUtf8("UTransl"));
        UTransl->setMinimum(0);
        UTransl->setMaximum(6.28);
        UTransl->setSingleStep(0.1);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, UTransl);

        VTransl = new QDoubleSpinBox(formLayoutWidget_3);
        VTransl->setObjectName(QString::fromUtf8("VTransl"));
        VTransl->setMaximum(6.28);
        VTransl->setSingleStep(0.1);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, VTransl);


        retranslateUi(Widget);
        QObject::connect(XTransl, SIGNAL(valueChanged(int)), glWidget, SLOT(translateX(int)));
        QObject::connect(YTransl, SIGNAL(valueChanged(int)), glWidget, SLOT(translateY(int)));
        QObject::connect(ZTransl, SIGNAL(valueChanged(int)), glWidget, SLOT(translateZ(int)));
        QObject::connect(XRot, SIGNAL(valueChanged(int)), glWidget, SLOT(rotateX(int)));
        QObject::connect(YRot, SIGNAL(valueChanged(int)), glWidget, SLOT(rotateY(int)));
        QObject::connect(ZRot, SIGNAL(valueChanged(int)), glWidget, SLOT(rotateZ(int)));
        QObject::connect(paramSpinBox, SIGNAL(valueChanged(double)), glWidget, SLOT(changeParam(double)));
        QObject::connect(UTransl, SIGNAL(valueChanged(double)), glWidget, SLOT(translateU(double)));
        QObject::connect(VTransl, SIGNAL(valueChanged(double)), glWidget, SLOT(translateV(double)));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, 0));
        groupBox->setTitle(QApplication::translate("Widget", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265", 0, 0));
        label->setText(QApplication::translate("Widget", "X:", 0, 0));
        label_2->setText(QApplication::translate("Widget", "Y:", 0, 0));
        label_3->setText(QApplication::translate("Widget", "Z:", 0, 0));
        groupBox_2->setTitle(QApplication::translate("Widget", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265", 0, 0));
        label_4->setText(QApplication::translate("Widget", "X:", 0, 0));
        label_5->setText(QApplication::translate("Widget", "Y:", 0, 0));
        label_6->setText(QApplication::translate("Widget", "Z:", 0, 0));
        groupBox_3->setTitle(QApplication::translate("Widget", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", 0, 0));
        label_9->setText(QApplication::translate("Widget", "X", 0, 0));
        label_11->setText(QApplication::translate("Widget", "Y", 0, 0));
        label_12->setText(QApplication::translate("Widget", "Z", 0, 0));
        label_15->setText(QString());
        label_16->setText(QString());
        label_17->setText(QString());
        groupBox_4->setTitle(QApplication::translate("Widget", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", 0, 0));
        label_7->setText(QApplication::translate("Widget", "U:", 0, 0));
        label_8->setText(QApplication::translate("Widget", "V:", 0, 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
