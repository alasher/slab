//
//  scene.h
//  slab
//
//  Created by Austin Lasher on 7/23/17.
//
//

#ifndef scene_h
#define scene_h

namespace Slab
{
    class Scene
    {
    public:
        Scene();
        virtual ~Scene();
        void attachCamera();

    private:
        bool hasCamera;
    };
}

#endif /* scene_h */
