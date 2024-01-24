
#ifndef PROJECT_LUMINARY_ENEMYFACTORY_H
#define PROJECT_LUMINARY_ENEMYFACTORY_H


#include "../Enemy.h"
#include "../../enums/EnemyType.h"
#include "../../console/CharBuilder.h"
#include "../../palettes/ColorPalette.h"

class EnemyFactory {
public:
    Enemy* createEnemy(Position position, EnemyType type);
};


#endif //PROJECT_LUMINARY_ENEMYFACTORY_H
