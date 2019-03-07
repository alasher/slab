#ifndef scene_hpp
#define scene_hpp

#include "camera.hpp"
#include "object.hpp"

#include <vector>

namespace slab {
    class Scene {
       public:
        Scene();
        virtual ~Scene();
        void attachCamera(const Camera *cam);
        void addObject(const Camera *obj);
        void addObject(const Object *obj);
        inline bool hasCamera() const {
            return has_camera;
        }
        inline const std::vector<const Object *> &getObjects() const {
            return objects;
        }
        inline const Camera &getCamera() const {
            return *camera;
        }

       private:
        bool has_camera;
        const Camera *camera;  // TODO: Change this. See camera.hpp

        // TODO: Make something more efficient than this!
        // This is just a placeholder for testing.
        std::vector<const Object *> objects;
    };
}  // namespace slab

#endif /* scene_hpp */
