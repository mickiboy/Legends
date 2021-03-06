cmake_minimum_required(VERSION 3.1)
project(Legends VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

set(GLAD_PROFILE "core")
add_subdirectory(${CMAKE_SOURCE_DIR}/extlibs/glad)

set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
add_subdirectory(${CMAKE_SOURCE_DIR}/extlibs/glfw)

add_subdirectory(${CMAKE_SOURCE_DIR}/extlibs/yaml-cpp)

configure_file(${CMAKE_SOURCE_DIR}/src/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/src/config.h @ONLY)

include_directories(
    ${GLAD_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/extlibs/glfw/include
    ${CMAKE_SOURCE_DIR}/extlibs/glm
    ${CMAKE_SOURCE_DIR}/extlibs/yaml-cpp/include
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}/src)

set(SOURCE_FILES
    src/init.cpp
    src/main.cpp

    src/core/App.cpp src/core/App.h
    src/core/EventManager.cpp src/core/EventManager.h
    src/core/Log.cpp src/core/Log.h
    src/core/ResourceManager.cpp src/core/ResourceManager.h
    src/core/SceneManager.cpp src/core/SceneManager.h
    src/core/TaskManager.cpp src/core/TaskManager.h
    src/core/World.cpp src/core/World.h

    src/core/impl/AppImpl_GLFW.cpp src/core/impl/AppImpl_GLFW.h
    src/core/impl/LogOutputImpl_ANSI.cpp src/core/impl/LogOutputImpl_ANSI.h
    src/core/impl/LogOutputImpl_Win32.cpp src/core/impl/LogOutputImpl_Win32.h

    src/graphics/Camera.cpp src/graphics/Camera.h
    src/graphics/Mesh.cpp src/graphics/Mesh.h
    src/graphics/Renderer.cpp src/graphics/Renderer.h
    src/graphics/Shader.cpp src/graphics/Shader.h
    src/graphics/Sprite.cpp src/graphics/Sprite.h
    src/graphics/SpriteRendererTask.cpp src/graphics/SpriteRendererTask.h
    src/graphics/Texture.cpp src/graphics/Texture.h
        
    src/graphics/impl/MeshImpl_GL.cpp src/graphics/impl/MeshImpl_GL.h
    src/graphics/impl/RendererImpl_GL.cpp src/graphics/impl/RendererImpl_GL.h
    src/graphics/impl/ShaderImpl_GL.cpp src/graphics/impl/ShaderImpl_GL.h
    src/graphics/impl/TextureImpl_GL.cpp src/graphics/impl/TextureImpl_GL.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${GLAD_LIBRARIES} glfw yaml-cpp)

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/assets" "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets")
