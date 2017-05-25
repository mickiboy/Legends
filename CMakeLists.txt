cmake_minimum_required(VERSION 3.1)
project(Legends VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

set(GLAD_PROFILE "core")
add_subdirectory(${CMAKE_SOURCE_DIR}/extlibs/glad)

set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
add_subdirectory(${CMAKE_SOURCE_DIR}/extlibs/glfw)

configure_file(${CMAKE_SOURCE_DIR}/src/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/src/config.h @ONLY)

include_directories(
    ${GLAD_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/extlibs/glfw/include
    ${CMAKE_SOURCE_DIR}/extlibs/glm
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}/src)

set(SOURCE_FILES
    src/init.cpp
    src/main.cpp

    src/core/App.h src/core/App.cpp
    src/core/EventManager.h src/core/EventManager.cpp
    src/core/ResourceManager.h src/core/ResourceManager.cpp

    src/core/impl/AppImpl_GLFW.h src/core/impl/AppImpl_GLFW.cpp

    src/graphics/Camera.h src/graphics/Camera.cpp
    src/graphics/Mesh.h src/graphics/Mesh.cpp
    src/graphics/Renderer.h src/graphics/Renderer.cpp
    src/graphics/Shader.h src/graphics/Shader.cpp
    src/graphics/Sprite.h src/graphics/Sprite.cpp
    src/graphics/Texture.h src/graphics/Texture.cpp
        
    src/graphics/impl/MeshImpl_GL.h src/graphics/impl/MeshImpl_GL.cpp
    src/graphics/impl/RendererImpl_GL.h src/graphics/impl/RendererImpl_GL.cpp
    src/graphics/impl/ShaderImpl_GL.h src/graphics/impl/ShaderImpl_GL.cpp
    src/graphics/impl/TextureImpl_GL.h src/graphics/impl/TextureImpl_GL.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${GLAD_LIBRARIES} glfw)

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/assets" "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets")
