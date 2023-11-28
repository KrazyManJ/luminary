#ifndef PROJECT_LUMINARY_MAP_H
#define PROJECT_LUMINARY_MAP_H


#include <string>

class Map {
private:
    std::string m_matrix;
public:
    Map(std::string stringMatrix);
    std::string render();
};


#endif //PROJECT_LUMINARY_MAP_H
