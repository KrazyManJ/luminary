#include <iostream>
#include "Map.h"

Map::Map(std::string stringMatrix, std::map<char, std::function<MapObject *()>> mappings) {
    unsigned short row = 0, col = 0;
    for (char c : stringMatrix){
        if (c == '\n') { row++; col = 0; continue; }
        m_matrix[row][col] = (c == ' ') ? nullptr :  mappings.at(c)();
        col++;
    }
}

std::string Map::render() {
    std::string result;
    for (auto & row : m_matrix){
        for (auto & col : row) {
            result.append(
                    (col != nullptr)
                    ? col->renderChar(false)
                    : " "+ConsoleHandler::getFormatChar(ConsoleHandler::RESET)
                    );
        }
        result.append("\n");
    }

    return result;
}

