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
    ItemEntity(Item* item, Position position, CharData* charData); //konstruktor pro viditelne "itemy"
    ItemEntity(Item* item, Position position); //konstruktor pro neviditelne "itemy"
    Item* pickUp(); //vrati samotny objekt itemu a smaze "vykreslovanou" ItemEntity
    //pretezuje dedenou metodu pro vraceni vykreslovaneho znaku (v pripade, ze je "neviditelny" vrati prazdny znak)
    std::string renderChar() override;
};


#endif //PROJECT_LUMINARY_ITEMENTITY_H
