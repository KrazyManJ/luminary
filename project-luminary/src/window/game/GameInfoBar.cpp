#include <iostream>
#include "GameInfoBar.h"

GameInfoBar::GameInfoBar(Game *game) : GameReturnableWindow(game) {}

void GameInfoBar::render() {
    const unsigned short BAR_HEIGHT = 3;
    ConsoleHandler::setCursorPosition(0,Window::HEIGHT-BAR_HEIGHT+1);
    std::string output;
    for (int i = 0; i < BAR_HEIGHT; i++)
        output.append(std::string(Window::WIDTH,' ')+"\n");
    std::cout << ConsoleHandler::getColorChar(0x1a2b47, BACKGROUND) << output;
    int gameWidth = m_game->getWidth(), gameHeight = m_game->getMapMatrix().size();
    //MINIMAP BORDER
    for (int i = Window::HEIGHT - gameHeight-1; i < Window::HEIGHT+1; i++){
        ConsoleHandler::setCursorPosition(Window::WIDTH-gameWidth-1, i);
        std::cout << std::string(gameWidth+2, ' ');
    }
    //MINIMAP
    std::cout << ConsoleHandler::getFormatChar(RESET);
    for (int row = 0; row < gameHeight; row++){
        for (int col = 0; col < gameWidth; col++){
            ConsoleHandler::setCursorPosition(Window::WIDTH-gameWidth+col,Window::HEIGHT-gameHeight+row);
            if (m_game->getMapMatrix().at(row).at(col) == m_game->getCurrentMap())
            std::cout << "X";
            else std::cout << "-";
        }
    }
    //
    ConsoleHandler::setCursorPosition(5,Window::HEIGHT-BAR_HEIGHT/2);
    std::cout
    << ConsoleHandler::getColorChar(0x1a2b47, BACKGROUND)
    << "Health ";

    const int HEALTH_BAR_WIDTH = 30;

    ConsoleHandler::setCursorPosition(12,Window::HEIGHT-BAR_HEIGHT/2);
    std::cout
    << ConsoleHandler::getColorChar(0x555555, BACKGROUND)
    << std::string(HEALTH_BAR_WIDTH , ' ');
    ConsoleHandler::setCursorPosition(12,Window::HEIGHT-BAR_HEIGHT/2);
    std::cout
        << ConsoleHandler::getColorChar(0xFF0000, BACKGROUND)
        << std::string(m_game->getPlayer()->getHealth()/100*HEALTH_BAR_WIDTH , ' ');
    ConsoleHandler::setCursorPosition(Window::WIDTH/2+5,Window::HEIGHT-BAR_HEIGHT/2);
    std::cout
        << ConsoleHandler::getColorChar(0x1a2b47, BACKGROUND)
        << "Strength:" << m_game->getPlayer()->getDamageAvg();

}

void GameInfoBar::onInput(ConsoleHandler::KeyEvent *evt) {
    close();
    if (evt->isArrowEscaped()
        || evt->getKey() == KEY_W
        || evt->getKey() == KEY_A
        || evt->getKey() == KEY_S
        || evt->getKey() == KEY_D
    ) m_game->onInput(evt);
}
