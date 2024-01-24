
#ifndef PROJECT_LUMINARY_HEALFACTORY_H
#define PROJECT_LUMINARY_HEALFACTORY_H


#include "../../inventory/Heal.h"
#include "../ItemEntity.h"

class HealFactory {
public:
    ItemEntity* createHeal(Position position);
};


#endif //PROJECT_LUMINARY_HEALFACTORY_H
