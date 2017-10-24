#include <iostream>
#include <slab/context.hpp>
#include <slab/camera.hpp>
#include <slab/triangle.hpp>
#include <slab/mesh.hpp>

int main(int argc, char **argv) {

    Slab::Context slab;
    std::cout << "Hello, world!" << std::endl;

    Slab::Scene main_scene;

    // Slab::Triangle c(1);
    Slab::Camera *cam = new Slab::Camera();
    main_scene.attachCamera(cam);

    Slab::Triangle t_geom;
    Slab::Mesh tri{t_geom};
    main_scene.addObject(&tri);

    while(slab.isAlive())
    {
        // TODO: Specify a scene object to render
        // All scenes must have a camera
        slab.render(main_scene);
    }

    delete cam;

    return 0;
}
