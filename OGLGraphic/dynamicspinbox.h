#ifndef DYNAMICSPINBOX_H
#define DYNAMICSPINBOX_H

#include <QSpinBox>

class DynamicSpinBox : public QSpinBox {
    Q_OBJECT
public:
    DynamicSpinBox(QWidget* parent = 0);
    void init(int min, int max, int val);
public slots:
    void SetMaxValue(int);
    void SetMinValue(int);
};

#endif // DYNAMICSPINBOX_H
