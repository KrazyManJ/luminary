#include <iostream>
#include <vector>
#include "MainMenuWindow.h"
#include "../Luminary.h"
#include "../Game.h"
#include "../GameCreator.h"

MainMenuWindow::MainMenuWindow() {
    m_menuCycler = new Cycler(1);
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
    for (int i = 0; i < title.size(); i++) {
        ConsoleHandler::setCursorPosition(40 - title.at(i).length() / 2, 4 + i);
        std::cout << title.at(i) << std::endl;
    }

    std::vector<std::string> labels = {"Create new game", "Quit Game"};
    for (int i = 0; i < labels.size(); i++) {
        ConsoleHandler::setCursorPosition(10, i * 2 + title.size() + 9);
        std::cout << ConsoleHandler::getColorChar(0xFFFF55, FOREGROUND) << "> ";
        if (m_menuCycler->getIndex() == i) {
            std::cout
                    << ConsoleHandler::getFormatChar(BLINKING)
                    << ConsoleHandler::getFormatChar(INVERTED);
        }
        std::cout << labels.at(i)
                  << ConsoleHandler::getFormatChar(RESET)
                  << std::string(10, ' ');
    }
}

void MainMenuWindow::onInput(ConsoleHandler::KeyEvent *evt) {
    if (evt->getKey() == KEY_ENTER) {
        if (m_menuCycler->getIndex() == 0) {
            Luminary::getInstance()->openWindow(GameCreator::createNewGame());
            delete this;
        } else if (m_menuCycler->getIndex() == 1) {
            Luminary::getInstance()->exit();
        }
    }
    if (evt->getKey() == KEY_W) {
        m_menuCycler->goDown();
        return;
    }
    if (evt->getKey() == KEY_S) {
        m_menuCycler->goUp();
        return;
    }
    if (!evt->isArrowEscaped()) return;
    if (evt->getKey() == KEY_ARROW_UP) m_menuCycler->goDown();
    else if (evt->getKey() == KEY_ARROW_DOWN) m_menuCycler->goUp();
}

Window::~Window() = default;