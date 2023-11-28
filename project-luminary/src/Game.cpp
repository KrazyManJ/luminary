#include <iostream>
#include "Game.h"


void Game::render() {
    ConsoleHandler::setCursorPosition(0, 0);
    std::cout << m_mapMatrix[m_currentMap.y][m_currentMap.x]->render()

    << std::endl;
}

void Game::onInput(ConsoleHandler::KeyEvent *evt) {
    if (!evt->isArrowEscaped()) return;
    // MAP SWITCH TEST
    if (
            evt->getKey() == KEY_ARROW_UP
            && m_currentMap.y > 0
            && m_mapMatrix.at(m_currentMap.y - 1).size() > m_currentMap.x
            && m_mapMatrix.at(m_currentMap.y - 1).at(m_currentMap.x) != nullptr
            )
        m_currentMap.y -= 1;
    else if (
            evt->getKey() == KEY_ARROW_DOWN
            && m_currentMap.y < m_mapMatrix.size() - 1
            && m_mapMatrix.at(m_currentMap.y + 1).size() > m_currentMap.x
            && m_mapMatrix.at(m_currentMap.y + 1).at(m_currentMap.x) != nullptr
            )
        m_currentMap.y += 1;
    else if (
            evt->getKey() == KEY_ARROW_LEFT
            && m_currentMap.x > 0
            && m_mapMatrix.at(m_currentMap.y).at(m_currentMap.x - 1) != nullptr
            )
        m_currentMap.x -= 1;
    else if (
            evt->getKey() == KEY_ARROW_RIGHT
            && m_currentMap.x < m_mapMatrix.at(m_currentMap.y).size()-1
            && m_mapMatrix.at(m_currentMap.y).at(m_currentMap.x + 1) != nullptr
            )
        m_currentMap.x += 1;
}

Game *Game::debugGame() {
    Game *game = new Game();
    game->m_mapMatrix = {
            {
                    nullptr,
                    new Map(" x-\n---\n--"),
                    new Map(" -x\n---\n--"),
            },
            {
                    new Map(" --\nx--\n--"),
                    new Map(" --\n-x-\n--"),
                    new Map(" --\n--x\n--"),
            },
            {
                    new Map(" --\n---\nx-"),
                    new Map(" --\n---\n-x"),
            }
    };
    game->m_currentMap = {.x = 1, .y=0};
    return game;
}

Game::~Game() {

}

//Game::~Game() {
//    for (int row = 0; row < ROWS; row++){
//        for (int col = 0; col < COLS; col++){
//            if (m_mapMatrix[row][col] != nullptr) delete m_mapMatrix[row][col];
//        }
//        delete m_mapMatrix[row];
//    }
//    delete m_mapMatrix;
//}
