#include "CharRenderable.h"

CharRenderable::CharRenderable(CharData* charData){
    m_data = charData;
}

std::string CharRenderable::renderChar(){
    return m_data->toFullChar();
}


