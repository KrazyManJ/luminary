#include "GameReturnableWindow.h"

GameReturnableWindow::GameReturnableWindow(Game *game): ReturnableWindow(game) {
    m_game = game;
}
