#include <slab/object.hpp>

namespace slab {

    Object::Object(int x, int y, int z) {
        moveTo(x, y, z);
    }

    Object::~Object() {
    }

    void Object::moveTo(int x, int y, int z) {
        position[0] = x;
        position[1] = y;
        position[2] = z;
    }

    void Object::push(int x, int y, int z) {
        moveTo(position[0] + x, position[1] + y, position[2] + z);
    }

}  // namespace slab
