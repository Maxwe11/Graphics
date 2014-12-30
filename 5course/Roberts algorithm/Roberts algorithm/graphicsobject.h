#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include <QtGui/QMatrix4x4>

class GraphicsObject
{
public:
    explicit GraphicsObject();
    virtual ~GraphicsObject() {}
public:
    virtual void draw() const = 0;
    virtual void draw(const QMatrix4x4& projection) const = 0;
    virtual void transform(const QMatrix4x4& transformation) = 0;

    void setVisible(bool visible);
    bool isVisible() const;
private:
    bool mVisible;
};

#endif // GRAPHICSOBJECT_H
