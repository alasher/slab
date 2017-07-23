//
// Created by alasher on 3/11/17.
//

#include <slab/context.h>

namespace Slab {
    Context::Context() :
        pScene(nullptr),
        eStatus(SLAB_OKAY)
    {
        pWindow = new Window();
        if (pWindow == nullptr)
        {
            setStatus(SLAB_WINDOW_FAILURE);
        }
    }

    Context::~Context()
    {
        delete pWindow;
    }

    bool Context::renderFrame()
    {
        if (pScene == nullptr) return false;
        return render(*pScene);
    }

    // TODO: Read camera info and objects from scene, render them
    bool Context::render(Slab::Scene &scene)
    {
        if (getStatus() != SLAB_OKAY) return false;

        if (pWindow != nullptr && !pWindow->isOpen())
        {
            if(!pWindow->open()) return false;
        }

        glClear(GL_COLOR_BUFFER_BIT);

        pWindow->swapBuffers();
        return true;
    }

    // TODO: Maybe need something more specific than "Alive"
    bool Context::isAlive()
    {
        // If Window is not defined, return true.
        // If Window is defined, return true iff it's open
        return (pWindow->isReady() && getStatus() == SLAB_OKAY);
    }

    SLAB_CONTEXT_STATUS Context::getStatus()
    {
        return eStatus;
    }

    void Context::setStatus(SLAB_CONTEXT_STATUS newStatus)
    {
        eStatus = newStatus;
    }

    void Context::kill()
    {
        setStatus(SLAB_DESTROYED);
    }
}
