//
//  camera.hpp
//  slab
//
//  Created by Austin Lasher on 7/24/17.
//
//

#ifndef camera_hpp
#define camera_hpp

#include "object.hpp"

namespace Slab
{
    /*

     // TODO: Right now the user creates a Camera object of their own and passes a pointer
     // to the context. Yuck! Don't let the user be responsible for their own pointers,
     // after all it's ${CURRENT_YEAR}! Maybe we should let the context create it's own
     // camera. Something like the following:

     main_scene.create_camera<MyCoolCameraSubclass>("player_cam");

     // create_camera<>(std::string) can default to a perspective Slab::Camera by default.
     // Then, the camera can be modified with main_scene.camera().x += 322;

     // How do we set up multiple cameras, and modify cameras that aren't active?
     main_scene.camera("other_camname").x += 25; // Modify a non-active camera.
     main_scene.camera() // Returns the current *active* camera.
     main_scene.setActiveCamera("camera2"); // Immediately switch to camera2.

    */
    class Camera : public Object
    {
    public:
        Camera(int x = 0, int y = 0, int z = 0);
    };
}

#endif /* camera_hpp */
