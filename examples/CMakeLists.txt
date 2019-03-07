add_executable(example1 "example1.cpp")

target_link_libraries(example1 slab)
target_link_libraries(example1 ${GLFW_LIBRARIES})
target_link_libraries(example1 ${OPENGL_gl_LIBRARY})
