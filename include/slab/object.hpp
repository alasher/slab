#ifndef object_hpp
#define object_hpp

namespace slab {
    class Object {
       public:
        Object(int x = 0, int y = 0, int z = 0);
        virtual ~Object();
        inline virtual bool isRenderable() const {
            return false;
        }

        void push(int x, int y, int z);
        void moveTo(int x, int y, int z);

       private:
        int position[3];
    };

}  // namespace slab

#endif /* object_hpp */
