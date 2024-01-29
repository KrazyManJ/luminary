#ifndef PROJECT_LUMINARY_ENEMY_H
#define PROJECT_LUMINARY_ENEMY_H

#include "InteractiveObject.h"
#include "../console/CharData.h"
#include "../inventory/Weapon.h"
#include "../player/PlayerAttack.h"

class Enemy: public InteractiveObject{
    float m_health;
    unsigned int m_damage;
    Weapon* m_lootWeapon;
    PlayerAttack* m_lootAttack;

public:
    Enemy(Position position, float health, unsigned int damage, CharData* charData);
    Enemy(Position position, float health, unsigned int damage, CharData* charData, Weapon* lootWeapon);
    Enemy(Position position, float health, unsigned int damage, CharData* charData, PlayerAttack* lootAttack);
    float getHealth();
    unsigned int getDamage();
    void dealDamage(unsigned int incomingDamage); //nastavi aktualni zdravi nepritele (pozdejsi vyuziti v ramci boje)
    bool hasWeapon();
    bool hasAttack();
    Weapon* getWeapon();
    PlayerAttack* getAttack();
    void onPlayerEnter(Game *game) override;
    void onPlayerProximity(Game *game) override;
};


#endif //PROJECT_LUMINARY_ENEMY_H
