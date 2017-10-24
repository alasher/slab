//
//  mesh.hpp
//  slab
//
//  Created by Austin Lasher on 10/23/17.
//

#ifndef mesh_h
#define mesh_h

#include "object.hpp"
#include "geometry.hpp"

namespace Slab {

    class Mesh : public Object
    {
    public:
        Mesh(const Geometry &ing);
        inline virtual bool isRenderable() const
        {
            return true;
        }

    private:
        Geometry geometry;
    };

}


#endif /* mesh_h */
