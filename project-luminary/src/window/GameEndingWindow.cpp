#include "GameEndingWindow.h"
#include "GameDialog.h"
#include "../Luminary.h"
#include "MainMenuWindow.h"

GameEndingWindow::GameEndingWindow(Game* game) : ReturnableWindow(new MainMenuWindow()) {
    m_game = game;
    m_step = 0;
}

void GameEndingWindow::render() {
    m_game->render();
    switch (m_step) {
        case 0:
            (new GameDialog("I did it! I lit up the world!", nullptr))->render();
            break;
        case 1:
            m_game->teleportPlayer(m_game->getEndingPosition());
            m_game->render();
            (new GameDialog("Now my home is not in dark anymore!", nullptr))->render();
            break;
        default:
            close();
            Luminary::getInstance()->removeLastGame();
            Luminary::getInstance()->getActiveWindow()->render();
            break;
    }
}

void GameEndingWindow::onInput(ConsoleHandler::KeyEvent *evt) {
    if (evt->getKey() == KEY_ENTER) m_step++;
}
