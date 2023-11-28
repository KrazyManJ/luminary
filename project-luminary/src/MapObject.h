//
// Created by redgu on 11/28/2023.
//

#ifndef PROJECT_LUMINARY_MAPOBJECT_H
#define PROJECT_LUMINARY_MAPOBJECT_H
#include "CharData.h"

class MapObject {
private:
    bool m_isObstacle;
protected:
    MapObject(CharData* charData, CharData* lightCharData, bool isObstacle);

    std::string renderChar(bool isLightened);

    bool isObstacle();
};


#endif //PROJECT_LUMINARY_MAPOBJECT_H
