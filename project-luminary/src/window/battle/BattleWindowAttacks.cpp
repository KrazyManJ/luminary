#include "BattleWindowAttacks.h"

BattleWindowAttacks::BattleWindowAttacks(Window *prevWindow, Player *player): ReturnableWindow(prevWindow) {
    m_player = player;
}

void BattleWindowAttacks::render() {
    ConsoleHandler::setCursorPosition(26,22);
    std::cout << "Ahoj";
}

void BattleWindowAttacks::onInput(ConsoleHandler::KeyEvent *evt) {

}
