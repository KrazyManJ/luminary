#include "BattleWindow.h"

BattleWindow::BattleWindow(Window* prevWindow, Player* player, Enemy* enemy) : ReturnableWindow(prevWindow) {
    m_player = player;
    m_enemy = enemy;
}

void BattleWindow::render() {
    ConsoleHandler::setCursorPosition(1,1);
    std::string fullRender;
    for(unsigned int renderPositionY = 1; renderPositionY <= Window::HEIGHT; renderPositionY++){
        fullRender.append(std::string(Window::WIDTH, (renderPositionY == 2 || renderPositionY == 20) ? '-' : ' ')).append("\n");
    }
    std::cout << fullRender << std::endl;
    std::string label = "Battle";
    unsigned int lenghtOfLabel = label.length();
    ConsoleHandler::setCursorPosition((Window::WIDTH/2)-(lenghtOfLabel/2),1);
    std::cout << label;
    ConsoleHandler::setCursorPosition(20,10);
    std::cout << m_player->renderChar();
//    ConsoleHandler::setCursorPosition(20,Window::WIDTH - 10);
//    std::cout << m_enemy->renderChar();
//    std::string attackName;
//    for(unsigned int attackIndex = 0; attackIndex < 4; attackIndex++){
//        attackName = m_player->getAttacks()[attackIndex]->getName();
//        ConsoleHandler::setCursorPosition(attackIndex*5+20+(attackName.length()), 22);
//        std::cout << attackName;
//    }
}

void BattleWindow::onInput(ConsoleHandler::KeyEvent *evt) {

}
