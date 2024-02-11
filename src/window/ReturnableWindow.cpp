#include "ReturnableWindow.h"
#include "../Luminary.h"

ReturnableWindow::ReturnableWindow(Window *prevWindow) {
    m_prevWindow = prevWindow;
}

void ReturnableWindow::close(bool keepPrevious) {
    Luminary::getInstance()->openWindow(m_prevWindow, keepPrevious);
    delete this;
}
