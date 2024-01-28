#ifndef PROJECT_LUMINARY_GAMEENDINGWINDOW_H
#define PROJECT_LUMINARY_GAMEENDINGWINDOW_H


#include "../Window.h"
#include "../../Game.h"
#include "../ReturnableWindow.h"

class GameEndingWindow : public ReturnableWindow {
private:
    Game* m_game;
    int m_step;
    Window* m_currentWindow;
public:
    GameEndingWindow(Game* game);

    void render() override;

    void onInput(ConsoleHandler::KeyEvent *evt) override;
};


#endif //PROJECT_LUMINARY_GAMEENDINGWINDOW_H
