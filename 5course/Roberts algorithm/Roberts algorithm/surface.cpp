#include "surface.h"

Surface::Surface() : mDrawNormals(false), mShading(false)
{
}

void Surface::draw() const
{
    if (!isVisible())
        return;

    if (mFaces.empty())
        build();

    for (int i = 0; i < mFaces.size(); ++i)
    {
        auto n1 = mFaces[i].buildNormal(mFaces[i].mPoints[0]);
        mFaces[i].setVisible(n1.z() <= 0.0);
        mFaces[i].draw();
    }
}

void Surface::draw(const QMatrix4x4 &projection) const
{
    if (!isVisible())
        return;

    if (mFaces.empty())
        build();

    static const QVector4D sun(10.0f, 10.0f, -10.0f, 0.0f);
    QVector4D tsun = projection.map(sun);

    if (!mShading)
    {
        for (int i = 0; i < mFaces.size(); ++i)
        {
            auto face = mFaces[i];
            face.transform(projection);
            auto n1 = face.buildNormal(face.mPoints[0]);
            mFaces[i].setVisible(n1.z() <= 0.0);
            mFaces[i].draw(projection);
        }
        return;
    }

    QVector<Face3D> transformed;
    for (int i = 0; i < mFaces.size(); ++i)
    {
        auto face = mFaces[i];
        face.transform(projection);
        auto n1 = face.buildNormal(face.mPoints[0]);
        if (n1.z() <= 0.0)
            transformed.push_back(face);
    }

    for (int i = 0; i < transformed.size(); ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            QVector<std::pair<Face3D, int>> neighbors;
            for (int k = 0; k < transformed.size(); ++k)
            {
                for (int q = 0; q < 3; ++q)
                {
                    if (i != k && transformed[i].mPoints[j] == transformed[k].mPoints[q])
                        neighbors.push_back(std::make_pair(transformed[k], q));
                }
            }

            if (neighbors.empty())
                continue;

            QVector4D norm;
            for (int k = 0; k < neighbors.size(); ++k)
                norm += neighbors[k].first.buildNormal(/*neighbors[k].first.mPoints[neighbors[k].second]*/);

            norm /= neighbors.size();
            auto cosA = (norm.x() * tsun.x() + norm.y() * tsun.y() + norm.z() * tsun.z()) / (norm.length() * tsun.length());
            if (acos(cosA) > 180.0)
                cosA = 0.0;
            transformed[i].mDepth[j] = 20000 * cosA / tsun.length();

            if (transformed[i].mDepth[j] > 255)
                transformed[i].mDepth[j] = 255;
            else if (transformed[i].mDepth[j] < 0)
                transformed[i].mDepth[j] = 0;
        }

        transformed[i].draw();
    }
}

void Surface::transform(const QMatrix4x4 &transformation)
{
    if (mFaces.empty())
        build();

    for (int i = 0; i < mFaces.size(); ++i)
        mFaces[i].transform(transformation);

    mTransformation += transformation;
}

void Surface::drawNormals(const QMatrix4x4 &projection) const
{
    if (isVisible() && isNormalsDrawn())
    {
        for (int i = 0; i < mFaces.size(); ++i)
            mFaces[i].drawNormal(projection);
    }
}

void Surface::setDrawNormals(bool value)
{
    mDrawNormals = value;
}

bool Surface::isNormalsDrawn() const
{
    return mDrawNormals;
}

void Surface::setShading(bool value)
{
    mShading = value;
}
