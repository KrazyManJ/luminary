#include "ItemEntity.h"
#include "../Game.h"
#include "../Luminary.h"
#include "../window/game/GameItemPickupDialogWindow.h"


ItemEntity::ItemEntity(Item *item, Position position, CharData *charData) : InteractiveObject(position, charData) {
    m_item = item;
}

ItemEntity::ItemEntity(Item *item, Position position) : ItemEntity(item, position, nullptr) {}



Item* ItemEntity::pickUp() {
    auto * item = m_item;
    makeUninteractable();
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

void ItemEntity::onPlayerProximity(Game *game) {}

void ItemEntity::onPlayerEnter(Game *game) {
    Inventory* playersInventory = game->getPlayer()->getInventory();
    if(dynamic_cast<Heal*>(m_item) != nullptr){
        playersInventory->addHeal(dynamic_cast<Heal*>(m_item));
        Luminary::getInstance()->openWindow(new GameItemPickupDialogWindow(game,pickUp()), true);
    }else{
        playersInventory->addWeapon(dynamic_cast<Weapon*>(m_item));
        Luminary::getInstance()->openWindow(new GameItemPickupDialogWindow(game,pickUp()), true);
    }
}
