//
//  scene.cpp
//  slab
//
//  Created by Austin Lasher on 7/23/17.
//
//

#include <slab/scene.h>

namespace Slab
{


    Scene::Scene() :
        hasCamera(false)
    {
    }

    Scene::~Scene()
    {
    }

    // TODO: Write camera class
    void Scene::attachCamera()
    {
        hasCamera = true;
    }

}
