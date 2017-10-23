//
//  object.h
//  slab
//
//  Created by Austin Lasher on 7/23/17.
//
//

#ifndef object_hpp
#define object_hpp

namespace Slab
{
    class Object
    {
    public:
        Object(int x = 0, int y = 0, int z = 0);
        virtual ~Object();

        void push(int x, int y, int z);
        void moveTo(int x, int y, int z);

        // TODO: Move this to a separate Model class
        // Just doing this temporarily so I can test rendering something
        virtual const float *getVertices() = 0;

    private:
        int position[3];
    };

}

#endif /* object_hpp */
