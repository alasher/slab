add_library( slab mesh.cpp foundation.cpp )

# Find graphics libs
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLFW REQUIRED)

# Include necessary dirs
target_include_directories( slab PUBLIC "${PROJECT_SOURCE_DIR}/include" )
include_directories("${GLEW_INCLUDE_DIRS}")
include_directories("${GLFW_INCLUDE_DIR}")

# Link graphics libs
target_link_libraries(slab "${GLEW_LIBRARIES}")
target_link_libraries(slab "${OPENGL_gl_LIBRARY}")
target_link_libraries(slab "${GLFW_LIBRARIES}")

