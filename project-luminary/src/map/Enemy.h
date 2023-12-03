#ifndef PROJECT_LUMINARY_ENEMY_H
#define PROJECT_LUMINARY_ENEMY_H

#include "InteractiveObject.h"
#include "../console/CharData.h"

class Enemy: public InteractiveObject{
    float m_health;
    unsigned int m_damage;

public:
    Enemy(Position position, float health, unsigned int damage, CharData* charData);
    int getHealth();
    unsigned int getDamage();
    void dealDamage(unsigned int incomingDamage); //nastavi aktualni zdravi nepritele (pozdejsi vyuziti v ramci boje)
};


#endif //PROJECT_LUMINARY_ENEMY_H
