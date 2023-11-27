#ifndef PROJECT_LUMINARY_PLAYER_H
#define PROJECT_LUMINARY_PLAYER_H

#include "structs/Position.h"
#include "CharRenderable.h"
#include "PlayerAttack.h"
#include "Inventory.h"
#include "CharData.h"
#include "enums/MovementDirection.h"

class Player: public CharRenderable{
    Position m_position;
    int m_health;
    PlayerAttack** m_attacks;
    Inventory* m_inventory;
    void setPosition(signed char x, signed char y);

public:
    Player(Position position, CharData* charData);
    void addAttack(PlayerAttack* newAttack);
    void dealDamage(unsigned int incomingDamage);
    void useHeal(unsigned int healIndex);
    Inventory* getInventory();
    void makeMovement(MovementDirection movementDirection);
};


#endif //PROJECT_LUMINARY_PLAYER_H
