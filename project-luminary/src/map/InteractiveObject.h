
#ifndef PROJECT_LUMINARY_INTERACTIVEOBJECT_H
#define PROJECT_LUMINARY_INTERACTIVEOBJECT_H


#include "../console/CharRenderable.h"

class InteractiveObject : public CharRenderable {
protected:
    Position m_position;

    InteractiveObject(Position position, CharData* charData);
public:
    Position getPosition();

    std::string renderChar() override;
};


#endif //PROJECT_LUMINARY_INTERACTIVEOBJECT_H
