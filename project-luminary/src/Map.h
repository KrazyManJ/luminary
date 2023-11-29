#ifndef PROJECT_LUMINARY_MAP_H
#define PROJECT_LUMINARY_MAP_H


#include <string>
#include <map>
#include <functional>
#include "MapObject.h"
#include "Window/Window.h"

class Map {
private:
    MapObject *m_matrix[Window::HEIGHT][Window::WIDTH];
public:
    Map(std::string stringMatrix, std::map<char, std::function<MapObject *()>> mappings);

    std::string render();
};


#endif //PROJECT_LUMINARY_MAP_H
