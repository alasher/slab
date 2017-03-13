cmake_minimum_required(VERSION 3.6)
project(slab)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/modules/")

find_package(GLFW REQUIRED)
find_package(OpenGL REQUIRED)

include_directories("include")
include_directories(${GLFW_INCLUDE_DIR})

set(SOURCE_FILES src/context.cpp include/slab/context.h src/window.cpp)
add_library(slab ${SOURCE_FILES})

add_executable(example1 "examples/example1.cpp")

target_link_libraries(example1 slab)
target_link_libraries(example1 ${GLFW_LIBRARIES})
target_link_libraries(example1 ${OPENGL_gl_LIBRARY})
