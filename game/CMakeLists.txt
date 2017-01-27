project(Game)

set(SOURCE_FILES
        src/main.cpp
        src/init.cpp)

add_executable(Game WIN32 ${SOURCE_FILES})

if(WIN32)
    target_link_libraries(Game Framework psapi)
endif()