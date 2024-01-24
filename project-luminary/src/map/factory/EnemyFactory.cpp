

#include "EnemyFactory.h"

Enemy* EnemyFactory::createEnemy(Position position, EnemyType type){
    switch (type) {
        case EASY:
            return new Enemy(position, 50, 15, (new CharBuilder('%'))->background(ColorPalette::GREEN)
                    ->foreground(ColorPalette::YELLOW)->build());
        case MEDIUM:
            return new Enemy(position, 75, 30,(new CharBuilder('%'))->background(ColorPalette::GREEN)
                    ->foreground(ColorPalette::YELLOW)->build());
        case HARD:
            return new Enemy(position, 100, 45,(new CharBuilder('%'))->background(ColorPalette::GREEN)
                    ->foreground(ColorPalette::YELLOW)->build());
        default:
            return nullptr;

    }
}