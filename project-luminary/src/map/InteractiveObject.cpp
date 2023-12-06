
#include "InteractiveObject.h"

InteractiveObject::InteractiveObject(Position position, CharData *charData) : CharRenderable(charData) {
    m_position = position;
}
InteractiveObject::InteractiveObject(Position position) : CharRenderable(nullptr){
    m_position = position;
}

Position InteractiveObject::getPosition() {
    return m_position;
}

std::string InteractiveObject::renderChar() {
    return CharRenderable::renderChar();
}
bool InteractiveObject::isTransparent(){
    if (m_data != nullptr) {
        return false;
    } else {
        return true;
    }
}
