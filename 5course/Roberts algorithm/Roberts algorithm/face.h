#ifndef FACE_H
#define FACE_H

#include <QtGui/QVector4D>
#include <QtCore/QDataStream>
#include "graphicsobject.h"

class GLWidget;

class Face3D : public GraphicsObject
{
public:
    static GLWidget* mGl;
public:
    Face3D() {}
    Face3D(const QVector4D &p1, const QVector4D &p2, const QVector4D &p3);

    void draw() const override;
    void draw(const QMatrix4x4 &projection) const override;
    void drawNormal(const QMatrix4x4 &projection) const;
    void transform(const QMatrix4x4 &transformation)  override;
    QVector4D buildNormal(const QVector4D &p = QVector4D()) const;
//private:
    QVector4D mPoints[3];
    int mDepth[3];
};



#endif // FACE_H
