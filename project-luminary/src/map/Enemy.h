#ifndef PROJECT_LUMINARY_ENEMY_H
#define PROJECT_LUMINARY_ENEMY_H

#include "InteractiveObject.h"
#include "../console/CharData.h"

class Enemy: public InteractiveObject{
    int m_health;
    unsigned int m_damage;

public:
    Enemy(Position position, int health, unsigned int damage, CharData* charData);
    int getHealth();
    unsigned int getDamage();
    void dealDamage(unsigned int incomingDamage);
};


#endif //PROJECT_LUMINARY_ENEMY_H
