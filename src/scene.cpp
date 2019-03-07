#include <slab/scene.hpp>

namespace slab {

    Scene::Scene() : has_camera(false) {
    }

    Scene::~Scene() {
    }

    void Scene::attachCamera(const Camera *cam) {
        if (cam == nullptr) return;

        has_camera = true;
        camera = cam;
    }

    void Scene::addObject(const Camera *cam) {
        attachCamera(cam);
    }

    void Scene::addObject(const Object *obj) {
        if (obj->isRenderable()) {
            objects.push_back(obj);
        }
    }

}  // namespace slab
