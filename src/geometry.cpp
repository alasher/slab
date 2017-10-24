//
//  Geometry.cpp
//  slab
//
//  Created by Austin Lasher on 10/22/17.
//

#include <slab/geometry.hpp>

void Slab::Geometry::addPoint(const float x, const float y, const float z)
{
    points.push_back(x);
    points.push_back(y);
    points.push_back(z);
}

void Slab::Geometry::addPoint(const Point3D &p)
{
    points.push_back(p.x);
    points.push_back(p.y);
    points.push_back(p.z);
}

void Slab::Geometry::addPoints(const unsigned int numPoints, const float *p)
{
    if (p == nullptr) return;

    for(int i = 0; i < numPoints; ++i)
    {
        points.push_back(p[i]);
    }
}

void Slab::Geometry::addPoints(const unsigned int numPoints, const Point3D *p)
{
    if (p == nullptr) return;

    for(int i = 0; i < numPoints; ++i)
    {
        points.push_back(p[i].x);
        points.push_back(p[i].y);
        points.push_back(p[i].z);
    }
}
