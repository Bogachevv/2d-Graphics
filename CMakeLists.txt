cmake_minimum_required(VERSION 3.16)
project(2d_Graphics)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
    add_executable(2d_Graphics main.cpp screen.h win/win_screen.h screen.cpp win/win_screen.cpp win/win_console.cpp win/win_console.h figures.cpp figures.h complex.cpp complex.h figure_factory.cpp figure_factory.h scene.cpp scene.h includes.h)
endif(WIN32)

if(UNIX)
    add_executable(2d_Graphics main.cpp screen.h linux/linux_screen.h screen.cpp linux/linux_screen.cpp figures.cpp figures.h complex.cpp complex.h figure_factory.cpp figure_factory.h scene.cpp scene.h includes.h)
    target_link_libraries(${PROJECT_NAME} ncurses)
endif(UNIX)
