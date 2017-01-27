cmake_minimum_required(VERSION 3.1)
project(Legends)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/framework/include)

add_subdirectory(framework)
add_subdirectory(game)
add_subdirectory(editor)