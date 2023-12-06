#ifndef PROJECT_LUMINARY_BATTLEWINDOW_H
#define PROJECT_LUMINARY_BATTLEWINDOW_H

#include "ReturnableWindow.h"
#include "../player/Player.h"
#include "../map/Enemy.h"
#include <iostream>

class BattleWindow : public ReturnableWindow{
    Player* m_player;
    Enemy* m_enemy;
public:
    BattleWindow(Window* prevWindow, Player* player, Enemy* enemy);
    void render() override;
    void onInput(ConsoleHandler::KeyEvent *evt) override;
};


#endif //PROJECT_LUMINARY_BATTLEWINDOW_H
