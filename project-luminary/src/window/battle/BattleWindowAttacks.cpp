#include "BattleWindowAttacks.h"

BattleWindowAttacks::BattleWindowAttacks(Window *prevWindow, Player *player, Enemy* enemy): ReturnableWindow(prevWindow) {
    m_player = player;
    m_enemy = enemy;
    m_battleAttacksCycler = new Cycler(PLAYER_ATTACKS-1);
}

void BattleWindowAttacks::render() {
    ConsoleHandler::setCursorPosition(11,20);
    for(int i = 0; i < PLAYER_ATTACKS; i++){
        if(m_player->getAttacks()[i] != nullptr){
            if(m_battleAttacksCycler->getIndex() == i){
                std::cout << ConsoleHandler::getFormatChar(BLINKING)
                        << ConsoleHandler::getFormatChar(INVERTED)
                        << ConsoleHandler::getColorChar(0xFFFF55, FOREGROUND) << " "
                        << m_player->getAttacks()[i]->getName() << " ";
            }
            else{
                std::cout << m_player->getAttacks()[i]->getName();
            }
        }
        else{
            if(m_battleAttacksCycler->getIndex() == i){
                std::cout << ConsoleHandler::getFormatChar(BLINKING)
                          << ConsoleHandler::getFormatChar(INVERTED)
                          << ConsoleHandler::getColorChar(0xFFFF55, FOREGROUND) << " " << "######" << " ";
            }
            else{
                std::cout << "######";
            }
        }
        std::cout << ConsoleHandler::getFormatChar(RESET) << "           ";
    }
}

void BattleWindowAttacks::onInput(ConsoleHandler::KeyEvent *evt) {
    if(evt->getKey() == KEY_D || evt->getKey() == KEY_ARROW_RIGHT){
        m_battleAttacksCycler->goUp();
        return;
    } else if(evt->getKey() == KEY_A || evt->getKey() == KEY_ARROW_LEFT){
        m_battleAttacksCycler->goDown();
        return;
    }
    if(evt->getKey() == KEY_ENTER){
        int index = m_battleAttacksCycler->getIndex();
        if(m_player->getAttacks()[index] != nullptr){
            m_enemy->dealDamage(m_player->getDamage(m_player->getAttacks()[index]));
            m_player->dealDamage(m_enemy->getDamage());
            close();
        }
    }
}
