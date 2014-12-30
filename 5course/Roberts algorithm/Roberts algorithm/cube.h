#ifndef CUBE_H
#define CUBE_H

#include "surface.h"

class Cube : public Surface
{
public:
    Cube();
    ~Cube() {}
    void build() const override;

//    Face3D mFaces[12];
};

#endif // CUBE_H
