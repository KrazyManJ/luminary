#include <iostream>
#include <utility>
#include "Map.h"

Map::Map(const std::string& stringMatrix, std::map<char, std::function<MapObject *()>> mappings,
         std::vector<InteractiveObject *> objects) {
    m_interactiveObjects = std::move(objects);
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
    for (unsigned int row = 0; row < Window::HEIGHT; row++) {
        for (unsigned int col = 0; col < Window::WIDTH; col++) {
            InteractiveObject* interactive = nullptr;
            for (auto* interactiveObject : m_interactiveObjects){
                if (interactiveObject->getPosition().x == col && interactiveObject->getPosition().y == row){
                    interactive = interactiveObject;
                    break;
                }
            }
            if (m_matrix[row][col] == nullptr)
                result.append(" " + ConsoleHandler::getFormatChar(ConsoleHandler::RESET));
            else if (interactive!= nullptr && !interactive->renderChar().empty())
                result.append(interactive->renderChar());
            else result.append(m_matrix[row][col]->renderChar(false));
        }
        result.append("\n");
    }
    return result;
}

std::vector<InteractiveObject *> Map::getInteractiveObjects() {
    return m_interactiveObjects;
}

MapObject *Map::getObjectAt(Position pos) {
    return m_matrix[pos.y][pos.x];
}
