#ifndef FOUNDATION_H
#define FOUNDATION_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

namespace Slab {
    class Foundation {
    public:
        Foundation();
        ~Foundation();
        //bool isWindowActive();
        void activateWindow();

    private:
        GLFWwindow *glfw_window;
        static void glfw_keypress(GLFWwindow *w, int key, int scancode, int action, int mode);
        //bool window_active;
    };
}

#endif
