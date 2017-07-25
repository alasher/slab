//
//  scene.hpp
//  slab
//
//  Created by Austin Lasher on 7/23/17.
//
//

#ifndef scene_hpp
#define scene_hpp

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

#endif /* scene_hpp */
