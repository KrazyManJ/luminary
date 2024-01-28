#include <iostream>
#include "GameItemPickupDialogWindow.h"

GameItemPickupDialogWindow::GameItemPickupDialogWindow(Game *game, Item *item) : ReturnableWindow(game) {
    m_game = game;
    m_item = item;
}

void GameItemPickupDialogWindow::render() {
    m_game->render();
    std::string label = "> " + m_item->getName() + " collected";
    ConsoleHandler::setCursorPosition(Window::WIDTH-label.size()-2, 22);
    std::cout
        << ConsoleHandler::getColorChar(0x0, BACKGROUND)
        << ConsoleHandler::getColorChar(0xFFFF55, FOREGROUND)
        << ConsoleHandler::getFormatChar(BLINKING)
        << label
        << ConsoleHandler::getFormatChar(RESET);
}

void GameItemPickupDialogWindow::onInput(ConsoleHandler::KeyEvent *evt) {
    Game* game = m_game;
    close();
    game->onInput(evt);
    game->render();
}
