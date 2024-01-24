#ifndef PROJECT_LUMINARY_INVENTORY_H
#define PROJECT_LUMINARY_INVENTORY_H

#include <vector>
#include "Heal.h"
#include "Weapon.h"

class Inventory {
private:
    std::vector<Weapon*> m_weapons;
    std::vector<Heal*> m_heals;

    void deleteHeal(unsigned int indexOfHeal); //smaze leceni na konkretni pozici ziskanou v ramci inventare
    void deleteWeapon(unsigned int indexOfWeapon); //smaze zbran na konkretni pozici ziskanou v ramci inventare

public:
    void addWeapon(Weapon* newWeapon); //prida zbran do inventare (do budoucna ziskatelne ve svete)
    void addHeal(Heal* newHeal); //prida leceni do inventare (do budoucna ziskatelne ve svete)
    Heal* getHeal(unsigned int indexOfHeal); //vrati konkretni leceni na konkretni zadane pozici
    std::vector<Heal*> getHeals();
    std::vector<Weapon*> getWeapons();
    ~Inventory(); //v ramci smazani inventare vymaze i leceni a zbrane v nem ulozene z pameti
};


#endif //PROJECT_LUMINARY_INVENTORY_H
