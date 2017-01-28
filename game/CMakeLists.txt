project(Game)

set(SOURCE_FILES
        src/main.cpp
        src/init.cpp)

add_executable(Game WIN32 ${SOURCE_FILES})

set(LIBRARIES Framework)

if(WIN32)
    set(LIBRARIES ${LIBRARIES} psapi)
elseif(UNIX)
    set(LIBRARIES ${LIBRARIES} X11 GL pthread dl)
endif()

target_link_libraries(Game ${LIBRARIES})
