//
//  camera.hpp
//  slab
//
//  Created by Austin Lasher on 7/24/17.
//
//

#ifndef camera_hpp
#define camera_hpp

#include "object.hpp"

namespace Slab
{
    class Camera : public Object
    {
    public:
        Camera(int x = 0, int y = 0, int z = 0);
        const float *getVertices() final;
    };
}

#endif /* camera_hpp */
