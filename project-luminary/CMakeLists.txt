cmake_minimum_required(VERSION 3.26)
project(project_luminary)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE source_list "src/**.cpp" "src/**.h")

# using this after all classes are done
# add_executable(project_luminary main.cpp ${source_list})

# this executable is for testing purposes
add_executable(project_luminary main.cpp
        src/console/ConsoleHandler.h
        src/console/ConsoleHandler.cpp
        src/Luminary.h
        src/Luminary.cpp
        src/window/Window.h
        src/window/Window.cpp
        src/window/MainMenuWindow.h
        src/window/MainMenuWindow.cpp
        src/utils/Cycler.cpp
        src/utils/Cycler.h
        src/Game.cpp
        src/Game.h
        src/console/CharData.h
        src/console/CharData.cpp
        src/map/Map.cpp
        src/map/Map.h
        src/player/Player.cpp
        src/player/Player.h
        src/console/CharRenderable.cpp
        src/console/CharRenderable.h
        src/console/CharRenderable.cpp
        src/console/CharRenderable.h
        src/map/MapObject.cpp
        src/map/MapObject.h
        src/inventory/Inventory.h
        src/inventory/Inventory.cpp
#        src/Enemy.h
#        src/Enemy.cpp
        src/palettes/ColorPalette.h
        src/palettes/CharPalette.h
        src/map/InteractiveObject.cpp
        src/map/InteractiveObject.h
        src/map/ItemEntity.cpp
        src/map/ItemEntity.h
)