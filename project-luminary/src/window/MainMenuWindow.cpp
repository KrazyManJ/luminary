#include <iostream>
#include "MainMenuWindow.h"

MainMenuWindow::MainMenuWindow() {
    keypressed = 0;
}

void MainMenuWindow::render() {
    ConsoleHandler::setCursorPosition(0,0);
    std::cout << keypressed << std::string(10,' ') << std::endl;
}

void MainMenuWindow::onInput(ConsoleHandler::KeyEvent *evt) {
    keypressed = evt->getKey();
}
