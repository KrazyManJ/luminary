
#include "CharFactory.h"

CharFactory::CharFactory(char character) {
    m_charData = new CharData(character, COLOR_NONE, COLOR_NONE);
}

CharFactory *CharFactory::foreground(unsigned int color) {
    m_charData->setForegroundColor(color);
    return this;
}

CharFactory *CharFactory::background(unsigned int color) {
    m_charData->setBackgroundColor(color);
    return this;
}

CharFactory *CharFactory::format(ConsoleFormatType format) {
    m_charData->addFormat(format);
    return this;
}

CharData *CharFactory::create() {
    auto* charData = m_charData;
    delete this;
    return charData;
}
