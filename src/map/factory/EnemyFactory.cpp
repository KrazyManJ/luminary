

#include "EnemyFactory.h"

Enemy* EnemyFactory::createEnemy(Position position, EnemyType type, Weapon* weapon, PlayerAttack* playerAttack){
    switch (type) {
        case EASY:
            return new Enemy(position, 25, 15, (new CharFactory('%'))->background(ColorPalette::GREEN)
                    ->foreground(ColorPalette::YELLOW)->create());
        case MEDIUM:
            return new Enemy(position, 50, 25, (new CharFactory('%'))->background(ColorPalette::GREEN)
                    ->foreground(ColorPalette::YELLOW)->create());
        case HARD:
            return new Enemy(position, 75, 35, (new CharFactory('%'))->background(ColorPalette::GREEN)
                    ->foreground(ColorPalette::YELLOW)->create());
        case ARMED:
            return new Enemy(position, 40, 20, (new CharFactory('%'))->background(ColorPalette::YELLOW)
                    ->foreground(ColorPalette::UNLIT_TORCH)->create(), weapon);
        case ATTACK:
            return new Enemy(position, 40, 25, (new CharFactory('%'))->background(ColorPalette::ORANGE)
                    ->foreground(ColorPalette::YELLOW)->create(), playerAttack);
        default:
            return nullptr;

    }
}
