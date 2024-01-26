#ifndef PROJECT_LUMINARY_GAMEINFOBAR_H
#define PROJECT_LUMINARY_GAMEINFOBAR_H


#include "../ReturnableWindow.h"
#include "../../Game.h"

class GameInfoBar : public ReturnableWindow {
private:
    Game* m_game;
public:
    GameInfoBar(Game *game);

    void render() override;

    void onInput(ConsoleHandler::KeyEvent *evt) override;
};


#endif //PROJECT_LUMINARY_GAMEINFOBAR_H
