#include <slab/triangle.hpp>

namespace slab {

    Triangle::Triangle() : Geometry() {
        addPoint(-1.0, -1.0, 0.0);
        addPoint(0.0, 1.0, 0.0);
        addPoint(1.0, 1.0, 0.0);

        sp = glCreateProgram();
    }

    Triangle::~Triangle() {
        glDeleteProgram(sp);
    }

    const char *Triangle::getPixelShader() {
        return "Testing!!";
    }

}  // namespace slab
