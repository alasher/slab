# Exports:
# GLFW_FOUND - Boolean, indicates if GLFW was found.
# GLFW_INCLUDE_DIR - Include path, for use with INCLUDE_DIRECTORIES
# GLFW_LIBRARIES - Libraries to link, for use with TARGET_LINK_LIBRARIES 

find_path( GLFW_INCLUDE_DIR 
    NAMES
        GLFW/glfw3.h
    HINTS
        "${GLFW_LOCATION}/include"
        "$ENV{GLFW_LOCATION}/include"
    PATHS
        "$ENV{PROGRAMFILES}/GLFW/include"
        "${OPENGL_INCLUDE_DIR}"
        /usr/openwin/share/include
        /usr/openwin/include
        /usr/X11R6/include
        /usr/include/X11
        /opt/graphics/OpenGL/include
        /opt/graphics/OpenGL/contrib/libglfw
        /usr/local/include
        /usr/include/GL
        /usr/include
)

if (APPLE)
    find_library( GLFW_glfw_LIBRARY glfw
        NAMES 
            glfw
            glfw3
        HINTS
            "${GLFW_LOCATION}/lib"
            "${GLFW_LOCATION}/lib/cocoa"
            "$ENV{GLFW_LOCATION}/lib"
            "$ENV{GLFW_LOCATION}/lib/cocoa"
        PATHS
            /usr/local/lib
    )

    set(GLFW_cocoa_LIBRARY "-framework Cocoa" CACHE STRING "Cocoa framework for OSX")
    set(GLFW_corevideo_LIBRARY "-framework CoreVideo" CACHE STRING "CoreVideo framework for OSX")
    set(GLFW_iokit_LIBRARY "-framework IOKit" CACHE STRING "IOKit framework for OSX")

else ()
    find_package(Threads REQUIRED)
    find_package(X11 REQUIRED)
    
    if(NOT X11_Xrandr_FOUND)
        message(FATAL_ERROR "Xrandr library not found - required for GLFW")
    endif()

    if(NOT X11_xf86vmode_FOUND)
        message(FATAL_ERROR "xf86vmode library not found - required for GLFW")
    endif()

    if(NOT X11_Xcursor_FOUND)
        message(FATAL_ERROR "Xcursor library not found - required for GLFW")
    endif()

    if(NOT X11_Xinerama_FOUND)
        message(FATAL_ERROR "Xinerama library not found - required for GLFW")
    endif()

    list(APPEND GLFW_x11_LIBRARY "${X11_Xrandr_LIB}" "${X11_Xxf86vm_LIB}" "${X11_Xcursor_LIB}" "${X11_Xinerama_LIB}" "${CMAKE_THREAD_LIBS_INIT}" -lrt -lXi)

    find_library( GLFW_glfw_LIBRARY
        NAMES 
            glfw
            glfw3
        HINTS
            "${GLFW_LOCATION}/lib"
            "$ENV{GLFW_LOCATION}/lib"
            "${GLFW_LOCATION}/lib/x11"
            "$ENV{GLFW_LOCATION}/lib/x11"
        PATHS
            /usr/lib64
            /usr/lib
            /usr/lib/${CMAKE_LIBRARY_ARCHITECTURE}
            /usr/local/lib64
            /usr/local/lib
            /usr/local/lib/${CMAKE_LIBRARY_ARCHITECTURE}
            /usr/openwin/lib
            /usr/X11R6/lib
    )

endif ()

set( GLFW_FOUND "NO" )

if(GLFW_INCLUDE_DIR)
    if(GLFW_glfw_LIBRARY)
        set( GLFW_LIBRARIES "${GLFW_glfw_LIBRARY}"
                            "${GLFW_x11_LIBRARY}"
                            "${GLFW_cocoa_LIBRARY}"
                            "${GLFW_iokit_LIBRARY}"
                            "${GLFW_corevideo_LIBRARY}" )
        set( GLFW_FOUND "YES" )
        set (GLFW_LIBRARY "${GLFW_LIBRARIES}")
        set (GLFW_INCLUDE_PATH "${GLFW_INCLUDE_DIR}")
    endif()
endif()

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(GLFW 
    REQUIRED_VARS
        GLFW_INCLUDE_DIR
        GLFW_LIBRARIES
    VERSION_VAR
        GLFW_VERSION
)

mark_as_advanced(
  GLFW_INCLUDE_DIR
  GLFW_LIBRARIES
  GLFW_glfw_LIBRARY
  GLFW_cocoa_LIBRARY
)
