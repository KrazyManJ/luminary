
#ifndef PROJECT_LUMINARY_HEALFACTORY_H
#define PROJECT_LUMINARY_HEALFACTORY_H


#include "../../inventory/Heal.h"
#include "../ItemEntity.h"
#include "../../enums/HealType.h"

class HealFactory {
public:
    ItemEntity* createHeal(Position position, HealType type);
};


#endif //PROJECT_LUMINARY_HEALFACTORY_H
