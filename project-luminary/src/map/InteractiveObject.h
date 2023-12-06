
#ifndef PROJECT_LUMINARY_INTERACTIVEOBJECT_H
#define PROJECT_LUMINARY_INTERACTIVEOBJECT_H


#include "../console/CharRenderable.h"

class InteractiveObject : public CharRenderable {
protected:
    Position m_position;

    InteractiveObject(Position position, CharData* charData);
    InteractiveObject(Position position);

public:
    Position getPosition();

    std::string renderChar() override;

    bool isTransparent();
};


#endif //PROJECT_LUMINARY_INTERACTIVEOBJECT_H
