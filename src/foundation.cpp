// Slab Foundation class
// TODO: Implement a way that a user program can utilize the init phase and draw loop

#include "slab/foundation.h"
#include <iostream>

namespace Slab {

Foundation::Foundation() {
    glfwInit();
    std::cout << "Creating the slab foundation" << std::endl;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    glfw_window = glfwCreateWindow(800, 600, "Slab Window", NULL, NULL);
    //window_active = true;
    if(glfw_window == NULL) {
        std::cout << "Failed to create window.\n";
        //window_active = false;
        //glfwTerminate();
        //return -1;
    }

    glfwMakeContextCurrent(glfw_window);
    glfwSetKeyCallback(glfw_window, glfw_keypress);

    if(glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW.\n";
        //window_active = false;
        //glfwTerminate();
        //return -1;
    }
}

Foundation::~Foundation() {
    std::cout << "Destroying the slab foundation" << std::endl;
    glfwTerminate();
}

void Foundation::activateWindow() {
    while(!glfwWindowShouldClose(glfw_window)) {
        glfwSwapBuffers(glfw_window);
        glfwPollEvents();
    }
}

void Foundation::glfw_keypress(GLFWwindow *w, int key, int scancode, int action, int mode) {
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(w, GL_TRUE);
    }
}

}
