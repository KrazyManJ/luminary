#ifndef PROJECT_LUMINARY_WINDOW_H
#define PROJECT_LUMINARY_WINDOW_H


#include "../ConsoleHandler.h"

class Window {
public:
    static const unsigned int WIDTH = 80;
    static const unsigned int HEIGHT = 25;

    virtual void render() = 0;

    virtual void onInput(ConsoleHandler::KeyEvent *evt) = 0;

    virtual ~Window()=0;
};


#endif //PROJECT_LUMINARY_WINDOW_H
