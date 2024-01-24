

#ifndef PROJECT_LUMINARY_NPC_H
#define PROJECT_LUMINARY_NPC_H


#include "MapObject.h"

class NPC : public MapObject {
private:
    std::string m_dialogue;
public:
    NPC(char character, std::string dialogue);

    void onCollision(Game* game) override;
};


#endif //PROJECT_LUMINARY_NPC_H
