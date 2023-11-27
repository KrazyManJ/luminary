#include "Player.h"

Player::Player(Position position, CharData* charData) : CharRenderable(charData){
    m_position = position;
    m_health = 100;
    m_attacks = new PlayerAttack*[4];
    m_inventory = new Inventory();
}

void Player::setPosition(signed char x, signed char y) {
    m_position.x += x;
    m_position.y += y;
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

void Player::makeMovement(MovementDirection movementDirection) {
    switch (movementDirection) {
        case RIGHT:
            setPosition(1,0);
            break;
        case LEFT:
            setPosition(-1,0);
            break;
        case UP:
            setPosition(0,-1);
            break;
        case DOWN:
            setPosition(0,1);
            break;
    }
}
