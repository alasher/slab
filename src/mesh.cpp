//
//  mesh.cpp
//  slab
//
//  Created by Austin Lasher on 10/23/17.
//

#include <slab/mesh.hpp>

Slab::Mesh::Mesh(const Geometry &ing) : Object(), geometry(ing)
{
}

// TODO: Create a basic Material object with shaders for this mesh
// compile the shaders, and load them when it's time to render.
// Or - consider making this an abstract class
