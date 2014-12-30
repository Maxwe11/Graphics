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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "view.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    View *graphicsView;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *addButton;
    QRadioButton *editButton;
    QCheckBox *showPoints;
    QCheckBox *showLines;
    QGroupBox *groupBox2;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *duckButton;
    QPushButton *sharkButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(850, 480);
        graphicsView = new View(Widget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 721, 460));
        graphicsView->setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);
        graphicsView->setOptimizationFlags(QGraphicsView::IndirectPainting);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(740, 10, 100, 121));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 82, 88));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addButton = new QRadioButton(layoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setChecked(false);

        verticalLayout->addWidget(addButton);

        editButton = new QRadioButton(layoutWidget);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setChecked(true);

        verticalLayout->addWidget(editButton);

        showPoints = new QCheckBox(layoutWidget);
        showPoints->setObjectName(QStringLiteral("showPoints"));
        showPoints->setChecked(true);

        verticalLayout->addWidget(showPoints);

        showLines = new QCheckBox(layoutWidget);
        showLines->setObjectName(QStringLiteral("showLines"));
        showLines->setChecked(true);

        verticalLayout->addWidget(showLines);

        groupBox2 = new QGroupBox(Widget);
        groupBox2->setObjectName(QStringLiteral("groupBox2"));
        groupBox2->setGeometry(QRect(740, 140, 100, 91));
        layoutWidget_3 = new QWidget(groupBox2);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 20, 81, 54));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        duckButton = new QPushButton(layoutWidget_3);
        duckButton->setObjectName(QStringLiteral("duckButton"));

        verticalLayout_3->addWidget(duckButton);

        sharkButton = new QPushButton(layoutWidget_3);
        sharkButton->setObjectName(QStringLiteral("sharkButton"));

        verticalLayout_3->addWidget(sharkButton);


        retranslateUi(Widget);
        QObject::connect(editButton, SIGNAL(toggled(bool)), graphicsView, SLOT(enableEditMode(bool)));
        QObject::connect(duckButton, SIGNAL(clicked()), graphicsView, SLOT(sharkToDuck()));
        QObject::connect(showPoints, SIGNAL(clicked(bool)), graphicsView, SLOT(showPoints(bool)));
        QObject::connect(sharkButton, SIGNAL(clicked()), graphicsView, SLOT(duckToShark()));
        QObject::connect(showLines, SIGNAL(clicked(bool)), graphicsView, SLOT(showLines(bool)));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        groupBox->setTitle(QApplication::translate("Widget", "Options", 0));
        addButton->setText(QApplication::translate("Widget", "add point", 0));
        editButton->setText(QApplication::translate("Widget", "edit points", 0));
        showPoints->setText(QApplication::translate("Widget", "show points", 0));
        showLines->setText(QApplication::translate("Widget", "show lines", 0));
        groupBox2->setTitle(QApplication::translate("Widget", "Animation", 0));
        duckButton->setText(QApplication::translate("Widget", "Duck", 0));
        sharkButton->setText(QApplication::translate("Widget", "Shark", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
