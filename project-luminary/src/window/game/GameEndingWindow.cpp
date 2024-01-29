#include "GameEndingWindow.h"
#include "GameDialog.h"
#include "../../Luminary.h"
#include "../MainMenuWindow.h"

GameEndingWindow::GameEndingWindow(Game* game) : ReturnableWindow(new MainMenuWindow()) {
    m_game = game;
    m_step = 0;
    m_currentWindow = new GameDialog("I did it! I lit up the world!", m_game);
}

void GameEndingWindow::render() {
    m_game->render();
    m_currentWindow->render();
}

void GameEndingWindow::onInput(ConsoleHandler::KeyEvent *evt) {
    if (evt->getKey() != KEY_ENTER) return;
    m_step++;
    switch (m_step) {
        case 0:
            break;
        case 1:
            delete m_currentWindow;
            m_currentWindow = new GameDialog("One travel back to home later...", m_game, true);
            break;
        case 2:
            m_game->teleportPlayer(m_game->getEndingPosition());
            delete m_currentWindow;
            m_currentWindow = new GameDialog("Now my home is not in dark anymore!", m_game);
            break;
        default:
            close();
            delete m_currentWindow;
            Luminary::getInstance()->removeLastGame();
            break;
    }
}
