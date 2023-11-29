#ifndef PROJECT_LUMINARY_ITEM_H
#define PROJECT_LUMINARY_ITEM_H


#include <string>
#include "../console/CharData.h"
#include "../console/CharRenderable.h"

class Item :public CharRenderable{
private:
    std::string m_name;
protected:
    Item(std::string name, CharData *charData);

public:
    void setName(std::string name);

    std::string getName();

};

#endif //PROJECT_LUMINARY_ITEM_H
