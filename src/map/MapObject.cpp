
#include "MapObject.h"

MapObject::MapObject(CharData* charData, CharData* lightCharData, bool isObstacle) : CharRenderable(charData){
    m_lightCharData = lightCharData;
    m_isObstacle = isObstacle;
}

std::string MapObject::renderChar(bool isLightened){
    if (isLightened){
        return m_lightCharData->toFullChar();
    }
    else {
        return m_charData->toFullChar();
    }
}

bool MapObject::isObstacle(){
    return m_isObstacle;
}

void MapObject::onCollision(Game *game) {}