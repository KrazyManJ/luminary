#include <iostream>
#include "Torch.h"
#include "MapObject.h"
#include "../Game.h"
#include "../palettes/ColorPalette.h"

Torch::Torch() : MapObject(
        new CharData('Y',ColorPalette::UNLIT_TORCH,ColorPalette::DAY_BLUE),
        new CharData('Y',ColorPalette::LIT_TORCH,ColorPalette::ORANGE)
        , true) {
    m_isLightened = false;
}

void Torch::lightUp() {
    m_isLightened = true;
}

bool Torch::isLit() {
    return m_isLightened;
}

std::string Torch::renderChar() {
    if (m_isLightened) {
        return m_lightCharData->toFullChar();
    } else {
        return m_data->toFullChar();
    }
}

void Torch::onCollision(Game *game) {

}
