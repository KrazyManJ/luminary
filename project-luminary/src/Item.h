#ifndef PROJECT_LUMINARY_ITEM_H
#define PROJECT_LUMINARY_ITEM_H


#include <string>
#include "CharData.h"

class Item {
    std::string m_name;
protected:
    Item(std::string name, CharData *charData);

public:
    void setName(std::string name) {};
};


#endif //PROJECT_LUMINARY_ITEM_H
