#include <iostream>
#include "Luminary.h"
#include "console/ConsoleHandler.h"
#include "GameCreator.h"

Luminary *Luminary::s_instance = nullptr;

Luminary::Luminary(Window *startingWindow) {
    s_instance = this;
    m_run = true;
    m_activeWindow = startingWindow;
    m_lastGame = nullptr;
    ConsoleHandler::setConsoleTitle("Luminary");
    ConsoleHandler::disableCursorVisibility();
    startingWindow->render();
}

Luminary *Luminary::getInstance() {
    return s_instance;
}


void Luminary::startLoop() {

//    // DEBUG - DRAW WINDOW BORDER
//    ConsoleHandler::setCursorPosition(0, 25 + 1);
//    std::cout
//            << ConsoleHandler::getColorChar(0x111111, BACKGROUND)
//            << std::string(80 + 1, ' ');
//    for (int i = 0; i < 25 + 1; i++) {
//        ConsoleHandler::setCursorPosition(80 + 1, i);
//        std::cout
//                << ConsoleHandler::getColorChar(0x111111, BACKGROUND)
//                << " " << ConsoleHandler::getFormatChar(RESET);
//    }

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

void Luminary::openWindow(Window *window, bool keepPrevious) {
    if (!keepPrevious) clearWindowContent();
    else ConsoleHandler::setCursorPosition(0, 0);
    m_activeWindow = window;
}

void Luminary::clearWindowContent() {
    ConsoleHandler::setCursorPosition(0, 0);
    for (int i = 0; i < Window::HEIGHT; i++) std::cout << std::string(Window::WIDTH, ' ') << std::endl;
    ConsoleHandler::setCursorPosition(0, 0);
}

void Luminary::startNewGame() {
    m_lastGame = GameCreator::createNewGame();
    openWindow(m_lastGame);
}

void Luminary::resetGame() {
    delete m_lastGame;
    startNewGame();
}

Game *Luminary::getLastGame() {
    return m_lastGame;
}