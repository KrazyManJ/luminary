#ifndef PROJECT_LUMINARY_CHARRENDERABLE_H
#define PROJECT_LUMINARY_CHARRENDERABLE_H

#include "CharData.h"

class CharRenderable {
protected:
    CharData* m_data;
    CharRenderable(CharData* charData);
public:
    std::string renderChar();
};


#endif //PROJECT_LUMINARY_CHARRENDERABLE_H
