#include <slab/window.hpp>

namespace Slab {

    // TODO: Make Window an abstract class that can interface different libraries
    // Virtual methods would be like open(), close(), setTitle, etc.
    // ex: GLFWWindow, SDLWindow, maybe even native OS window classes?
    Window::Window(std::string title) :
            pWindow(nullptr),
            nWidth(1280),
            nHeight(720),
            sTitle(title)
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        setWindowStatus(SLAB_WINDOW_OKAY);
    }

    Window::~Window() {
        glfwDestroyWindow(pWindow);
        pWindow = nullptr;
        glfwTerminate();
    }

    bool Window::open() {
        if(pWindow != nullptr) return false;
        if(!isReady()) return false;

        pWindow = glfwCreateWindow(nWidth, nHeight, sTitle.c_str(), NULL, NULL);
        if(pWindow == nullptr) {
            setWindowStatus(SLAB_WINDOW_FAILED_TO_OPEN);
            return false;
        }

        glfwMakeContextCurrent(pWindow);
        glfwSetKeyCallback(pWindow, Window::glfw_keypress_callback);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

        return true;
    }

    bool Window::close() {
        if(pWindow == nullptr) return false;
        glfwSetWindowShouldClose(pWindow, GLFW_TRUE);
        setWindowStatus(SLAB_WINDOW_CLOSED);
        return true;
    }



    // A Window that is "Ready" hasn't run into any errors. It can be closed, or open.
    bool Window::isReady() {
        return (getWindowStatus() == SLAB_WINDOW_OKAY);
    }

    bool Window::isOpen() {
        if(pWindow == nullptr) return false;
        if(glfwWindowShouldClose(pWindow)) {
            if(getWindowStatus() == SLAB_WINDOW_OKAY) {
                setWindowStatus(SLAB_WINDOW_CLOSED);
            }
            return false;
        }

        return true;
    }

    bool Window::swapBuffers() {
        glfwSwapBuffers(pWindow);
        glfwPollEvents();
        return true;
    }

    // TODO: Find an easy way to allow user to process key presses from Scene
    // Maybe an EventManager class? Would somehow provide class-neutral global
    // function callbacks for whatever window API we're using.
    void Window::glfw_keypress_callback(GLFWwindow *w, int key, int scancode,
                                int action, int mode) {
       if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
           glfwSetWindowShouldClose(w, GL_TRUE);
       }
    }
}
