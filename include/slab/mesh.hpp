#ifndef mesh_h
#define mesh_h

#include "geometry.hpp"
#include "object.hpp"

namespace slab {

    class Mesh : public Object {
       public:
        Mesh(const Geometry &ing);
        inline virtual bool isRenderable() const {
            return true;
        }

       private:
        Geometry geometry;
    };

}  // namespace slab

#endif /* mesh_h */
