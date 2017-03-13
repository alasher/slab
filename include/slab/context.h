//
// Created by alasher on 3/11/17.
//

#ifndef SLAB_CONTEXT_H
#define SLAB_CONTEXT_H

#include <iostream>
#include "window.h"

namespace Slab {
    enum SLAB_CONTEXT_STATUS {
        SLAB_OKAY
    };

    class Context {
    public:
        Context();
        ~Context();

        /*
        bool attachWindow(Window *win);
        bool releaseWindow();
        */
        bool renderFrame();
        bool isAlive();
        SLAB_CONTEXT_STATUS getStatus();

    private:
        Window *pWindow;
        SLAB_CONTEXT_STATUS eStatus;
        void setStatus(SLAB_CONTEXT_STATUS newStatus);


    };
}

#endif //SLAB_CONTEXT_H
