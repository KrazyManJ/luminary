
#include "CharBuilder.h"

CharBuilder::CharBuilder(char character) {
    m_charData = new CharData(character, COLOR_NONE, COLOR_NONE);
}

CharBuilder *CharBuilder::foreground(unsigned int color) {
    m_charData->setForegroundColor(color);
    return this;
}

CharBuilder *CharBuilder::background(unsigned int color) {
    m_charData->setBackgroundColor(color);
    return this;
}

CharBuilder *CharBuilder::format(ConsoleFormatType format) {
    m_charData->addFormat(format);
    return this;
}

CharData *CharBuilder::build() {
    auto* charData = m_charData;
    delete this;
    return charData;
}
