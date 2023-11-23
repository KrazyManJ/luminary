//
// Created by Martin on 23.11.2023.
//

#ifndef PROJECT_LUMINARY_PLAYER_H
#define PROJECT_LUMINARY_PLAYER_H

#include "structs/Position.h"
#include "CharRenderable.h"

class Player: public CharRenderable{
    Position m_position;
    float m_health;
    //PlayerAttack* m_attacks[4];
    //Inventory* m_inventory;

public:
    Player(Position position);
    //void addAttack(PlayerAttack* newAttack);
    void calculateHealth(unsigned int incomingDamage);
    void useHeal(unsigned int healIndex);
    //Inventory* getInventory();
};


#endif //PROJECT_LUMINARY_PLAYER_H
