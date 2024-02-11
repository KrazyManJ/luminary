#ifndef PROJECT_LUMINARY_GAMERETURNABLEWINDOW_H
#define PROJECT_LUMINARY_GAMERETURNABLEWINDOW_H


#include "../ReturnableWindow.h"
#include "../../Game.h"

class GameReturnableWindow : public ReturnableWindow {
protected:
    Game* m_game;
    explicit GameReturnableWindow(Game* game);
};


#endif //PROJECT_LUMINARY_GAMERETURNABLEWINDOW_H
