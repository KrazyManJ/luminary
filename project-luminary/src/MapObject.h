

#ifndef PROJECT_LUMINARY_MAPOBJECT_H
#define PROJECT_LUMINARY_MAPOBJECT_H
#include "CharData.h"
#include "CharRenderable.h"

class MapObject : public CharRenderable {
private:
    CharData* m_lightCharData;
    bool m_isObstacle;
protected:
    MapObject(CharData* charData, CharData* lightCharData, bool isObstacle);
public:
    std::string renderChar(bool isLightened);

    bool isObstacle();
};


#endif //PROJECT_LUMINARY_MAPOBJECT_H
