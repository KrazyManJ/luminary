#ifndef PROJECT_LUMINARY_TORCH_H
#define PROJECT_LUMINARY_TORCH_H

#include "MapObject.h"

class Torch : public MapObject {
private:
    bool m_isLightened;
public:
    Torch(CharData *charData, CharData *lightCharData);

    void lightUp();

    bool isLightened();

    std::string renderChar() override;
};


#endif //PROJECT_LUMINARY_TORCH_H
