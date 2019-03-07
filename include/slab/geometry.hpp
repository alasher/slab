#ifndef geometry_h
#define geometry_h

#include <vector>

namespace slab {
    struct Point3D {
        float x, y, z;
    };

    class Geometry {
       public:
        void addPoint(const float x, const float y, const float z);
        void addPoint(const Point3D &p);
        void addPoints(const unsigned int numPoints, const float *p);
        void addPoints(const unsigned int numPoints, const Point3D *p);
        inline size_t size() const {
            return points.size();
        };

       protected:
        std::vector<float> points;
    };
}  // namespace slab

#endif /* geometry_h */
