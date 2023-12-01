//
// Created by KrazyManJ on 01.12.2023.
//

#ifndef PROJECT_LUMINARY_RETURNABLEWINDOW_H
#define PROJECT_LUMINARY_RETURNABLEWINDOW_H


#include "Window.h"

class ReturnableWindow : public Window {
private:
    Window* m_prevWindow;
protected:
    ReturnableWindow(Window* prevWindow);
public:

    void close();
};


#endif //PROJECT_LUMINARY_RETURNABLEWINDOW_H
