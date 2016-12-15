#ifndef FOUNDATION_H
#define FOUNDATION_H

//#include <GL/glew.h>
//#include <GL/gl.h>
#include <GLFW/glfw3.h>

namespace Slab {
    class Foundation {
    public:
        Foundation();
        ~Foundation();
        //bool isWindowActive();
        void activateWindow();
        inline bool isAlive() { return window_creation_worked; }

    private:
        GLFWwindow *glfw_window;
        bool window_creation_worked;
        static void glfw_keypress(GLFWwindow *w, int key, int scancode, int action, int mode);
        static void glfw_err_callback(int errnum, const char *desc);
    };
}

#endif
