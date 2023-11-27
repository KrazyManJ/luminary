#include "ItemEntity.h"

ItemEntity::ItemEntity(Item *item, bool isTransparent, Position position, CharData *charData): InteractiveObject(position,charData) {
    m_isTransparent = isTransparent;
    m_item = item;
}

Item *ItemEntity::pickUp() {
    return m_item;
}
