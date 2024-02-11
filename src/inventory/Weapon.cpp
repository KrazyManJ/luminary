#include "Weapon.h"


Weapon::Weapon(std::string name, float damageValue, CharData *charData) : Item(name, charData) {
    m_damageValue = damageValue;
}

float Weapon::getDamage() {
    return m_damageValue;
}
