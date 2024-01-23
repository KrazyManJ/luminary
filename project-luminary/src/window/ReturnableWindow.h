#ifndef PROJECT_LUMINARY_RETURNABLEWINDOW_H
#define PROJECT_LUMINARY_RETURNABLEWINDOW_H


#include "Window.h"

class ReturnableWindow : public Window {
private:
    Window* m_prevWindow;
protected:
    ReturnableWindow(Window* prevWindow);
public:

    virtual void close(bool keepPrevious = false);
};


#endif //PROJECT_LUMINARY_RETURNABLEWINDOW_H
