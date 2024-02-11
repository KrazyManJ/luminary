#ifndef PROJECT_LUMINARY_BATTLEWINDOW_H
#define PROJECT_LUMINARY_BATTLEWINDOW_H

#include "ReturnableWindow.h"
#include "../player/Player.h"
#include "../map/Enemy.h"
#include "../utils/Cycler.h"
#include <iostream>

#define AMOUNT_OF_CHOISES 2 //urcuje mnozstvi moznosti zobrazovanych v uvodu battlu

class BattleWindow : public ReturnableWindow{ //ReturnableWindow = okno, ktere uchovava okno, ze ktereho se "otevrelo"
    Player* m_player;

    Enemy* m_enemy;

    Cycler* m_battleCycler; //slouzi pro formatovani "vyberu moznosti"

    bool m_end; //slouzi pro to, aby neslo vkladat nepovolene inputy pri zavirani BattleWindow

public:
    BattleWindow(Window* prevWindow, Player* player, Enemy* enemy); //do konstruktoru vstupuje hrac a aktualni enemy

    void render() override;

    void onInput(ConsoleHandler::KeyEvent *evt) override;
};


#endif //PROJECT_LUMINARY_BATTLEWINDOW_H
