//
//  triangle.hpp
//  slab
//
//  Created by Austin Lasher on 8/6/17.
//
//

#ifndef triangle_h
#define triangle_h

#include <OpenGL/gl.h>

#include "geometry.hpp"


namespace Slab {

    class Triangle : public Geometry
    {
    public:
        Triangle();
        virtual ~Triangle();
        
        // TODO: Move this somewhere else, where it makes more sense.
        // These are just for convenience right now, to get some basic stuff running!
        GLuint getShaderProgram();
    private:
        const char *getVertexShader();
        const char *getPixelShader();
        GLuint sp;
    };

}

#endif /* triangle_h */
