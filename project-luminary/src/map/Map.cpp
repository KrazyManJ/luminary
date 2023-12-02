#include <iostream>
#include <utility>
#include "Map.h"

Map::Map(const std::string& stringMatrix, std::map<char, std::function<MapObject *()>> mappings,
         std::vector<InteractiveObject *> objects) {
    m_interactiveObjects = std::move(objects);
    m_isLightened = false;
    unsigned short row = 0, col = 0;
    for (char c: stringMatrix) {
        if (c == '\n') {
            row++;
            col = 0;
            continue;
        }
        m_matrix[row][col] = (c == ' ') ? nullptr : mappings.at(c)();
        col++;
    }
}

std::string Map::render() {
    std::string result;
    for (unsigned short row = 0; row < Window::HEIGHT; row++) {
        for (unsigned short col = 0; col < Window::WIDTH; col++) {
            InteractiveObject* interactive = getInteractiveObjectAt({.x=col,.y=row});
            if (m_matrix[row][col] == nullptr)
                result.append(" " + ConsoleHandler::getFormatChar(RESET));
            else if (interactive!= nullptr && !interactive->renderChar().empty())
                result.append(interactive->renderChar());
            else result.append(m_matrix[row][col]->renderChar(m_isLightened));
        }
        result.append("\n");
    }
    return result;
}

std::vector<InteractiveObject *> Map::getInteractiveObjects() {
    return m_interactiveObjects;
}

InteractiveObject* Map::getInteractiveObjectAt(Position position){
    for (auto* interactiveObject : m_interactiveObjects){
        if (interactiveObject->getPosition().x == position.x && interactiveObject->getPosition().y == position.y){
            return interactiveObject;
        }
    }
    return nullptr;
}

MapObject *Map::getObjectAt(Position pos) {
    return m_matrix[pos.y][pos.x];
}

void Map::setLightState(bool state) {
    m_isLightened = state;
}

bool Map::getLightState() {
    return m_isLightened;
}
