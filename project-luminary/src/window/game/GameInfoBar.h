#ifndef PROJECT_LUMINARY_GAMEINFOBAR_H
#define PROJECT_LUMINARY_GAMEINFOBAR_H


#include "../../Game.h"
#include "GameReturnableWindow.h"

class GameInfoBar : public GameReturnableWindow {
public:
    GameInfoBar(Game *game);

    void render() override;

    void onInput(ConsoleHandler::KeyEvent *evt) override;
};


#endif //PROJECT_LUMINARY_GAMEINFOBAR_H
