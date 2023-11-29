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
    for (auto &row: m_matrix) {
        for (auto &col: row) {
            result.append(
                    (col != nullptr)
                    ? col->renderChar(false)
                    : " " + ConsoleHandler::getFormatChar(ConsoleHandler::RESET)
            );
        }
        result.append("\n");
    }
    return result;
}

std::vector<InteractiveObject *> Map::getInteractiveObjects() {
    return m_interactiveObjects;
}

