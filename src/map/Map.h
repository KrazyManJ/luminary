#ifndef PROJECT_LUMINARY_MAP_H
#define PROJECT_LUMINARY_MAP_H


#include <string>
#include <map>
#include <functional>
#include "MapObject.h"
#include "../window/Window.h"
#include "InteractiveObject.h"
#include "Torch.h"

class Map {
private:
    MapObject *m_matrix[Window::HEIGHT][Window::WIDTH]{};
    std::vector<InteractiveObject *> m_interactiveObjects;
    std::vector<Torch*> m_torches;
public:
    Map(
            const std::string& stringMatrix,
            std::map<char, std::function<MapObject *()>> mappings,
            std::vector<InteractiveObject *> objects
    );

    std::string render(bool isLit);

    std::vector<InteractiveObject *> getInteractiveObjects();

    MapObject* getObjectAt(Position pos);

    InteractiveObject *getInteractiveObjectAt(Position position);

    bool areAllTorchesLitUp();
};


#endif //PROJECT_LUMINARY_MAP_H
