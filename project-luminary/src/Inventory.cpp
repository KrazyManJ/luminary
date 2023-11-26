#include "Inventory.h"

void Inventory::addWeapon(Weapon *newWeapon) {
    m_weapons.push_back(newWeapon);
}

void Inventory::addHeal(Heal *newHeal) {
    m_heals.push_back(newHeal);
}

void Inventory::deleteHeal(unsigned int indexOfHeal) {
    delete m_heals.at(indexOfHeal);
    m_heals.erase(m_heals.begin()+indexOfHeal);
}

void Inventory::deleteWeapon(unsigned int indexOfWeapon) {
    delete m_weapons.at(indexOfWeapon);
    m_weapons.erase(m_weapons.begin()+indexOfWeapon);
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
