#include <iostream>
#include <slab/camera.hpp>
#include <slab/context.hpp>
#include <slab/mesh.hpp>
#include <slab/triangle.hpp>

int main(int argc, char **argv) {
    slab::Context eng;
    std::cout << "Hello, world!" << std::endl;

    slab::Scene main_scene;

    // Just do one dummy call to initialize the context
    // TODO: Come up with a more flexible program flow, I shouldn't expect everyone to have to do
    // this.
    eng.render(main_scene);

    slab::Camera *cam = new slab::Camera();
    main_scene.attachCamera(cam);

    slab::Triangle t_geom;
    slab::Mesh tri{t_geom};
    main_scene.addObject(&tri);

    while (eng.isAlive()) {
        eng.render(main_scene);
    }

    delete cam;

    return 0;
}
