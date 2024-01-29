
#ifndef PROJECT_LUMINARY_ENEMYFACTORY_H
#define PROJECT_LUMINARY_ENEMYFACTORY_H


#include "../Enemy.h"
#include "../../enums/EnemyType.h"
#include "../../console/CharFactory.h"
#include "../../palettes/ColorPalette.h"
#include "../../player/PlayerAttack.h"

class EnemyFactory {
public:
    Enemy* createEnemy(Position position, EnemyType type, Weapon* weapon = nullptr, PlayerAttack* playerAttack = nullptr);
};


#endif //PROJECT_LUMINARY_ENEMYFACTORY_H
