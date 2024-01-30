#include "CharRenderable.h"

CharRenderable::CharRenderable(CharData* charData){ //trida uchovava jak bude objekt na mape vypadat
    m_charData = charData;
}

std::string CharRenderable::renderChar(){ //metoda pro predani do jednoho stringu
    return m_charData->toFullChar();
}


