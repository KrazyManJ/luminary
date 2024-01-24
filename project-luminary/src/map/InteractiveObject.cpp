
#include "InteractiveObject.h"

InteractiveObject::InteractiveObject(Position position, CharData *charData) : CharRenderable(charData) {
    m_position = position;
}
InteractiveObject::InteractiveObject(Position position) : CharRenderable(nullptr){
    m_position = position;
    m_available = true;
}

Position InteractiveObject::getPosition() {
    return m_position;
}

std::string InteractiveObject::renderChar() {
    if(isTransparent()){
        return "";
    } else {
        return CharRenderable::renderChar();
    }
}
bool InteractiveObject::isTransparent(){
    if (m_data != nullptr) {
        return false;
    } else {
        return true;
    }
}

void InteractiveObject::changeState() {
    m_available = false;
}

bool InteractiveObject::getState() {
    return m_available;
}
