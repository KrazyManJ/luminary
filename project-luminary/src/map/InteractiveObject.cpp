
#include "InteractiveObject.h"

InteractiveObject::InteractiveObject(Position position, CharData *charData) : CharRenderable(charData) {
    m_position = position;
}

Position InteractiveObject::getPosition() {
    return m_position;
}

std::string InteractiveObject::renderChar() {
    return CharRenderable::renderChar();
}
