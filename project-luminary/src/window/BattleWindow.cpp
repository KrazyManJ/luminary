#include "BattleWindow.h"
#include "battle/BattleWindowAttacks.h"
#include "../Luminary.h"
#include "InventoryWindow.h"

BattleWindow::BattleWindow(Window* prevWindow, Player* player, Enemy* enemy) : ReturnableWindow(prevWindow) {
    m_player = player;
    m_enemy = enemy;
    m_battleCycler = new Cycler(AMOUNT_OF_CHOISES-1);
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
    ConsoleHandler::setCursorPosition(15,10);
    std::cout << m_player->renderChar();
    ConsoleHandler::setCursorPosition(Window::WIDTH-13,10);
    std::cout << "%"; //    std::cout << m_enemy->renderChar();
    ConsoleHandler::setCursorPosition(26,22);
    std::string choises[AMOUNT_OF_CHOISES] = {"Attack", "Open inventory"};
    for(unsigned int i = 0; i < AMOUNT_OF_CHOISES; i++){
        if(m_battleCycler->getIndex() == i){
            std::cout << ConsoleHandler::getFormatChar(BLINKING)
            << ConsoleHandler::getFormatChar(INVERTED) << " " << choises[i] << " "
            << ConsoleHandler::getFormatChar(RESET) << "            ";
        }
        else{
            std::cout << choises[i] << "            ";
        }
    }
}

void BattleWindow::onInput(ConsoleHandler::KeyEvent *evt) {
    if(evt->getKey() == KEY_D || evt->getKey() == KEY_ARROW_RIGHT){
        m_battleCycler->goUp();
        return;
    } else if(evt->getKey() == KEY_A || evt->getKey() == KEY_ARROW_LEFT){
        m_battleCycler->goDown();
        return;
    }
    if(evt->getKey() == KEY_ENTER){
        int index = m_battleCycler->getIndex();
        if (index == 0) {
//            BattleWindowAttacks* battleWindowAttacks = new BattleWindowAttacks(this,m_player);
//            Luminary::getInstance()->openWindow(battleWindowAttacks, true);
        }
        else if(index == 1)
            Luminary::getInstance()->openWindow(new InventoryWindow(this,m_player->getInventory()),true);
    }
}
