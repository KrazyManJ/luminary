
#ifndef PROJECT_LUMINARY_CHARFACTORY_H
#define PROJECT_LUMINARY_CHARFACTORY_H
#include "CharData.h"

class CharFactory {
private:
    CharData* m_charData;
public:
    CharFactory(char character = ' ');

    CharFactory* foreground(unsigned int color);

    CharFactory* background(unsigned int color);

    CharFactory* format(ConsoleFormatType format);

    CharData* create();
};


#endif //PROJECT_LUMINARY_CHARFACTORY_H
