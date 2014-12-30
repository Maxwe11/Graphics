#include "paraboliccylinder.h"
#include <QtCore/QDebug>
#include "primitives.h"

ParabolicCylinder::ParabolicCylinder() : mParameter(1.0f)
{
}

void ParabolicCylinder::setParabolaParameter(float value)
{
    mParameter = value;
    mFaces.clear();
}

void ParabolicCylinder::build() const
{
    QVector<QVector4D> vec;
    vec.reserve(200);

    for (float i = 0.0f, end = 5.4f, step = 0.6f; i < end; i += step)
        vec.push_back(QVector4D(i, mParameter * i * i, 0.0f, 1.0f));

    QMatrix4x4 reflection;
    reflection(0, 0) = -1.0f;

    QVector<Face3D> direct, reflected;
    direct.reserve(20);
    reflected.reserve(20);

    for (float z = 0.0f; z < 9.0f; z += 1.5)
    {
        for (int i = 0; i < vec.size() - 1; ++i)
        {
            auto p1 = vec[i], p2 = vec[i];
            auto p3 = vec[i + 1], p4 = vec[i + 1];
            p1.setZ(z);
            p2.setZ(z + 1.5f);
            p3.setZ(z);
            p4.setZ(z + 1.5f);

            Face3D face{p3, p2, p1};
            direct.push_back(face);

            face = {p2, p3, p1};
            face.transform(reflection);
            reflected.push_front(face);

            face = {p2, p3, p4};
            direct.push_back(face);

            face = {p3, p2, p4};
            face.transform(reflection);
            reflected.push_front(face);
        }

        mFaces += reflected;
        mFaces += direct;

        reflected.clear();
        direct.clear();
    }

    mTransformation.setToIdentity();
}
