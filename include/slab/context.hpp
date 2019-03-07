//
// Created by alasher on 3/11/17.
//

#ifndef context_hpp
#define context_hpp

#include "window.hpp"
#include "scene.hpp"
#include "geometry.hpp"

namespace Slab
{
    enum class SLAB_STATUS : unsigned short {
        OKAY = 0,
        DESTROYED,
        WINDOW_FAILURE
    };

    class Context {
    public:
        Context();
        ~Context();

        bool renderFrame();
        bool render(const Scene &scene) const;
        bool renderObject(const Camera &cam, const Object &obj) const;
        bool renderGeometry(const Camera &cam, const Geometry &g) const;
        bool isAlive() const;
        SLAB_STATUS getStatus() const;
        void kill();

    private:
        Window *pWindow;
        Scene *pScene;
        SLAB_STATUS eStatus;
        void setStatus(SLAB_STATUS newStatus);

    };
}

#endif /* context_hpp */
