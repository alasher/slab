//
//  scene.cpp
//  slab
//
//  Created by Austin Lasher on 7/23/17.
//
//

#include <slab/scene.hpp>

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
    void Scene::attachCamera(const Camera *cam)
    {
        if (cam == nullptr) return;

        hasCamera = true;
        camera = cam;
    }

    void Scene::addObject(const Camera *cam)
    {
        attachCamera(cam);
    }

    void Scene::addObject(const Object *obj)
    {
        objects.push_back(obj);
    }
}
