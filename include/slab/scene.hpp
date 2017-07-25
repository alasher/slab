//
//  scene.hpp
//  slab
//
//  Created by Austin Lasher on 7/23/17.
//
//

#ifndef scene_hpp
#define scene_hpp

#include "camera.hpp"
#include "object.hpp"

#include <vector>

namespace Slab
{
    class Scene
    {
    public:
        Scene();
        virtual ~Scene();
        void attachCamera(const Camera *cam);
        void addObject(const Camera *obj);
        void addObject(const Object *obj);

    private:
        bool hasCamera;
        const Camera *camera;

        // TODO: Make something more efficient than this!
        // This is just a placeholder for testing :)
        // We need a way to reference objects within the scene easily
        // Array of pointers? Shared smart pointers?
        std::vector<const Object *> objects;
    };
}

#endif /* scene_hpp */
