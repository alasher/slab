//
// Created by alasher on 3/11/17.
//

#ifndef SLAB_CONTEXT_H
#define SLAB_CONTEXT_H

#include <iostream>
#include "window.h"
#include "scene.h"

namespace Slab {
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
        bool render(Scene &scene);
        bool isAlive();
        SLAB_CONTEXT_STATUS getStatus();
        void kill();

    private:
        Window *pWindow;
        Scene *pScene;
        SLAB_CONTEXT_STATUS eStatus;
        void setStatus(SLAB_CONTEXT_STATUS newStatus);

    };
}

#endif //SLAB_CONTEXT_H
