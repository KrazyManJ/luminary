
#ifndef PROJECT_LUMINARY_CHARBUILDER_H
#define PROJECT_LUMINARY_CHARBUILDER_H
#include "CharData.h"

class CharBuilder {
private:
    CharData* m_charData;
public:
    CharBuilder(char character = ' ');

    CharBuilder* foreground(unsigned int color);

    CharBuilder* background(unsigned int color);

    CharBuilder* format(ConsoleHandler::ConsoleFormatType format);

    CharData* build();
};


#endif //PROJECT_LUMINARY_CHARBUILDER_H
