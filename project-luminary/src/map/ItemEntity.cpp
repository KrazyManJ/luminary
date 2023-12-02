#include "ItemEntity.h"

ItemEntity::ItemEntity(Item *item, Position position, CharData *charData) : InteractiveObject(position, charData) {
    m_item = item;
}

ItemEntity::ItemEntity(Item *item, Position position) : ItemEntity(item, position, nullptr) {}

bool ItemEntity::isTransparent() {
    if (m_data != nullptr) {
        return false;
    } else {
        return true;
    }
}

Item *ItemEntity::pickUp() {
    auto* item = m_item;
    delete this;
    return m_item;
}

std::string ItemEntity::renderChar() {
    if(isTransparent()){
        return "";
    } else{
        return InteractiveObject::renderChar();
    }
}
