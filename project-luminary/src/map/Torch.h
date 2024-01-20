#ifndef PROJECT_LUMINARY_TORCH_H
#define PROJECT_LUMINARY_TORCH_H

#include "MapObject.h"

class Torch : public MapObject {
private:
    bool m_isLit;
public:
    Torch();

    void lightUp();

    bool isLit();

    std::string renderChar(bool isLightened) override;

    void onCollision(Game *game) override;
};


#endif //PROJECT_LUMINARY_TORCH_H
