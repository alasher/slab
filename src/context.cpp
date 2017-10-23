#include <slab/context.hpp>

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

    bool Context::render(const Slab::Scene &scene) const
    {
        if (getStatus() != SLAB_OKAY) return false;

        if (pWindow != nullptr && !pWindow->isOpen())
        {
            if(!pWindow->open()) return false;
        }

        if (!scene.hasCamera())
        {
            return false;
        }

        glClear(GL_COLOR_BUFFER_BIT);

        const std::vector<const Object *> objs = scene.getObjects();
        const Camera &cam = scene.getCamera();

        // TODO: Look into optimizations for this
        for (const Object *obj : objs)
        {
            renderObject(cam, *obj);
        }

        pWindow->swapBuffers();
        return true;
    }

    bool Context::renderObject(const Camera &cam, const Object &obj) const
    {
        return false;
    }

    // TODO: Maybe need something more specific than "Alive"
    bool Context::isAlive() const
    {
        // If Window is not defined, return true.
        // If Window is defined, return true iff it's open
        return (pWindow->isReady() && getStatus() == SLAB_OKAY);
    }

    SLAB_CONTEXT_STATUS Context::getStatus() const
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
