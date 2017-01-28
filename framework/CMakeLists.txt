project(Framework)

set(SOURCE_FILES
        include/Legends/App.h
        src/App.cpp

        include/Legends/EventManager.h
        src/EventManager.cpp

        include/Legends/Renderer.h
        src/Renderer.cpp

        include/Legends/Surface.h
        src/Surface.cpp

        src/win32/AppImpl_win32.h
        src/win32/AppImpl_win32.cpp

        src/win32/SurfaceImpl_win32.h
        src/win32/SurfaceImpl_win32.cpp

        src/linux/AppImpl_linux.h
        src/linux/AppImpl_linux.cpp

        src/linux/SurfaceImpl_linux.h
        src/linux/SurfaceImpl_linux.cpp
        )

if(APPLE)
    set(SOURCE_FILES
            ${PROJECT_SOURCE_DIR}/../extlibs/bgfx/src/amalgamated.mm
            ${SOURCE_FILES})
else()
    set(SOURCE_FILES
            ${PROJECT_SOURCE_DIR}/../extlibs/bgfx/src/amalgamated.cpp
            ${SOURCE_FILES})
endif()

add_definitions(-D__STDC_FORMAT_MACROS)

if(MINGW)
    include_directories(${PROJECT_SOURCE_DIR}/../extlibs/bx/include/compat/mingw)
    add_definitions(-DMINGW_HAS_SECURE_API=1)
elseif(MSVC)
    include_directories(${PROJECT_SOURCE_DIR}/../extlibs/bx/include/compat/msvc)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

set(SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/../extlibs/bx/src/commandline.cpp
        ${PROJECT_SOURCE_DIR}/../extlibs/bx/src/crtimpl.cpp
        ${PROJECT_SOURCE_DIR}/../extlibs/bx/src/debug.cpp
        ${PROJECT_SOURCE_DIR}/../extlibs/bx/src/dtoa.cpp
        ${PROJECT_SOURCE_DIR}/../extlibs/bx/src/fpumath.cpp
        ${PROJECT_SOURCE_DIR}/../extlibs/bx/src/mutex.cpp
        ${PROJECT_SOURCE_DIR}/../extlibs/bx/src/os.cpp
        ${PROJECT_SOURCE_DIR}/../extlibs/bx/src/sem.cpp
        ${PROJECT_SOURCE_DIR}/../extlibs/bx/src/string.cpp
        ${PROJECT_SOURCE_DIR}/../extlibs/bx/src/thread.cpp
        ${SOURCE_FILES})

include_directories(${PROJECT_SOURCE_DIR}/../extlibs/bx/include)
include_directories(${PROJECT_SOURCE_DIR}/../extlibs/bgfx/include)
include_directories(${PROJECT_SOURCE_DIR}/../extlibs/bgfx/3rdparty)
include_directories(${PROJECT_SOURCE_DIR}/../extlibs/bgfx/3rdparty/dxsdk/include)
include_directories(${PROJECT_SOURCE_DIR}/../extlibs/bgfx/3rdparty/khronos)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DBGFX_CONFIG_DEBUG=1)
endif()

add_library(Framework STATIC ${SOURCE_FILES})
