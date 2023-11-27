#include <iostream>
#include <vector>
#include "MainMenuWindow.h"
#include "../Luminary.h"
#include "../Game.h"

MainMenuWindow::MainMenuWindow() {
    m_menuCycler = new Cycler(2);
}

void MainMenuWindow::render() {
    std::vector<std::string> title = {
            " _                    _                           ",
            "| |   _   _ _ __ ___ (_)_ __   __ _ _ __ _   _    ",
            "| |  | | | | '_ ` _ \\| | '_ \\ / _` | '__| | | |   ",
            "| |__| |_| | | | | | | | | | | (_| | |  | |_| |   ",
            "|_____\\__,_|_| |_| |_|_|_| |_|\\__,_|_|   \\__, |   ",
            "                                         |___/    "
    };
    for (int i = 0; i < title.size(); i++){
        ConsoleHandler::setCursorPosition(40-title.at(i).length()/2,4+i);
        std::cout << title.at(i) << std::endl;
    }

    std::vector<std::string> labels = {"Create new game", "Load game", "Quit Game"};
    for (int i = 0; i < labels.size(); i++){
        ConsoleHandler::setCursorPosition(10,i*2+title.size()+9);
        std::cout << ConsoleHandler::getColorChar(0xFFFF55, ConsoleHandler::FOREGROUND) << "> ";
        if (m_menuCycler->getIndex() == i){
            std::cout
                << ConsoleHandler::getFormatChar(ConsoleHandler::BLINKING)
                << ConsoleHandler::getFormatChar(ConsoleHandler::INVERTED);
        }
        std::cout << labels.at(i)
            << ConsoleHandler::getFormatChar(ConsoleHandler::RESET)
            << std::string(10,' ');
    }
}

void MainMenuWindow::onInput(ConsoleHandler::KeyEvent *evt) {
    if (evt->getKey() == KEY_ENTER){
        if (m_menuCycler->getIndex() == 0){
            Luminary::getInstance()->openWindow(new Game());
            delete this;
        }
        else if (m_menuCycler->getIndex() == 1){

        }
        else if (m_menuCycler->getIndex() == 2){
            Luminary::getInstance()->exit();
        }
    }
    if (!evt->isArrowEscaped()) return;
    if (evt->getKey() == KEY_ARROW_UP) m_menuCycler->goDown();
    else if (evt->getKey() == KEY_ARROW_DOWN) m_menuCycler->goUp();
}

Window::~Window() = default;