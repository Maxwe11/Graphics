#include "graphicsobject.h"

GraphicsObject::GraphicsObject() : mVisible(true)
{
}

void GraphicsObject::setVisible(bool visible)
{
    mVisible = visible;
}

bool GraphicsObject::isVisible() const
{
    return mVisible;
}
