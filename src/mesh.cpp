#include <slab/mesh.hpp>

slab::Mesh::Mesh(const Geometry &ing) : Object(), geometry(ing) {
}

// TODO: Create a basic Material object with shaders for this mesh
// compile the shaders, and load them when it's time to render.
// Or - consider making this an abstract class
