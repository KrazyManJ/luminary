#ifndef PROJECT_LUMINARY_BATTLEWINDOWATTACKS_H
#define PROJECT_LUMINARY_BATTLEWINDOWATTACKS_H


#include "../ReturnableWindow.h"
#include "../../player/Player.h"
#include "../BattleWindow.h"

class BattleWindowAttacks : public ReturnableWindow{
private:
    Player* m_player;
public:
    BattleWindowAttacks(Window* prevWindow, Player* player);
    void render() override;
    void onInput(ConsoleHandler::KeyEvent *evt) override;
};


#endif //PROJECT_LUMINARY_BATTLEWINDOWATTACKS_H
