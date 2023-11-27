#include <iostream>
#include "Game.h"

void Game::render() {
    ConsoleHandler::setCursorPosition(0,0);
    std::cout << "Lol" << std::endl;
}

void Game::onInput(ConsoleHandler::KeyEvent *evt) {

}

Game::~Game() = default;
