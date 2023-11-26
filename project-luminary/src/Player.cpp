#include "Player.h"

Player::Player(Position position, CharData* charData) : CharRenderable(charData){
    m_position = position;
    m_health = 100;
    m_attacks = new PlayerAttack*[4];
    m_inventory = new Inventory();
}

void Player::addAttack(PlayerAttack *newAttack) {
    char indexOfAttack = 0;
    while(m_attacks[indexOfAttack]!= nullptr){
        indexOfAttack++;
    }
    m_attacks[indexOfAttack] = newAttack;
}

void Player::dealDamage(unsigned int incomingDamage) {
    m_health -= incomingDamage;
}

void Player::useHeal(unsigned int healIndex) {
    Heal* heal = m_inventory->getHeal(healIndex);
    m_health += heal->getHealValue();
    m_inventory->deleteHeal(healIndex);
}

Inventory* Player::getInventory() {
    return m_inventory;
}