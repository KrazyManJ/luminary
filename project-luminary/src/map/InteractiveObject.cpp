
#include "InteractiveObject.h"

InteractiveObject::InteractiveObject(Position position, CharData *charData) : CharRenderable(charData) {
    m_position = position;
    m_interactable = true;
}

InteractiveObject::InteractiveObject(Position position) : InteractiveObject(position, nullptr){}

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
    if (m_charData != nullptr) {
        return false;
    } else {
        return true;
    }
}

void InteractiveObject::makeUninteractable() {
    m_interactable = false;
}

bool InteractiveObject::isInteractable() {
    return m_interactable;
}
