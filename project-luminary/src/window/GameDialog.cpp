#include <iostream>
#include <unistd.h>
#include "GameDialog.h"

void GameDialog::render() {
    for (int i = 20; i < 25; i++){
        ConsoleHandler::setCursorPosition(2,i);
        std::cout
            << ConsoleHandler::getFormatChar(RESET)
            << std::string(Window::WIDTH-2,' ');
    }
    ConsoleHandler::setCursorPosition(4,22);
    if (m_faded) {
        std::cout << m_text;
        return;
    }
    for (char c : m_text){
        std::cout << c;
        usleep(5000);
    }
    m_faded = true;
}

void GameDialog::onInput(ConsoleHandler::KeyEvent *evt) {
    if (evt->getKey() == KEY_ENTER) close();
}

GameDialog::GameDialog(std::string text, Window *prevWindow) : ReturnableWindow(prevWindow) {
    m_faded = false;
    m_text = text;
}
