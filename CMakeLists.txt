cmake_minimum_required(VERSION 3.26)
project(luminary)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static")

file(GLOB_RECURSE source_list "src/**.cpp" "src/**.h")

add_executable(luminary main.cpp ${source_list})
