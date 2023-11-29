#ifndef PROJECT_LUMINARY_ITEMENTITY_H
#define PROJECT_LUMINARY_ITEMENTITY_H

#include "../inventory/Item.h"
#include "../map/InteractiveObject.h"
#include "../console/CharData.h"
#include "../structs/Position.h"

class ItemEntity: public InteractiveObject{
private:
    bool m_isTransparent;
    Item* m_item;

public:
    ItemEntity(Item* item, bool isTransparent, Position position, CharData* charData);
    Item* pickUp();
};


#endif //PROJECT_LUMINARY_ITEMENTITY_H
