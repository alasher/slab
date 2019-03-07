cmake_minimum_required(VERSION 3.6)
project(slab)

# Options
option(BUILD_EXAMPLES "Build example executable in addition to library." ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/modules")

find_package(GLFW REQUIRED)
find_package(OpenGL REQUIRED)

include_directories("include")
include_directories(${GLFW_INCLUDE_DIR})

# Assign source files
# One day this can be moved to a separate CMakeLists file, if the complexity increases.
set (SOURCE_FILES "")
set (SOURCE_FILES ${SOURCE_FILES} "src/camera.cpp")
set (SOURCE_FILES ${SOURCE_FILES} "src/context.cpp")
set (SOURCE_FILES ${SOURCE_FILES} "src/matrix.cpp")
set (SOURCE_FILES ${SOURCE_FILES} "src/object.cpp")
set (SOURCE_FILES ${SOURCE_FILES} "src/scene.cpp")
set (SOURCE_FILES ${SOURCE_FILES} "src/window.cpp")
add_library (slab ${SOURCE_FILES})

if (${BUILD_EXAMPLES})
    add_subdirectory("${CMAKE_SOURCE_DIR}/examples")
endif()
