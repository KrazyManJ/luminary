#ifndef PROJECT_LUMINARY_HEAL_H
#define PROJECT_LUMINARY_HEAL_H

#include "Item.h"
#include "CharRenderable.h"

class Heal: public Item {
private:
    float m_healValue;
public:
    Heal(std::string name,float m_healValue, CharData* charData );

    float getHealValue();
};


#endif //PROJECT_LUMINARY_HEAL_H
