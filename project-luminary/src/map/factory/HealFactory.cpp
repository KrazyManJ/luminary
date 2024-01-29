

#include "HealFactory.h"
#include "../../console/CharFactory.h"
#include "../../palettes/ColorPalette.h"


ItemEntity* HealFactory::createHeal(Position position, HealType type) {
    CharData* Carrot = new CharData('"', ColorPalette::GREEN, ColorPalette::ORANGE);
    CharData* MagicCarrot = new CharData('"', ColorPalette::GREEN, ColorPalette::MAGIC_CARROT);
    switch(type) {
        case VISIBLE:
            return new ItemEntity(new Heal("Carrot", 20, Carrot), position, Carrot);
        case INVISIBLE:
            return new ItemEntity(new Heal("Carrot", 20, Carrot), position);
        case MAGIC:
            return new ItemEntity(new Heal("Magic Carrot", 50, MagicCarrot), position, MagicCarrot);
        default:
            return nullptr;
    }
}