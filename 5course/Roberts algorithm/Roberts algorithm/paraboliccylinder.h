#ifndef PARABOLICCYLINDER_H
#define PARABOLICCYLINDER_H

#include "surface.h"
#include <QtCore/QVector>

class ParabolicCylinder : public Surface
{
public:
    explicit ParabolicCylinder();

    void setParabolaParameter(float value);
private:
    void build() const override;
private:
    float mParameter;
};

#endif // PARABOLICCYLINDER_H
