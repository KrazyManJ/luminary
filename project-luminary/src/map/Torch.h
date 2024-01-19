#ifndef PROJECT_LUMINARY_TORCH_H
#define PROJECT_LUMINARY_TORCH_H

#include "MapObject.h"

class Torch : public MapObject {
private:
    bool m_isLightened;
public:
    Torch();

    void lightUp();

    bool isLit();

    std::string renderChar() override;

    void onCollision(Game *game) override;
};


#endif //PROJECT_LUMINARY_TORCH_H
