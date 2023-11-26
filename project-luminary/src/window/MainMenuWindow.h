#ifndef PROJECT_LUMINARY_MAINMENUWINDOW_H
#define PROJECT_LUMINARY_MAINMENUWINDOW_H


#include "Window.h"

class MainMenuWindow : public Window {
private:
    unsigned int keypressed;
public:
    MainMenuWindow();

    void render() override;

    void onInput(ConsoleHandler::KeyEvent *evt) override;
};


#endif //PROJECT_LUMINARY_MAINMENUWINDOW_H
