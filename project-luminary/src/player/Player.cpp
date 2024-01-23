#include "Player.h"
#include "../palettes/ColorPalette.h"
#include "../palettes/CharPalette.h"



Player::Player(Position position) : CharRenderable(new CharData(CharPalette::PLAYER,ColorPalette::FG_PLAYER,ColorPalette::BG_PLAYER)){
    m_position = position; //nastavuje Kata v ramci vykreslovani
    m_health = 100;
    m_inventory = new Inventory();
    m_attacks[0] = new PlayerAttack("Punch", 35);
    for(int i = 1; i < PLAYER_ATTACKS; i++){
        m_attacks[i] = nullptr;
    }
}

void Player::setPosition(Position newPosition) {
    m_position = newPosition;
}

void Player::addAttack(PlayerAttack *newAttack) {
    char indexOfAttack = 0;
    while(m_attacks[indexOfAttack]!= nullptr && indexOfAttack <= 4){
        //vyhledava misto pro vlozeni noveho utoku (neni omezeno na velikost pole,
        // protoze zatim neni planovano vice utoku nez 4)
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
            m_position.x++;
            break;
        case LEFT:
            m_position.x--;
            break;
        case UP:
            m_position.y--;
            break;
        case DOWN:
            m_position.y++;
            break;
    }
}

Position Player::getPosition() {
    return m_position;
}

PlayerAttack** Player::getAttacks() {
    return m_attacks;
}

float Player::getHealth() {
    return m_health;
}

Player::~Player() {
    delete m_inventory;
    for(int i = 0; i < PLAYER_ATTACKS - 1; i++){
        delete m_attacks[i];
    }
}
