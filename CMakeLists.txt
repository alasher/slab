CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
PROJECT( slab C CXX )

# Find graphics libs
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLFW REQUIRED)

# Include necessary dirs
include_directories( "${PROJECT_SOURCE_DIR}/include" )
include_directories( "${GLEW_INCLUDE_DIRS}")
include_directories( "${GLFW_INCLUDE_DIR}")

include_directories("include")
add_subdirectory("src")
add_subdirectory("examples")
