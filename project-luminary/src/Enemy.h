#ifndef PROJECT_LUMINARY_ENEMY_H
#define PROJECT_LUMINARY_ENEMY_H

#include "InteractiveObject.h"
#include "CharData.h"

class Enemy: public InteractiveObject{
    int m_health;
    unsigned int m_damage;

public:
    Enemy(int health, unsigned int damage, CharData* charData, CharData* lightCharData);
    int getHealth();
    unsigned int getDamage();
    void dealHealth(unsigned int incomingDamage);
};


#endif //PROJECT_LUMINARY_ENEMY_H
