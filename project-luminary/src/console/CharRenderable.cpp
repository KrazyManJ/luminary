#include "CharRenderable.h"

CharRenderable::CharRenderable(CharData* charData){
    m_charData = charData;
}

std::string CharRenderable::renderChar(){
    return m_charData->toFullChar();
}


