project(Game)

set(SOURCE_FILES
        src/main.cpp
        src/init.cpp
        )

add_executable(Game WIN32 ${SOURCE_FILES})
target_link_libraries(Game Framework)
