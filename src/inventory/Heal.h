#ifndef PROJECT_LUMINARY_HEAL_H
#define PROJECT_LUMINARY_HEAL_H

#include "Item.h"
#include "../console/CharRenderable.h"

class Heal : public Item {
private:
    float m_healValue;
public:
    Heal(std::string name, float healValue, CharData *charData);

    float getHealValue();
};


#endif //PROJECT_LUMINARY_HEAL_H
