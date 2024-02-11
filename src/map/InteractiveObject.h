
#ifndef PROJECT_LUMINARY_INTERACTIVEOBJECT_H
#define PROJECT_LUMINARY_INTERACTIVEOBJECT_H


#include "../console/CharRenderable.h"

class Game;

class InteractiveObject : public CharRenderable {
protected:
    Position m_position;

    InteractiveObject(Position position, CharData* charData);

    InteractiveObject(Position position);

    bool m_interactable;
public:
    Position getPosition();

    std::string renderChar() override;

    bool isTransparent();

    virtual void onPlayerProximity(Game* game) = 0;

    virtual void onPlayerEnter(Game* game) = 0;

    void makeUninteractable();

    bool isInteractable();
};


#endif //PROJECT_LUMINARY_INTERACTIVEOBJECT_H
