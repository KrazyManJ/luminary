#include "Inventory.h"

Inventory::Inventory() {
    m_nowEquiped = nullptr;
}

void Inventory::addWeapon(Weapon *newWeapon) {
    m_weapons.push_back(newWeapon);
}

void Inventory::addHeal(Heal *newHeal) {
    m_heals.push_back(newHeal);
}

void Inventory::deleteHeal(unsigned int indexOfHeal) {
    delete getHeal(indexOfHeal);
    m_heals.erase(m_heals.begin()+indexOfHeal);
}

void Inventory::deleteWeapon(unsigned int indexOfWeapon) {
    delete m_weapons.at(indexOfWeapon);
    m_weapons.erase(m_weapons.begin()+indexOfWeapon);
}

Heal *Inventory::getHeal(unsigned int indexOfHeal) {
    return m_heals.at(indexOfHeal);
}

Weapon *Inventory::getWeapon(unsigned int indexOfWeapon) {
    return m_weapons.at(indexOfWeapon);
}

std::vector<Heal *> Inventory::getHeals() {
    return m_heals;
}

std::vector<Weapon *> Inventory::getWeapons() {
    return m_weapons;
}

void Inventory::equipWeapon(unsigned int indexOfWeapon) {
    m_nowEquiped = getWeapon(indexOfWeapon);
}

Weapon *Inventory::equipedWeapon() {
    return m_nowEquiped;
}

bool Inventory::useHeal(unsigned int indexOfHeal, Player* player) {
    auto * heal = getHeal(indexOfHeal);
    if(heal->getHealValue() + player->getHealth() <= PLAYER_MAX_HEALTH){
        player->useHeal(heal);
        deleteHeal(indexOfHeal);
        return true;
    }else{
        return false;
    }
}

Inventory::~Inventory() {
    for(Weapon* weapon: m_weapons){
        delete weapon;
    }
    m_weapons.clear();
    for(Heal* heal: m_heals){
        delete heal;
    }
    m_heals.clear();
}
