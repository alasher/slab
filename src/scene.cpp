#include <slab/scene.hpp>

namespace Slab
{
    Scene::Scene() :
        has_camera(false)
    {
    }

    Scene::~Scene()
    {
    }

    // TODO: Write camera class
    void Scene::attachCamera(const Camera *cam)
    {
        if (cam == nullptr) return;

        has_camera = true;
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
