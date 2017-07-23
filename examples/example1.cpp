//
// Created by alasher on 3/11/17.
//

#include <iostream>
#include <slab/context.h>

int main(int argc, char **argv) {

    Slab::Context slab;
    std::cout << "Hello, world!" << std::endl;

    Slab::Scene main_scene;

    while(slab.isAlive())
    {
        // TODO: Specify a scene object to render
        // All scenes must have a camera
        slab.render(main_scene);
    }

    /*
    // Don't necessarily need to add this right now.
    Slab::Camera cam;
    main_scene.addCamera(cam);
    */

    return 0;
}
