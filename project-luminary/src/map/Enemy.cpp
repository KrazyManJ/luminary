#include "Enemy.h"
#include "../Game.h"
#include "../Luminary.h"
#include "../window/BattleWindow.h"

Enemy::Enemy(Position position, float health, unsigned int damage, CharData *charData) : InteractiveObject(position, charData) {
    m_health = health;
    m_damage = damage;
    m_lootWeapon = nullptr;
}

Enemy::Enemy(Position position, float health, unsigned int damage, CharData *charData, Weapon *lootWeapon) : Enemy(position,health,damage,charData){
    m_lootWeapon = lootWeapon;
}

float Enemy::getHealth() {
    return m_health;
}

unsigned int Enemy::getDamage() {
    return m_damage;
}


void Enemy::dealDamage(unsigned int incomingDamage) {
    //nedochazi ke kontrole jiti do zapornych cisel, prototoze tuto vlastnost pozdeji vyuzije okno pro souboj
    m_health -= incomingDamage;
}

bool Enemy::hasLoot() {
    if(m_lootWeapon != nullptr) return true;
    return false;
}

Weapon *Enemy::getLoot() {
    return m_lootWeapon;
}

void Enemy::onPlayerEnter(Game *game) {}

void Enemy::onPlayerProximity(Game *game) {
    Luminary::getInstance()->openWindow(new BattleWindow(game, game->getPlayer(), this));
}
