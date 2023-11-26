#ifndef PROJECT_LUMINARY_WINDOW_H
#define PROJECT_LUMINARY_WINDOW_H


#include "../ConsoleHandler.h"

class Window {
public:
    virtual void render() = 0;

    virtual void onInput(ConsoleHandler::KeyEvent *evt) = 0;
};


#endif //PROJECT_LUMINARY_WINDOW_H
