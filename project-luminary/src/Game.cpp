#include <iostream>
#include "Game.h"


void Game::render() {
    ConsoleHandler::setCursorPosition(1, 1);
    std::cout << ConsoleHandler::getFormatChar(ConsoleHandler::RESET);
    std::cout << m_mapMatrix.at(m_currentMapPos.y).at(m_currentMapPos.x)->render() << std::endl;
    std::cout << "Player pos - x: "
        << m_player->getPosition().x << "   y: "
        << m_player->getPosition().y << "      ";
    ConsoleHandler::setCursorPosition(m_player->getPosition());
    std::cout << m_player->renderChar();
}

void Game::onInput(ConsoleHandler::KeyEvent *evt) {
    if (!evt->isArrowEscaped()) return;
    // PLAYER MOVEMENT
    Position pPos = m_player->getPosition();
    if (evt->getKey() == KEY_ARROW_RIGHT && pPos.x < WIDTH) m_player->makeMovement(RIGHT);
    else if (evt->getKey() == KEY_ARROW_LEFT && pPos.x > 1) m_player->makeMovement(LEFT);
    else if (evt->getKey() == KEY_ARROW_UP && pPos.y > 1) m_player->makeMovement(UP);
    else if (evt->getKey() == KEY_ARROW_DOWN && pPos.y < HEIGHT) m_player->makeMovement(DOWN);


    // MAP SWITCH TEST
//    if (
//            evt->getKey() == KEY_ARROW_UP
//            && m_currentMapPos.y > 0
//            && m_mapMatrix.at(m_currentMapPos.y - 1).size() > m_currentMapPos.x
//            && m_mapMatrix.at(m_currentMapPos.y - 1).at(m_currentMapPos.x) != nullptr
//            )
//        m_currentMapPos.y -= 1;
//    else if (
//            evt->getKey() == KEY_ARROW_DOWN
//            && m_currentMapPos.y < m_mapMatrix.size() - 1
//            && m_mapMatrix.at(m_currentMapPos.y + 1).size() > m_currentMapPos.x
//            && m_mapMatrix.at(m_currentMapPos.y + 1).at(m_currentMapPos.x) != nullptr
//            )
//        m_currentMapPos.y += 1;
//    else if (
//            evt->getKey() == KEY_ARROW_LEFT
//            && m_currentMapPos.x > 0
//            && m_mapMatrix.at(m_currentMapPos.y).at(m_currentMapPos.x - 1) != nullptr
//            )
//        m_currentMapPos.x -= 1;
//    else if (
//            evt->getKey() == KEY_ARROW_RIGHT
//            && m_currentMapPos.x < m_mapMatrix.at(m_currentMapPos.y).size()-1
//            && m_mapMatrix.at(m_currentMapPos.y).at(m_currentMapPos.x + 1) != nullptr
//            )
//        m_currentMapPos.x += 1;
}

Game *Game::debugGame() {
    Game *game = new Game();
    game->m_player = new Player(
            {.x=10,.y=10},
            new CharData('*',0xFFFF00,COLOR_NONE)
    );
    game->m_mapMatrix = {
            {
                    new Map(
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            "                                                                                \n"
                            ),
                    new Map("-x\n--\n--"),
            },
            {
                    new Map("--\nx-\n--"),
                    new Map("--\n-x\n--"),
            },
            {
                    new Map("--\n--\nx-"),
                    new Map("--\n--\n-x"),
            }
    };
    game->m_currentMapPos = {.x = 0, .y=0};
    return game;
}

Game::~Game() {
    for (auto row : m_mapMatrix){
        for (auto col : row){
            delete col;
        }
        row.clear();
    }
    m_mapMatrix.clear();
}
