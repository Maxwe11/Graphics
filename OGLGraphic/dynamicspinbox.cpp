#include "dynamicspinbox.h"

DynamicSpinBox::DynamicSpinBox(QWidget* parent)
    : QSpinBox(parent)
{
}

void DynamicSpinBox::SetMaxValue(int val)
{
    this->setMaximum(val);
}

void DynamicSpinBox::SetMinValue(int val)
{
    this->setMinimum(val);
}

void DynamicSpinBox::init(int min, int max, int val)
{
    this->setMinimum(min);
    this->setMaximum(max);
    this->setValue(val);
}
