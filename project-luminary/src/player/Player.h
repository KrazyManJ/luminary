#ifndef PROJECT_LUMINARY_PLAYER_H
#define PROJECT_LUMINARY_PLAYER_H

#include "../structs/Position.h"
#include "../console/CharRenderable.h"
#include "PlayerAttack.h"
#include "../inventory/Inventory.h"
#include "../console/CharData.h"
#include "../enums/MovementDirection.h"

class Player: public CharRenderable{
    Position m_position;
    int m_health;
    PlayerAttack** m_attacks;
    Inventory* m_inventory;

public:
    Player(Position position);
    void setPosition(Position newPosition);
    void addAttack(PlayerAttack* newAttack);
    void dealDamage(unsigned int incomingDamage);
    void useHeal(unsigned int healIndex);
    Inventory* getInventory();
    void makeMovement(MovementDirection movementDirection);
    Position getPosition();
    ~Player();
};


#endif //PROJECT_LUMINARY_PLAYER_H
