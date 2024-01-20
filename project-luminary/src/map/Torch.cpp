#include <iostream>
#include "Torch.h"
#include "MapObject.h"
#include "../Game.h"
#include "../palettes/ColorPalette.h"

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
    game->lightUpTorch(this);
}
