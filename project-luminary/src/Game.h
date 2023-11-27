#ifndef PROJECT_LUMINARY_GAME_H
#define PROJECT_LUMINARY_GAME_H


#include "window/Window.h"

class Game : public Window {
public:
    void render() override;

    void onInput(ConsoleHandler::KeyEvent *evt) override;

    ~Game() override;
};


#endif //PROJECT_LUMINARY_GAME_H
