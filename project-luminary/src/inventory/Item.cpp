#include "Item.h"


Item::Item(std::string name, CharData *charData): CharRenderable(charData) {
    setName(name);
}

void Item::setName(std::string name) {
    m_name = name;
}

std::string Item::getName() {
    return m_name;
}



