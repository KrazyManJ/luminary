#include "Torch.h"
#include "MapObject.h"

Torch::Torch(CharData *charData, CharData *lightCharData) : MapObject(charData, lightCharData, true) {
    m_isLightened = false;
}

void Torch::lightUp() {
    m_isLightened = true;
}

bool Torch::isLightened() {
    return m_isLightened;
}

std::string Torch::renderChar() {
    if (m_isLightened) {
        return m_lightCharData->toFullChar();
    } else {
        return m_data->toFullChar();
    }
}
