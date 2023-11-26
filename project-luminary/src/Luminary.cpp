#include "Luminary.h"
#include "ConsoleHandler.h"

Luminary* Luminary::s_instance = nullptr;

Luminary::Luminary(Window* startingWindow) {
    s_instance = this;
    m_run = true;
    m_activeWindow = startingWindow;
    ConsoleHandler::setConsoleTitle("Luminary");
    ConsoleHandler::disableCursorVisibility();
}

Luminary *Luminary::getInstance() {
    return s_instance;
}


void Luminary::startLoop() {
    while (m_run) {
        auto *input = ConsoleHandler::handleKeyboardInput();
        getActiveWindow()->onInput(input);

        getActiveWindow()->render();
        delete input;
    }
}

void Luminary::exit() {
    m_run = false;
}

Window *Luminary::getActiveWindow() {
    return m_activeWindow;
}

void Luminary::setActiveWindow(Window *window) {
    m_activeWindow = window;
}
