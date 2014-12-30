#include "cube.h"

Cube::Cube()
{
}

void Cube::build() const
{
    static const float side = 10.0f;

    mFaces.push_back(Face3D({0.0f, 0.0f, 0.0f, 1.0f}, {0.0f, side, 0.0f, 1.0f}, {side, side, 0.0f, 1.0f}));
    mFaces.push_back(Face3D({side, 0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 0.0f, 1.0f}, {side, side, 0.0f, 1.0f}));

    mFaces.push_back(Face3D({side, side, 0.0f, 1.0f}, {side, 0.0f, side, 1.0f}, {side, 0.0f, 0.0f, 1.0f}));
    mFaces.push_back(Face3D({side, side, 0.0f, 1.0f}, {side, side, side, 1.0f}, {side, 0.0f, side, 1.0f}));

    mFaces.push_back(Face3D({0.0f, 0.0f, side, 1.0f}, {0.0f, side, 0.0f, 1.0f}, {0.0f, 0.0f, 0.0f, 1.0f}));
    mFaces.push_back(Face3D({0.0f, side, side, 1.0f}, {0.0f, side, 0.0f, 1.0f}, {0.0f, 0.0f, side, 1.0f}));

    mFaces.push_back(Face3D({0.0f, side, side, 1.0f}, {0.0f, 0.0f, side, 1.0f}, {side, side, side, 1.0f}));
    mFaces.push_back(Face3D({0.0f, 0.0f, side, 1.0f}, {side, 0.0f, side, 1.0f}, {side, side, side, 1.0f}));
//дно
    mFaces.push_back(Face3D({0.0f, 0.0f, side, 1.0f}, {0.0f, 0.0f, 0.0f, 1.0f}, {side, 0.0f, 0.0f, 1.0f}));
    mFaces.push_back(Face3D({side, 0.0f, 0.0f, 1.0f}, {side, 0.0f, side, 1.0f}, {0.0f, 0.0f, side, 1.0f}));
//крыша
    mFaces.push_back(Face3D({0.0f, side, 0.0f, 1.0f}, {0.0f, side, side, 1.0f}, {side, side, 0.0f, 1.0f}));
    mFaces.push_back(Face3D({side, side, side, 1.0f}, {side, side, 0.0f, 1.0f}, {0.0f, side, side, 1.0f}));
}
