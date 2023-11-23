#include "Player.h"

Player::Player(Position position){
    m_position = position;
    m_health = 100;
    //m_attacks = {nullptr, nullptr, nullptr, nullptr};
}

void Player::calculateHealth(unsigned int incomingDamage) {
    m_health -= incomingDamage;
}

void Player::useHeal(unsigned int healIndex) {
    //Heal heal = inventory->getHeal(healIndex);
    //m_health += heal->getHealValue();
    //inventory->deleteHeal(healIndex);
}
