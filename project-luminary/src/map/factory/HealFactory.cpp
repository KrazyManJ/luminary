

#include "HealFactory.h"
#include "../../console/CharFactory.h"
#include "../../palettes/ColorPalette.h"


ItemEntity* HealFactory::createHeal(Position position, HealType type) {
    switch(type) {
        case VISIBLE:
            return new ItemEntity(new Heal("Carrot", 5, (new CharFactory('"'))->create()), position,
                                  new CharData('"', ColorPalette::GREEN, ColorPalette::ORANGE));
        case INVISIBLE:
            return new ItemEntity(new Heal("Carrot", 5, (new CharFactory())->create()), position);
        case MAGIC:
            return new ItemEntity(new Heal("Magic Carrot", 20, (new CharFactory('"'))->create()), position,
                                  new CharData('"', ColorPalette::GREEN, ColorPalette::MAGIC_CARROT));
        default:
            return nullptr;
    }
}