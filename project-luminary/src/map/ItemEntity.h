#ifndef PROJECT_LUMINARY_ITEMENTITY_H
#define PROJECT_LUMINARY_ITEMENTITY_H

#include "../inventory/Item.h"
#include "../map/InteractiveObject.h"
#include "../console/CharData.h"
#include "../structs/Position.h"

class ItemEntity: public InteractiveObject{
private:
    Item* m_item;

public:
    ItemEntity(Item* item, Position position, CharData* charData);
    ItemEntity(Item* item, Position position);
    Item* pickUp();
    bool isTransparent();
    std::string renderChar() override;
};


#endif //PROJECT_LUMINARY_ITEMENTITY_H
