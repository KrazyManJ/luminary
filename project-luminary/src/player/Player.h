#ifndef PROJECT_LUMINARY_PLAYER_H
#define PROJECT_LUMINARY_PLAYER_H

#include "../structs/Position.h"
#include "../console/CharRenderable.h"
#include "PlayerAttack.h"
#include "../inventory/Inventory.h"
#include "../console/CharData.h"
#include "../enums/MovementDirection.h"

#define PLAYER_ATTACKS 4

class Player: public CharRenderable{
    Position m_position;
    float m_health;
    PlayerAttack* m_attacks[PLAYER_ATTACKS]; //jinak deklarovane pole ukazatelu
    Inventory* m_inventory;

public:
    Player(Position position);
    void setPosition(Position newPosition); //nastavuje pozici hrace (v ramci pohybu)
    void addAttack(PlayerAttack* newAttack); //pridava novy utok (pokud jej hrac ziska)
    void dealDamage(unsigned int incomingDamage); //metoda, ktera se bude vyuzivat pro vypocet zdravi v ramci souboje
    void useHeal(unsigned int healIndex); //metoda, pro pouziti zvoleneho healu (je v planu pozdeji aplikovat v ramci inventare)
    Inventory* getInventory(); //preda aktualni stav inventare hrace (v budoucnu aplikovano pro inventar)
    void makeMovement(MovementDirection movementDirection); //na zaklade predaneho smeru pohybu zmeni souradnice
    Position getPosition(); //vraci aktualni pozici hrace
    PlayerAttack** getAttacks();
    ~Player(); //v ramci smazani hrace vymaze i inventar a utoky z pameti
};


#endif //PROJECT_LUMINARY_PLAYER_H
