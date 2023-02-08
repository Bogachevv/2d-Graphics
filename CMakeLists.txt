cmake_minimum_required(VERSION 3.24)
project(2d_Graphics)

set(CMAKE_CXX_STANDARD 17)

add_executable(2d_Graphics main.cpp screen.h win/win_screen.h screen.cpp win/win_screen.cpp win/win_console.cpp win/win_console.h)
