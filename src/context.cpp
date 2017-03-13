//
// Created by alasher on 3/11/17.
//

#include <slab/context.h>

namespace Slab {
    Context::Context() :
        eStatus(SLAB_OKAY) {
        std::cout << "Creating Slab context!" << std::endl;
        // TODO: Add a default Window initialization in Context
        //       - Maybe allow user to create new Window w/ templates?
        //           - slab_c.createWindow<AustinsWindow>();
        //       - Maybe make it so we don't need to make a Window at all?
        //       - Add Event handling to Scene?
        pWindow = new Window();
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    }

    Context::~Context() {
        delete pWindow;
        std::cout << "Destroying Slab context." << std::endl;
    }

    // TODO: Actually render something!
    bool Context::renderFrame() {
        if(pWindow != nullptr && !pWindow->isOpen()) {
            if(!pWindow->open()) return false;
        }

        pWindow->swapBuffers();
        return true;
    }

    // TODO: Maybe need something more specific than "Alive"
    bool Context::isAlive() {
        // If Window is not defined, return true.
        // If Window is defined, return true iff it's open
        return (pWindow->isReady() && getStatus() == SLAB_OKAY);
    }

    SLAB_CONTEXT_STATUS Context::getStatus() {
        return eStatus;
    }

    void Context::setStatus(SLAB_CONTEXT_STATUS newStatus) {
        eStatus = newStatus;
    }
}