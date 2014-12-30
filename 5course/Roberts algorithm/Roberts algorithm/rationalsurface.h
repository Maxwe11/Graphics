#ifndef RATIONALSURFACE_H
#define RATIONALSURFACE_H

#include "surface.h"

class RationalSurface : public Surface
{
public:
    RationalSurface();

    void setPoints(const  QVector<QVector4D>& points);
    QVector<QVector4D> getPoints() const;
private:
    void build() const override;
private:
    QVector<QVector4D> mPoints;
};

#endif // RATIONALSURFACE_H
