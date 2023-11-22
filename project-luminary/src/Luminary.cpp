#include "Luminary.h"
#include "ConsoleHandler.h"

bool Luminary::s_run = true;

void Luminary::initialize() {
    ConsoleHandler::setConsoleTitle("Luminary");
    ConsoleHandler::disableCursorVisibility();
}

void Luminary::startLoop() {
    while (s_run) {
        auto *input = ConsoleHandler::handleKeyboardInput();
        // Processing
        if (input->getKey() == K_ESC) Luminary::exit();
    }
}

void Luminary::exit() {
    s_run = false;
}
