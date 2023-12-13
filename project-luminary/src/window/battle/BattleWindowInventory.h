#ifndef PROJECT_LUMINARY_BATTLEWINDOWINVENTORY_H
#define PROJECT_LUMINARY_BATTLEWINDOWINVENTORY_H


#include "../../player/Player.h"
#include "../ReturnableWindow.h"

class BattleWindowInventory : public ReturnableWindow{
private:
    Player* m_player;
public:
    BattleWindowInventory(Window* prevWindow, Player* player);
    void onInput(ConsoleHandler::KeyEvent *evt) override;
    void render() override;
};


#endif //PROJECT_LUMINARY_BATTLEWINDOWINVENTORY_H
