#include <slab/camera.hpp>

namespace Slab
{

    Camera::Camera(int x, int y, int z) :
        Object(x, y, z)
    {
        
    }

    // TODO: Remove this - move this to a model class
    const float *Camera::getVertices()
    {
        return nullptr;
    }

}
