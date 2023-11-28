#include "Map.h"

Map::Map(std::string stringMatrix) {
    m_matrix = stringMatrix;
}

std::string Map::render() {
    return m_matrix;
}
