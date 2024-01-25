#include "ItemEntity.h"
#include "../Game.h"


ItemEntity::ItemEntity(Item *item, Position position, CharData *charData) : InteractiveObject(position, charData) {
    m_item = item;
}

ItemEntity::ItemEntity(Item *item, Position position) : ItemEntity(item, position, nullptr) {}



void ItemEntity::pickUp() {
    delete this;
}

std::string ItemEntity::renderChar() {
    if(isTransparent()){
        return "";
    } else{
        return InteractiveObject::renderChar();
    }
}

void ItemEntity::onPlayerProximity(Game *game) {}

void ItemEntity::onPlayerEnter(Game *game) {
    Inventory* playersInventory = game->getPlayer()->getInventory();
    Heal* isHeal = dynamic_cast<Heal*>(m_item);
    if(isHeal != nullptr){
        playersInventory->addHeal(isHeal);
    }else{
        Weapon* weapon = dynamic_cast<Weapon*>(m_item);
        playersInventory->addWeapon(weapon);
    }
    pickUp();
}
