

#include "EnemyFactory.h"

Enemy* EnemyFactory::createEnemy(Position position, EnemyType type, Weapon* weapon, PlayerAttack* playerAttack){
    switch (type) {
        case EASY:
            return new Enemy(position, 50, 15, (new CharFactory('%'))->background(ColorPalette::GREEN)
                    ->foreground(ColorPalette::YELLOW)->create());
        case MEDIUM:
            return new Enemy(position, 75, 30, (new CharFactory('%'))->background(ColorPalette::GREEN)
                    ->foreground(ColorPalette::YELLOW)->create());
        case HARD:
            return new Enemy(position, 100, 45, (new CharFactory('%'))->background(ColorPalette::GREEN)
                    ->foreground(ColorPalette::YELLOW)->create());
        case ARMED:
            return new Enemy(position, 55, 20, (new CharFactory('%'))->background(ColorPalette::GREEN)
                    ->foreground(ColorPalette::YELLOW)->create(), weapon);
        case ATTACK:
            return new Enemy(position, 55, 25, (new CharFactory('%'))->background(ColorPalette::GREEN)
                    ->foreground(ColorPalette::YELLOW)->create(), playerAttack);
        default:
            return nullptr;

    }
}
