#ifndef PROJECT_LUMINARY_INVENTORY_H
#define PROJECT_LUMINARY_INVENTORY_H

#include <vector>
#include "Heal.h"
#include "Weapon.h"

class Inventory {
private:
    std::vector<Weapon*> m_weapons;
    std::vector<Heal*> m_heals;

public:
    void addWeapon(Weapon* newWeapon);
    void addHeal(Heal* newHeal);
    void deleteHeal(unsigned int indexOfHeal);
    void deleteWeapon(unsigned int indexOfWeapon);
};


#endif //PROJECT_LUMINARY_INVENTORY_H
