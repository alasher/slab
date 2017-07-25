//
// Created by alasher on 3/11/17.
//

#ifndef window_hpp
#define window_hpp

#include <GLFW/glfw3.h>

#include <string>
#include <iostream>

namespace Slab {

    enum SLAB_WINDOW_STATUS {
        SLAB_WINDOW_OKAY,
        SLAB_WINDOW_FAILED_TO_OPEN,
        SLAB_WINDOW_CLOSED
    };

    class Window {
    public:
        Window(std::string title = "Slab");
        virtual ~Window();
        bool isReady();
        bool isOpen();
        bool open();
        bool close();
        bool swapBuffers();
        inline SLAB_WINDOW_STATUS getWindowStatus() {
            return eWindowStatus;
        }

    private:
        GLFWwindow *pWindow;
        // bool bHasBeenOpened, bWindowIsOpen;
        short nWidth, nHeight;
        std::string sTitle;
        SLAB_WINDOW_STATUS eWindowStatus;
        inline void setWindowStatus(SLAB_WINDOW_STATUS newStatus) {
            eWindowStatus = newStatus;
        }

        // Callbacks
        static void glfw_keypress_callback(GLFWwindow *w, int, int, int, int);
    };
}

#endif /* window_hpp */
