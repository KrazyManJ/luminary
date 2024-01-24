#ifndef PROJECT_LUMINARY_LUMINARY_H
#define PROJECT_LUMINARY_LUMINARY_H


#include "window/Window.h"
#include "Game.h"


class Luminary {
private:
    static Luminary *s_instance;
    Window *m_activeWindow;
    bool m_run;
    Game* m_lastGame;
public:
    explicit Luminary(Window *startingWindow);

    static Luminary *getInstance();

    void startLoop();

    void exit();

    Window *getActiveWindow();

    void openWindow(Window *window, bool keepPrevious = false);

    void startNewGame();

    void resetGame();

    void clearWindowContent();

    Game* getLastGame();
};


#endif //PROJECT_LUMINARY_LUMINARY_H
