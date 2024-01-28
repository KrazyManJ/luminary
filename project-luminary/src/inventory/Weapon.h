#ifndef PROJECT_LUMINARY_WEAPON_H
#define PROJECT_LUMINARY_WEAPON_H

#include "Item.h"

class Weapon : public Item{
private:
    float m_damageValue;
public:
    Weapon(std::string name, float damageValue, CharData* charData);

    float getDamage();
};


#endif //PROJECT_LUMINARY_WEAPON_H
