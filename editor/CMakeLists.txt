project(Editor)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(MSVC)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(CMAKE_PREFIX_PATH
                $ENV{QT_PATH_MSVC_64}/lib/cmake/Qt5
                ${CMAKE_PREFIX_PATH})
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
        set(CMAKE_PREFIX_PATH
                $ENV{QT_PATH_MSVC_32}/lib/cmake/Qt5
                ${CMAKE_PREFIX_PATH})
    endif()
endif()

find_package(Qt5 REQUIRED Widgets)

set(SOURCE_FILES
        src/main.cpp

        src/MainWindow.h
        src/MainWindow.cpp

        src/RendererWidget.h
        src/RendererWidget.cpp)

add_executable(Editor WIN32 ${SOURCE_FILES})
target_link_libraries(Editor Framework Qt5::Widgets psapi)