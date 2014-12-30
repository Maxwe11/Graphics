#ifndef SURFACE_H
#define SURFACE_H

#include "graphicsobject.h"
#include "face.h"
#include <QtGui/QMatrix4x4>
#include <QtGui/QVector4D>

class Surface : public GraphicsObject
{
public:
    Surface();

    void draw() const override;
    void draw(const QMatrix4x4 &projection) const override;
    void transform(const QMatrix4x4 &transformation) override;

    void drawNormals(const QMatrix4x4& projection) const;

    void setDrawNormals(bool value);
    bool isNormalsDrawn() const;

    void setShading(bool value);
private:
    virtual void build() const = 0;
protected:
    mutable QVector<Face3D> mFaces;
    mutable QMatrix4x4 mTransformation;
private:
    bool mDrawNormals;
    bool mShading;
};

#endif // SURFACE_H
