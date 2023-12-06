#include "ItemEntity.h"

ItemEntity::ItemEntity(Item *item, Position position, CharData *charData) : InteractiveObject(position, charData) {
    m_item = item;
}

ItemEntity::ItemEntity(Item *item, Position position) : ItemEntity(item, position, nullptr) {}



Item *ItemEntity::pickUp() {
    auto* item = m_item;
    delete this;
    return item;
}

std::string ItemEntity::renderChar() {
    if(isTransparent()){
        return "";
    } else{
        return InteractiveObject::renderChar();
    }
}
