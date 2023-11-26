#ifndef PROJECT_LUMINARY_PLAYER_H
#define PROJECT_LUMINARY_PLAYER_H

#include "structs/Position.h"
#include "CharRenderable.h"
#include "PlayerAttack.h"
#include "Inventory.h"
#include "CharData.h"

class Player: public CharRenderable{
    Position m_position;
    float m_health;
    PlayerAttack** m_attacks;
    Inventory* m_inventory;

public:
    Player(Position position, CharData* charData);
    void addAttack(PlayerAttack* newAttack);
    void dealDamage(unsigned int incomingDamage);
    void useHeal(unsigned int healIndex);
    Inventory* getInventory();
};


#endif //PROJECT_LUMINARY_PLAYER_H
