#include <string>
#include "PlayerAttack.h"

PlayerAttack::PlayerAttack(std::string name, float damage) {
    m_name = name;
    m_damage = damage;
}

std::string PlayerAttack::getName() {
    return m_name;
}

float PlayerAttack::getDamage() {
    return m_damage;
}
