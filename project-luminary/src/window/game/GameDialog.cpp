#include <iostream>
#include <unistd.h>
#include "GameDialog.h"


void GameDialog::renderClassic() {
    const short Y_DIALOG_POS = m_game->getPlayer()->getPosition().y < Window::HEIGHT/1.5 ? 19 : 2;
    for (int i = Y_DIALOG_POS; i < Y_DIALOG_POS+6; i++){
        ConsoleHandler::setCursorPosition(2,i);
        std::cout
            << ConsoleHandler::getFormatChar(RESET)
            << std::string(Window::WIDTH-2,' ');
    }
    ConsoleHandler::setCursorPosition(4,Y_DIALOG_POS+2);
    std::cout << ConsoleHandler::getFormatChar(ITALIC);
    if (m_faded) {
        std::cout << m_text;
    } else {
        for (char c : m_text){
            std::cout << c;
            usleep(4000);
        }
        m_faded = true;
    }
    std::cout << ConsoleHandler::getFormatChar(RESET);
    ConsoleHandler::setCursorPosition(70,Y_DIALOG_POS+4);
    std::cout
        << ConsoleHandler::getFormatChar(BLINKING)
        << ConsoleHandler::getFormatChar(INVERTED)
        << " Enter "
        << ConsoleHandler::getFormatChar(RESET);
}

void GameDialog::renderFullScreen() {

    ConsoleHandler::setCursorPosition(0,0);
    std::string output;
    for (int i = 0; i < Window::HEIGHT; i++)
        output += std::string(Window::WIDTH, ' ')+"\n";
    std::cout << output;

    std::cout << ConsoleHandler::getFormatChar(ITALIC);
    if (m_faded) {
        ConsoleHandler::setCursorPosition(Window::WIDTH/2-m_text.size()/2, Window::HEIGHT/2);
        std::cout << m_text;
    }
    else {
        output = "";
        for (char c : m_text){
            output += c;
            ConsoleHandler::setCursorPosition(Window::WIDTH/2-output.size()/2, Window::HEIGHT/2);
            std::cout << output;
            usleep(4000);
        }
        m_faded = true;
    }
}

void GameDialog::render() {
    if (m_fullScreen) renderFullScreen();
    else renderClassic();
}

void GameDialog::onInput(ConsoleHandler::KeyEvent *evt) {
    if (evt->getKey() == KEY_ENTER) close(true);
}

GameDialog::GameDialog(std::string text, Game *game, bool fullScreen) : GameReturnableWindow(game) {
    m_faded = false;
    m_text = text;
    m_fullScreen = fullScreen;
}