#include "Enemy.h"

Enemy::Enemy(Position position, int health, unsigned int damage, CharData *charData) : InteractiveObject(position, charData) {
    m_health = health;
    m_damage = damage;
}

int Enemy::getHealth() {
    return m_health;
}

unsigned int Enemy::getDamage() {
    return m_damage;
}

void Enemy::dealDamage(unsigned int incomingDamage) {
    m_health -= incomingDamage;
}
