cmake_minimum_required(VERSION 3.26)
project(project_luminary)

set(CMAKE_CXX_STANDARD 17)

add_executable(project_luminary main.cpp
        src/ConsoleHandler.cpp
        src/ConsoleHandler.h)
