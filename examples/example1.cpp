#include <iostream>
#include <slab/context.hpp>
#include <slab/camera.hpp>
#include <slab/triangle.hpp>
#include <slab/mesh.hpp>

int main(int argc, char **argv) {

    Slab::Context slab;
    std::cout << "Hello, world!" << std::endl;

    Slab::Scene main_scene;

    // Just do one dummy call to initialize the context
    // TODO: Come up with a more flexible program flow, I shouldn't expect everyone to have to do this.
    slab.render(main_scene);

    Slab::Camera *cam = new Slab::Camera();
    main_scene.attachCamera(cam);

    Slab::Triangle t_geom;
    Slab::Mesh tri{t_geom};
    main_scene.addObject(&tri);

    while(slab.isAlive())
    {
        slab.render(main_scene);
    }

    delete cam;

    return 0;
}
