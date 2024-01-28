#ifndef PROJECT_LUMINARY_GAMEITEMPICKUPDIALOGWINDOW_H
#define PROJECT_LUMINARY_GAMEITEMPICKUPDIALOGWINDOW_H


#include "../../Game.h"
#include "GameReturnableWindow.h"

class GameItemPickupDialogWindow : public GameReturnableWindow {
private:
    Item* m_item;
public:
    GameItemPickupDialogWindow(Game* game, Item* item);

    void render() override;

    void onInput(ConsoleHandler::KeyEvent *evt) override;
};


#endif //PROJECT_LUMINARY_GAMEITEMPICKUPDIALOGWINDOW_H
