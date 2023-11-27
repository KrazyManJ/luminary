#ifndef PROJECT_LUMINARY_LUMINARY_H
#define PROJECT_LUMINARY_LUMINARY_H


#include "window/Window.h"

class Luminary {
private:
    static Luminary* s_instance;
    Window* m_activeWindow;
    bool m_run;
public:
    explicit Luminary(Window* startingWindow);

    static Luminary* getInstance();

    void startLoop();

    void exit();

    Window* getActiveWindow();

    void openWindow(Window* window, bool keepPrevious = false);

    void clearWindowContent();
};


#endif //PROJECT_LUMINARY_LUMINARY_H
