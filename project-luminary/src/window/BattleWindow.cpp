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
    float playerHealth = m_player->getHealth();
    float enemyHealth = m_enemy->getHealth();
    if(playerHealth <= 0 or enemyHealth <= 0)
    {
        close();
        std::string finishDialog = "";
        if(playerHealth > 0)
        {
            m_enemy->makeUninteractable();
            if(m_enemy->hasWeapon()){
                m_player->getInventory()->addWeapon(m_enemy->getWeapon());
                finishDialog = "Wow you gained a weapon!!! ";
            }else if(m_enemy->hasAttack()){
                m_player->addAttack(m_enemy->getAttack());
                finishDialog = "Wow you gained an attack!!! ";
            }
            finishDialog += "You won!!! Press any key to continue...";
        }else{
            finishDialog = "Game is over!!! Press any key to start again...";
            Luminary::getInstance()->resetGame();
        }
        ConsoleHandler::setCursorPosition(Window::WIDTH/2-finishDialog.size()/2,10);
        std::cout << finishDialog;
    }
    else{
        std::string fullRender;
//        std::string fightBackground = ConsoleHandler::getColorChar(0x38A8AB, BACKGROUND) + ' ' + ConsoleHandler::getFormatChar(RESET);
        for(unsigned int renderPositionY = 1; renderPositionY <= Window::HEIGHT; renderPositionY++){
            fullRender.append(std::string(Window::WIDTH-1, (renderPositionY == 4 || renderPositionY == 18) ? '-' : ' ')).append("\n");
//            if(renderPositionY == 2 || renderPositionY == 20) fullRender.append(std::string(Window::WIDTH, '-')).append("\n");
//            else if(renderPositionY > 2 && renderPositionY < 20){
//                for(unsigned renderPositionX = 1; renderPositionX <= Window::WIDTH; renderPositionX++){
//                    fullRender.append(fightBackground,0);
//                }
//                fullRender.append("\n");
//            }
//            else{
//                fullRender.append(std::string(Window::WIDTH,' ')).append("\n");
//            }
        }
        ConsoleHandler::setCursorPosition(1,1);
        std::cout << fullRender << std::endl;
        std::string label = "| Battle |";
        unsigned int lenghtOfLabel = label.length();
        ConsoleHandler::setCursorPosition((Window::WIDTH/2)-(lenghtOfLabel/2),3);
        std::cout << label;
        ConsoleHandler::setCursorPosition(18,6);
        std::cout << playerHealth << " HP";
        ConsoleHandler::setCursorPosition(20,8);
        std::cout << m_player->renderChar();
        ConsoleHandler::setCursorPosition((Window::WIDTH/2)+(lenghtOfLabel/2)+11,6);
        std::cout << enemyHealth << " HP";
        ConsoleHandler::setCursorPosition((Window::WIDTH/2)+(lenghtOfLabel/2)+13,8);
        std::cout << m_enemy->renderChar();
        ConsoleHandler::setCursorPosition(25,20);
        std::string choises[AMOUNT_OF_CHOISES] = {"Attack", "Open inventory"};
        for(unsigned int i = 0; i < AMOUNT_OF_CHOISES; i++){
            if(m_battleCycler->getIndex() == i){
                std::cout << ConsoleHandler::getFormatChar(BLINKING)
                          << ConsoleHandler::getFormatChar(INVERTED)
                          << ConsoleHandler::getColorChar(0xFFFF55, FOREGROUND)
                          << " " << choises[i] << " " << ConsoleHandler::getFormatChar(RESET) << "            ";
            }
            else{
                std::cout << choises[i] << "            ";
            }
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
            BattleWindowAttacks* battleWindowAttacks = new BattleWindowAttacks(this,m_player, m_enemy);
            Luminary::getInstance()->openWindow(battleWindowAttacks, true);
        }
        else if(index == 1)
            Luminary::getInstance()->openWindow(new InventoryWindow(this,m_player->getInventory()));
    }
}
