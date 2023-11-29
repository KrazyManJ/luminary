#include "Heal.h"

Heal::Heal(std::string name, float healValue, CharData *charData) : Item(name, charData) {
    m_healValue = healValue;
}

float Heal::getHealValue() {
    return m_healValue;
}
