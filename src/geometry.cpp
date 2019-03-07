#include <slab/geometry.hpp>

namespace slab {

    void Geometry::addPoint(const float x, const float y, const float z) {
        points.push_back(x);
        points.push_back(y);
        points.push_back(z);
    }

    void Geometry::addPoint(const Point3D &p) {
        addPoint(p.x, p.y, p.z);
    }

    // Points added this way must be given in groups of three. Otherwise we won't know what
    // dimension each component is.
    void Geometry::addPoints(const unsigned int numPoints, const float *p) {
        if (p == nullptr) return;
        if (numPoints == 0 || numPoints % 3 != 0) return;

        for (int i = 0; i < numPoints; i += 3) {
            addPoint(p[i], p[i + 1], p[i + 2]);
        }
    }

    void Geometry::addPoints(const unsigned int numPoints, const Point3D *p) {
        if (p == nullptr) return;

        for (int i = 0; i < numPoints; ++i) {
            addPoint(p[i]);
        }
    }

}  // namespace slab
