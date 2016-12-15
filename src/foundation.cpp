// Slab Foundation class
// TODO: Implement a way that a user program can utilize the init phase and draw loop
// TODO: Move the majority of this over to a window class

#include "slab/foundation.h"
#include <iostream>
#include <string>

namespace Slab {

Foundation::Foundation() :
    window_creation_worked(false)
{
    glfwInit();
    std::cout << "Creating the slab foundation" << std::endl;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwSetErrorCallback(Foundation::glfw_err_callback);
    
    glfw_window = glfwCreateWindow(800, 600, "Slab Window", NULL, NULL);
    if(glfw_window == NULL) {
        std::cout << "Failed to create window.\n";
        window_creation_worked = false;
    } else {
        window_creation_worked = true;
    }

    glfwMakeContextCurrent(glfw_window);
    glfwSetKeyCallback(glfw_window, glfw_keypress);

#ifndef __APPLE__
    if(glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW.\n";
    }
#endif
}

Foundation::~Foundation()
{
    std::cout << "Destroying the slab foundation" << std::endl;
    glfwTerminate();
}

void Foundation::activateWindow()
{
    if(!isAlive()) return;

    while(!glfwWindowShouldClose(glfw_window)) {
        glfwSwapBuffers(glfw_window);
        glfwPollEvents();
    }
}

void Foundation::glfw_keypress(GLFWwindow *w, int key, int scancode, int action, int mode)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(w, GL_TRUE);
    }
}

void Foundation::glfw_err_callback(int errnum, const char *desc){
    std::cout << "GLFW creation error!" << std::endl;
    std::cout << std::string(desc) << std::endl;
}

}
