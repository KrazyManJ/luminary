#include "ReturnableWindow.h"
#include "../Luminary.h"

ReturnableWindow::ReturnableWindow(Window *prevWindow) {
    m_prevWindow = prevWindow;
}

void ReturnableWindow::close() {
    Luminary::getInstance()->openWindow(m_prevWindow);
    delete this;
}
