//
//  geometry.hpp
//  slab
//
//  Created by Austin Lasher on 10/22/17.
//

#ifndef geometry_h
#define geometry_h

#include <vector>

namespace Slab
{
    struct Point3D
    {
        float x, y, z;
    };

    class Geometry
    {
    public:
        void addPoint(const float x, const float y, const float z);
        void addPoint(const Point3D &p);
        void addPoints(const unsigned int numPoints, const float *p);
        void addPoints(const unsigned int numPoints, const Point3D *p);
    protected:
        std::vector<float> points;
    };
}

#endif /* geometry_h */
