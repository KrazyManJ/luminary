#ifndef PROJECT_LUMINARY_MAP_H
#define PROJECT_LUMINARY_MAP_H


#include <string>
#include <map>
#include <functional>
#include "MapObject.h"
#include "../window/Window.h"
#include "InteractiveObject.h"

class Map {
private:
    MapObject *m_matrix[Window::HEIGHT][Window::WIDTH]{};
    std::vector<InteractiveObject *> m_interactiveObjects;
    bool m_isLightened;
public:
    Map(
            const std::string& stringMatrix,
            std::map<char, std::function<MapObject *()>> mappings,
            std::vector<InteractiveObject *> objects
    );

    std::string render();

    std::vector<InteractiveObject *> getInteractiveObjects();

    MapObject* getObjectAt(Position pos);

    void setLightState(bool state);

    bool getLightState();

    InteractiveObject *getInteractiveObjectAt(Position position);
};


#endif //PROJECT_LUMINARY_MAP_H
