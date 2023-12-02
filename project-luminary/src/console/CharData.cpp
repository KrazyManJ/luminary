#include "CharData.h"

CharData::CharData(char character, unsigned int foregroundColor, unsigned int backgroundColor) {
    m_character = character;
    m_backgroundColor = backgroundColor;
    m_foregroundColor = foregroundColor;
}

void CharData::addFormat(ConsoleFormatType format) {
    m_formats.push_back(format);
}

std::string CharData::toFullChar() {
    std::string result;
    if (m_backgroundColor < COLOR_NONE)
        result += ConsoleHandler::getColorChar(m_backgroundColor, BACKGROUND);
    if (m_foregroundColor < COLOR_NONE)
        result += ConsoleHandler::getColorChar(m_foregroundColor, FOREGROUND);
    for (ConsoleFormatType type: m_formats)
        result += ConsoleHandler::getFormatChar(type);
    return result + m_character + ConsoleHandler::getFormatChar(RESET);
}

void CharData::setBackgroundColor(unsigned int color) {
    m_backgroundColor = color;
}

void CharData::setForegroundColor(unsigned int color) {
    m_foregroundColor = color;
}

void CharData::setChar(char character) {
    m_character = character;
}
