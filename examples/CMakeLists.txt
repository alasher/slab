CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
PROJECT( slab_examples )

include_directories("../include")

add_executable(example1 example1.cpp)
target_link_libraries(example1 slab)
