#include <iostream>
#include "Torch.h"
#include "MapObject.h"
#include "../Game.h"
#include "../palettes/ColorPalette.h"
#include "../Luminary.h"
#include "../window/game/GameDialog.h"

Torch::Torch() : MapObject(
        new CharData('Y',ColorPalette::UNLIT_TORCH,ColorPalette::DAY_BLUE),
        new CharData('Y',ColorPalette::LIT_TORCH,ColorPalette::ORANGE)
        , true) {
    m_isLit = false;
}

void Torch::lightUp() {
    m_isLit = true;
}

bool Torch::isLit() {
    return m_isLit;
}

std::string Torch::renderChar(bool isLightened) {
    if (isLit()) {
        return m_lightCharData->toFullChar();
    } else {
        return m_data->toFullChar();
    }
}

void Torch::onCollision(Game *game) {
    if (!game->lightUpTorch(this))
        Luminary::getInstance()->openWindow(new GameDialog(
                "Oh, this does not seem to work, maybe I've skipped some torches..."
    ,game), true);
}
