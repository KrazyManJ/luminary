

#include "HealFactory.h"
#include "../../console/CharBuilder.h"
#include "../../palettes/ColorPalette.h"


ItemEntity* HealFactory::createHeal(Position position) {
    return new ItemEntity(new Heal("Carrot", 5, (new CharBuilder('"'))->build()), position,
                          new CharData('"', ColorPalette::GREEN, ColorPalette::ORANGE));
}