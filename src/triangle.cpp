//
//  triangle.cpp
//  slab
//
//  Created by Austin Lasher on 8/6/17.
//
//

#include <slab/triangle.hpp>

Slab::Triangle::Triangle() : Slab::Geometry()
{
    addPoint(-1.0, -1.0,  0.0);
    addPoint( 0.0,  1.0,  0.0);
    addPoint( 1.0,  1.0,  0.0);
}
