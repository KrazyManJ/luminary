#ifndef PROJECT_LUMINARY_BATTLEWINDOWATTACKS_H
#define PROJECT_LUMINARY_BATTLEWINDOWATTACKS_H

#include "../ReturnableWindow.h"
#include "../../player/Player.h"
#include "../BattleWindow.h"

class BattleWindowAttacks : public ReturnableWindow{
private:
    Player* m_player;

    Enemy* m_enemy;

    Cycler* m_battleAttacksCycler;

public:
    BattleWindowAttacks(Window* prevWindow, Player* player, Enemy* enemy); //enemy vstupuje kvuli vypoctu poskozeni

    void render() override; //pretezuje se, protoze je ve Window plne virtualni

    void onInput(ConsoleHandler::KeyEvent *evt) override; //pretezuje se, protoze je ve Window plne virtualni
};

#endif //PROJECT_LUMINARY_BATTLEWINDOWATTACKS_H