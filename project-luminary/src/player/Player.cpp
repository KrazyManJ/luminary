#include "Player.h"
#include "../palettes/ColorPalette.h"
#include "../palettes/CharPalette.h"
#include "../console/CharBuilder.h"


Player::Player(Position position) : CharRenderable(new CharData(CharPalette::PLAYER,ColorPalette::FG_PLAYER,ColorPalette::BG_PLAYER)){
    m_position = position; //nastavuje se v ramci vykreslovani
    m_health = PLAYER_MAX_HEALTH;
    m_inventory = new Inventory();
    m_attacks[0] = new PlayerAttack("Punch", 20);
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

bool Player::useHeal(Heal* heal) {
    if(m_health + heal->getHealValue() <= PLAYER_MAX_HEALTH){
        m_health += heal->getHealValue();
        return true;
    }else{
        return false;
    }
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

int Player::getDamage(PlayerAttack *playerAttack) {
    Weapon* equiped = m_inventory->equipedWeapon();
    if(equiped != nullptr) return playerAttack->getDamage() + equiped->getDamage();
    return playerAttack->getDamage();
}

float Player::getDamageAvg() {
    float damageAvg = 0;
    unsigned availableAttacks = 0;
    for(unsigned i = 0; i < PLAYER_ATTACKS; i++){
        if(m_attacks[i] != nullptr){
            damageAvg += m_attacks[i]->getDamage();
            availableAttacks++;
        }
    }
    if(m_inventory->equipedWeapon() != nullptr) return (damageAvg/(float)availableAttacks)+m_inventory->equipedWeapon()->getDamage();
    return (damageAvg/(float)availableAttacks);
}

Player::~Player() {
    delete m_inventory;
    for(int i = 0; i < PLAYER_ATTACKS - 1; i++){
        delete m_attacks[i];
    }
}
