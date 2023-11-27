cmake_minimum_required(VERSION 3.26)
project(project_luminary)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE source_list "src/**.cpp" "src/**.h")

# using this after all classes are done
 add_executable(project_luminary main.cpp ${source_list})

# this executable is for testing purposes
#add_executable(project_luminary main.cpp
#        src/ConsoleHandler.h
#        src/ConsoleHandler.cpp
#        src/Luminary.h
#        src/Luminary.cpp
#        src/window/Window.h
#        src/window/Window.cpp
#        src/window/MainMenuWindow.h
#        src/window/MainMenuWindow.cpp
#)