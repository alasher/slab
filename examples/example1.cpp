//
// Created by alasher on 3/11/17.
//

#include <iostream>
#include <slab/context.h>

int main(int argc, char **argv) {

    Slab::Context slab;
    std::cout << "Hello, world!" << std::endl;

    while(slab.isAlive()) {
        slab.renderFrame();
    }

    // Don't know if I want to do this anymore
    // Slab::Window main_window;
    // slab.attachWindow(main_window);

    /*
    Slab::Scene main_scene;
    slab.attachScene(main_scene);

    // Don't necessarily need to add this right now.
    Slab::Camera cam;
    main_scene.addCamera(cam);
    */

    /*
    while(slab.isAlive()) {
        if(!slab.renderFrame()) break;
    }
     */

    return 0;
}