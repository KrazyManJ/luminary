#include <iostream>
#include <vector>
#include "MainMenuWindow.h"
#include "../Luminary.h"
#include "../Game.h"
#include "../GameCreator.h"

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
    for (int i = 0; i < title.size(); i++) {
        ConsoleHandler::setCursorPosition(40 - title.at(i).length() / 2, 4 + i);
        std::cout << title.at(i) << std::endl;
    }

    std::vector<std::string> labels = {"Create new game", "Resume Game", "Quit Game"};
    for (int i = 0; i < labels.size(); i++) {
        ConsoleHandler::setCursorPosition(10, i * 2 + title.size() + 9);
        std::cout << ConsoleHandler::getColorChar(
                (i == 1 && Luminary::getInstance()->getLastGame() == nullptr ? 0x888888 : 0xFFFF55)
                , FOREGROUND) << "> ";
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
            Luminary::getInstance()->startNewGame();
            delete this;
        }
        else if (m_menuCycler->getIndex() == 1) {
            if (Luminary::getInstance()->getLastGame() != nullptr) {
                Luminary::getInstance()->openWindow(Luminary::getInstance()->getLastGame());
                delete this;
            }
        }
        else if (m_menuCycler->getIndex() == 2) {
            Luminary::getInstance()->exit();
            delete this;
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