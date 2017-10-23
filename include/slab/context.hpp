//
// Created by alasher on 3/11/17.
//

#ifndef context_hpp
#define context_hpp

#include "window.hpp"
#include "scene.hpp"

namespace Slab
{
    enum SLAB_CONTEXT_STATUS {
        SLAB_OKAY = 0,
        SLAB_DESTROYED,
        SLAB_WINDOW_FAILURE
    };

    class Context {
    public:
        Context();
        ~Context();

        bool renderFrame();
        bool render(const Scene &scene) const;
        bool renderObject(const Camera &cam, const Object &obj) const;
        bool isAlive() const;
        SLAB_CONTEXT_STATUS getStatus() const;
        void kill();

    private:
        Window *pWindow;
        Scene *pScene;
        SLAB_CONTEXT_STATUS eStatus;
        void setStatus(SLAB_CONTEXT_STATUS newStatus);

    };
}

#endif /* context_hpp */
