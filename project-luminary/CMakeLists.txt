cmake_minimum_required(VERSION 3.26)
project(project_luminary)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE source_list "src/**.cpp" "src/**.h")

add_executable(project_luminary main.cpp
        ${source_list}
        src/Heal.cpp
        src/Heal.h
        src/Weapon.cpp
        src/Weapon.h
        src/ItemEntity.cpp
        src/ItemEntity.h
        src/Item.cpp
        src/Item.h
)
