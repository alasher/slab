add_library( slab mesh.cpp foundation.cpp )

# Link graphics libs
target_link_libraries(slab "${GLEW_LIBRARIES}")
target_link_libraries(slab "${OPENGL_gl_LIBRARY}")
if(APPLE)
    target_link_libraries(slab "${GLFW_glfw_LIBRARY}")
else()
    target_link_libraries(slab "${GLFW_LIBRARIES}")
endif()

