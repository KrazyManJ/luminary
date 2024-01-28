#ifndef PROJECT_LUMINARY_GAMEITEMPICKUPDIALOGWINDOW_H
#define PROJECT_LUMINARY_GAMEITEMPICKUPDIALOGWINDOW_H


#include "../ReturnableWindow.h"
#include "../../Game.h"

class GameItemPickupDialogWindow : public ReturnableWindow {
private:
    Game* m_game;
    Item* m_item;
public:
    GameItemPickupDialogWindow(Game* game, Item* item);

    void render() override;

    void onInput(ConsoleHandler::KeyEvent *evt) override;
};


#endif //PROJECT_LUMINARY_GAMEITEMPICKUPDIALOGWINDOW_H
