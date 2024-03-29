#ifndef PROJECT_LUMINARY_CHARDATA_H
#define PROJECT_LUMINARY_CHARDATA_H

#define COLOR_NONE 0x1000000

#include <vector>
#include "ConsoleHandler.h"

class CharData {
private:
    char m_character;
    unsigned int m_foregroundColor;
    unsigned int m_backgroundColor;
    std::vector<ConsoleFormatType> m_formats;
public:
    CharData(char character, unsigned int foregroundColor, unsigned int backgroundColor);

    void addFormat(ConsoleFormatType format);

    std::string toFullChar();

    void setBackgroundColor(unsigned int color);

    void setForegroundColor(unsigned int color);

    void setChar(char character);
};


#endif //PROJECT_LUMINARY_CHARDATA_H
