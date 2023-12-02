#include <iostream>
#include "Game.h"
#include "Luminary.h"
#include "map/Enemy.h"
#include "console/CharBuilder.h"
#include "map/ItemEntity.h"
#include "window/InventoryWindow.h"


void Game::render() {
    ConsoleHandler::setCursorPosition(1, 1);
    std::cout << ConsoleHandler::getFormatChar(RESET);
    std::cout << m_mapMatrix.at(m_currentMapPos.y).at(m_currentMapPos.x)->render() << std::endl;
    ConsoleHandler::setCursorPosition(m_player->getPosition().x + 1, m_player->getPosition().y + 1);
    std::cout << m_player->renderChar();

    //DEBUG TOOLS

//    ConsoleHandler::setCursorPosition(2, Window::HEIGHT + 2);
//    std::cout << "Player pos - x: " << m_player->getPosition().x << "   y: " << m_player->getPosition().y << "      ";
//    for (unsigned int i = 0; i < m_mapMatrix.size(); i++) {
//        ConsoleHandler::setCursorPosition(Window::WIDTH + 2, i + 1);
//        for (unsigned int j = 0; j < m_mapMatrix.at(i).size(); j++) {
//            if (m_mapMatrix.at(i).at(j) == nullptr) std::cout << " ";
//            else if (i == m_currentMapPos.y && j == m_currentMapPos.x) std::cout << "x";
//            else std::cout << "-";
//        }
//    }
}

Map *Game::getCurrentMap() {
    return m_mapMatrix.at(m_currentMapPos.y).at(m_currentMapPos.x);
}

Position Game::posInDirection(Position position, MovementDirection direction) {
    if (direction == LEFT || direction == RIGHT)
        position.x += (direction == LEFT) ? -1 : 1;
    else if (direction == UP || direction == DOWN)
        position.y += (direction == UP) ? -1 : 1;
    return position;
}

MapObject *Game::getMapObjectInDirectionOfPlayer(MovementDirection direction) {
    return getCurrentMap()->getObjectAt(posInDirection(m_player->getPosition(), direction));
}

bool Game::isPlayerMoveInMap(MovementDirection direction) {
    switch (direction) {
        case RIGHT:
            return m_player->getPosition().x < Window::WIDTH - 1;
        case LEFT:
            return m_player->getPosition().x > 0;
        case UP:
            return m_player->getPosition().y > 0;
        case DOWN:
            return m_player->getPosition().y < Window::HEIGHT - 1;
    }
    return false;
}

bool Game::canAccessMapInDirection(MovementDirection direction) {
    switch (direction) {
        case RIGHT:
            return m_currentMapPos.x < m_mapMatrix.at(m_currentMapPos.y).size() - 1 &&
                   m_mapMatrix.at(m_currentMapPos.y).at(m_currentMapPos.x + 1) != nullptr;
        case LEFT:
            return m_currentMapPos.x > 0 && m_mapMatrix.at(m_currentMapPos.y).at(m_currentMapPos.x - 1) != nullptr;
        case UP:
            return m_currentMapPos.y > 0 && m_mapMatrix.at(m_currentMapPos.y - 1).size() > m_currentMapPos.x &&
                   m_mapMatrix.at(m_currentMapPos.y - 1).at(m_currentMapPos.x) != nullptr;
        case DOWN:
            return m_currentMapPos.y < m_mapMatrix.size() - 1 &&
                   m_mapMatrix.at(m_currentMapPos.y + 1).size() > m_currentMapPos.x &&
                   m_mapMatrix.at(m_currentMapPos.y + 1).at(m_currentMapPos.x) != nullptr;
    }
    return false;
}

void Game::switchMap(MovementDirection direction) {
    Position pos = m_player->getPosition();
    if (direction == RIGHT || direction == LEFT)
        pos.x = (direction == RIGHT) ? 0 : Window::WIDTH - 1;
    else if (direction == UP || direction == DOWN)
        pos.y = (direction == DOWN) ? 0 : Window::HEIGHT - 1;
    m_currentMapPos = posInDirection(m_currentMapPos, direction);
    m_player->setPosition(pos);
}

void Game::makePlayerMovement(MovementDirection direction) {
    if (Game::isPlayerMoveInMap(direction)) {
        MapObject* obj = getMapObjectInDirectionOfPlayer(direction);
        if (obj != nullptr && obj->isObstacle()) return;
        m_player->makeMovement(direction);
        return;
    }
    if (!canAccessMapInDirection(direction)) return;
    switchMap(direction);
}

void Game::onInput(ConsoleHandler::KeyEvent *evt) {
    if (evt->getKey() == KEY_ESC) {
        Luminary::getInstance()->exit();
        return;
    }
    if (evt->getKey() == KEY_L){
        getCurrentMap()->setLightState(!getCurrentMap()->getLightState());
        return;
    }
    if (evt->getKey() == KEY_E){
        Luminary::getInstance()->openWindow(new InventoryWindow(this, m_player->getInventory()),true);
        return;
    }
    std::map<unsigned int, MovementDirection> directions = {
            {KEY_W,    UP},
            {KEY_A,  LEFT},
            {KEY_S,  DOWN},
            {KEY_D, RIGHT}
    };
    if (directions.count(evt->getKey()) > 0){
        makePlayerMovement(directions.at(evt->getKey()));
        return;
    }
    if (!evt->isArrowEscaped()) return;
    directions = {
            {KEY_ARROW_LEFT,  LEFT},
            {KEY_ARROW_RIGHT, RIGHT},
            {KEY_ARROW_UP,    UP},
            {KEY_ARROW_DOWN,  DOWN}
    };
    if (directions.count(evt->getKey()) == 0) return;
    makePlayerMovement(directions.at(evt->getKey()));
}

Game::~Game() {
    for (auto row: m_mapMatrix) {
        for (auto col: row) delete col;
        row.clear();
    }
    m_mapMatrix.clear();
    delete m_player;
}
