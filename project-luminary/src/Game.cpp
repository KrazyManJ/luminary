#include <iostream>
#include "Game.h"
#include "Luminary.h"


void Game::render() {
    ConsoleHandler::setCursorPosition(1, 1);
    std::cout << ConsoleHandler::getFormatChar(ConsoleHandler::RESET);
    std::cout << m_mapMatrix.at(m_currentMapPos.y).at(m_currentMapPos.x)->render() << std::endl;
    ConsoleHandler::setCursorPosition(m_player->getPosition());
    std::cout << m_player->renderChar();

    //DEBUG TOOLS
    ConsoleHandler::setCursorPosition(2, Window::HEIGHT + 2);
    std::cout << "Player pos - x: "
              << m_player->getPosition().x << "   y: "
              << m_player->getPosition().y << "      ";
    for (unsigned int i = 0; i < m_mapMatrix.size(); i++) {
        ConsoleHandler::setCursorPosition(Window::WIDTH + 2, i + 1);
        for (unsigned int j = 0; j < m_mapMatrix.at(i).size(); j++) {
            if (m_mapMatrix.at(i).at(j) == nullptr) std::cout << " ";
            else if (i == m_currentMapPos.y && j == m_currentMapPos.x) std::cout << "x";
            else std::cout << "-";
        }
    }
}

void Game::onInput(ConsoleHandler::KeyEvent *evt) {
    if (evt->getKey() == KEY_ESC) {
        Luminary::getInstance()->exit();
        return;
    }
    if (!evt->isArrowEscaped()) return;
    Position pPos = m_player->getPosition();
    Map* currentMap = m_mapMatrix.at(m_currentMapPos.y).at(m_currentMapPos.x);
    if (evt->getKey() == KEY_ARROW_RIGHT) {
        if (pPos.x < WIDTH) {
            MapObject* nextObject = currentMap->getObjectAt({.x=pPos.x,.y=static_cast<unsigned short>(pPos.y-1)});
            if (nextObject != nullptr && nextObject->isObstacle()) return;
            m_player->makeMovement(RIGHT);
            return;
        }
        if (m_currentMapPos.x >= m_mapMatrix.at(m_currentMapPos.y).size() - 1) return;
        if (m_mapMatrix.at(m_currentMapPos.y).at(m_currentMapPos.x + 1) == nullptr) return;
        m_player->setPosition({.x=1, .y=pPos.y});
        m_currentMapPos.x += 1;
    } else if (evt->getKey() == KEY_ARROW_LEFT) {
        if (pPos.x > 1) {
            MapObject* nextObject = currentMap->getObjectAt({
                .x=static_cast<unsigned short>(pPos.x-2),
                .y=static_cast<unsigned short>(pPos.y-1)
            });
            if (nextObject != nullptr && nextObject->isObstacle()) return;
            m_player->makeMovement(LEFT);
            return;
        }
        if (m_currentMapPos.x <= 0) return;
        if (m_mapMatrix.at(m_currentMapPos.y).at(m_currentMapPos.x - 1) == nullptr) return;
        m_player->setPosition({.x=Window::WIDTH, .y=pPos.y});
        m_currentMapPos.x -= 1;
    } else if (evt->getKey() == KEY_ARROW_UP) {
        if (pPos.y > 1) {
            MapObject* nextObject = currentMap->getObjectAt({
                .x=static_cast<unsigned short>(pPos.x-1),
                .y=static_cast<unsigned short>(pPos.y-2)
            });
            if (nextObject != nullptr && nextObject->isObstacle()) return;
            m_player->makeMovement(UP);
            return;
        }
        if (m_currentMapPos.y <= 0) return;
        if (m_mapMatrix.at(m_currentMapPos.y - 1).size() <= m_currentMapPos.x) return;
        if (m_mapMatrix.at(m_currentMapPos.y - 1).at(m_currentMapPos.x) == nullptr) return;
        m_player->setPosition({.x=pPos.x, .y=Window::HEIGHT});
        m_currentMapPos.y -= 1;
    } else if (evt->getKey() == KEY_ARROW_DOWN) {
        if (pPos.y < HEIGHT) {
            MapObject* nextObject = currentMap->getObjectAt({
                .x=static_cast<unsigned short>(pPos.x-1),
                .y=pPos.y
            });
            if (nextObject != nullptr && nextObject->isObstacle()) return;
            m_player->makeMovement(DOWN);
            return;
        }
        if (m_currentMapPos.y >= m_mapMatrix.size() - 1) return;
        if (m_mapMatrix.at(m_currentMapPos.y + 1).size() <= m_currentMapPos.x) return;
        if (m_mapMatrix.at(m_currentMapPos.y + 1).at(m_currentMapPos.x) == nullptr) return;
        m_player->setPosition({.x=pPos.x, .y=1});
        m_currentMapPos.y += 1;
    }
}

Game *Game::debugGame() {
    Game *game = new Game();
    game->m_player = new Player({.x=10, .y=2});
    const std::string emptyMatrix =
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "WWGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGWWWWWWWWWWGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "WWWWWWWWWWWWGGGGGGGGGGGGGGGGGGGGGGGGGGGGWWWWWWWWWWWWWWWWWGGGGGGGGGGGGGGGGGGGGGGG\n"
            "WWWWWWWWWWWWWWWWWWWWWWWGGGGGGGGGGGGGGWWWWWWWWWWWWWWWWWWWWWWWWGGGGGGGGGGGGGGGGGGG\n"
            "GGWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGWWWWWWWWWWWWWWWWWWWWGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGWWWWWWWWWWWWWGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n";
    std::map<char, std::function<MapObject *()>> map = {
            {
                    'G', []() {
                return new MapObject(
                        new CharData(' ', COLOR_NONE, 0x1a472e),
                        new CharData(' ', COLOR_NONE, 0x1a472e),
                        false
                );
            }
            },
            {
                    'W', []() {
                return new MapObject(
                        new CharData(' ', COLOR_NONE, 0x253352),
                        new CharData(' ', COLOR_NONE, 0x253352),
                        true
                );
            }
            }
    };
    game->m_mapMatrix = {
            {
                    new Map(emptyMatrix, map, {}),
                    new Map(emptyMatrix, map, {}),
            },
            {
                    new Map(emptyMatrix, map, {}),
                    new Map(emptyMatrix, map, {}),
            },
            {
                    new Map(emptyMatrix, map, {}),
                    new Map(emptyMatrix, map, {}),
            }
    };
    game->m_currentMapPos = {.x = 0, .y=0};
    return game;
}

Game::~Game() {
    for (auto row: m_mapMatrix) {
        for (auto col: row) delete col;
        row.clear();
    }
    m_mapMatrix.clear();
}
