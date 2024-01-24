#ifndef PROJECT_LUMINARY_ENEMY_H
#define PROJECT_LUMINARY_ENEMY_H

#include "InteractiveObject.h"
#include "../console/CharData.h"
#include "../inventory/Weapon.h"

class Enemy: public InteractiveObject{
    float m_health;
    unsigned int m_damage;
    Weapon* m_lootWeapon;

public:
    Enemy(Position position, float health, unsigned int damage, CharData* charData);
    Enemy(Position position, float health, unsigned int damage, CharData* charData, Weapon* lootWeapon);
    float getHealth();
    unsigned int getDamage();
    void dealDamage(unsigned int incomingDamage); //nastavi aktualni zdravi nepritele (pozdejsi vyuziti v ramci boje)
    void onPlayerEnter(Game *game) override;
    void onPlayerProximity(Game *game) override;
};


#endif //PROJECT_LUMINARY_ENEMY_H
