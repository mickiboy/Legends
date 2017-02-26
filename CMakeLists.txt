cmake_minimum_required(VERSION 3.1)
project(Legends)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(${PROJECT_SOURCE_DIR}/extlibs/glad)
add_subdirectory(${PROJECT_SOURCE_DIR}/extlibs/glfw)

include_directories(
        ${GLAD_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/extlibs/glfw/include)

set(SOURCE_FILES
        src/init.cpp
        src/main.cpp

        src/core/App.cpp
        src/core/EventManager.cpp

        src/graphics/Renderer.cpp)

add_executable(Legends ${SOURCE_FILES})
target_link_libraries(Legends ${GLAD_LIBRARIES} glfw)
