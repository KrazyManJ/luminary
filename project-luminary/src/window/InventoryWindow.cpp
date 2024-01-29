#include <iostream>
#include "InventoryWindow.h"
#include "../utils/Cycler.h"
#include <vector>
//#include "Item.h"
void InventoryWindow::render() {

    const unsigned short MARGIN_WIDTH = 4;
    const unsigned short MARGIN_HEIGHT = 2;

    // window background
    for (unsigned int row = MARGIN_HEIGHT; row < Window::HEIGHT - MARGIN_HEIGHT; row++) {
        ConsoleHandler::setCursorPosition(MARGIN_WIDTH + 1, row + 1);
        std::string output;
        for (unsigned int col = MARGIN_WIDTH; col < Window::WIDTH - MARGIN_WIDTH; col++) {
            output.append(ConsoleHandler::getFormatChar(RESET) + " ");
        }
        std::cout << output;
    }

    //inventory label
    const std::string INVENTORY_LABEL = "Inventory";
    ConsoleHandler::setCursorPosition(Window::WIDTH / 2 - INVENTORY_LABEL.length() / 2, MARGIN_HEIGHT + 1);
    std::cout << INVENTORY_LABEL;

    // grid
    const unsigned short X_GRID_START = MARGIN_WIDTH+4;
    const unsigned short SECTION_ROWS = 3;
    const unsigned short HEALS_POSITION_Y = MARGIN_HEIGHT+4;
    const unsigned short WEAPONS_POSITION_Y = HEALS_POSITION_Y+SECTION_ROWS*2+2;

    for (int yPos : {HEALS_POSITION_Y, WEAPONS_POSITION_Y}){
        for (unsigned int gridP = 0; gridP < SECTION_ROWS*2-1; gridP++) {
            ConsoleHandler::setCursorPosition(X_GRID_START, yPos + gridP + 1);
            std::string output;
            for (unsigned int gridW = 0; gridW < SLOTS_IN_ROW; gridW++) {
                if (gridP % 2 == 0)
                    output.append(ConsoleHandler::getFormatChar(RESET) + "| ");
                else
                    output.append(ConsoleHandler::getFormatChar(RESET) + "--");
            }
            output.append(ConsoleHandler::getFormatChar(RESET) + (gridP % 2 == 0 ? "|" : "-"));
            std::cout << output;
        }
    }
    ConsoleHandler::setCursorPosition(MARGIN_WIDTH+4,HEALS_POSITION_Y);
    std::cout << "Heals:";
    ConsoleHandler::setCursorPosition(MARGIN_WIDTH+4,WEAPONS_POSITION_Y);
    std::cout << "Weapons:";

    //fill grid with items
    //weapons write
    int itemIndex = 0;
    for (int i = 0; i < m_openedInventory->getHeals().size(); i++){
        ConsoleHandler::setCursorPosition(X_GRID_START+(i%SLOTS_IN_ROW)*2+1, HEALS_POSITION_Y+1+(i/SLOTS_IN_ROW)*2);
        if (m_InventoryCycler->getIndex() == itemIndex)
            std::cout
            << ConsoleHandler::getFormatChar(BLINKING)
            << ConsoleHandler::getFormatChar(INVERTED)
            ;
        std::cout
            << m_openedInventory->getHeals().at(i)->renderChar()
            << ConsoleHandler::getFormatChar(RESET)
        ;
        itemIndex++;
    }

    // heals write
    for (int i = 0; i < m_openedInventory->getWeapons().size(); i++){
        ConsoleHandler::setCursorPosition(X_GRID_START+(i%SLOTS_IN_ROW)*2+1, WEAPONS_POSITION_Y+1+(i/SLOTS_IN_ROW)*2);
        if (m_InventoryCycler->getIndex() == itemIndex)
            std::cout
                << ConsoleHandler::getFormatChar(BLINKING)
                << ConsoleHandler::getFormatChar(INVERTED)
            ;
        std::cout
            << m_openedInventory->getWeapons().at(i)->renderChar()
            << ConsoleHandler::getFormatChar(RESET)
        ;
        itemIndex++;
    }
}

void InventoryWindow::onInput(ConsoleHandler::KeyEvent *evt) {
    if (evt->getKey() == KEY_E || evt->getKey() == KEY_ESC) {
        close();
        return;
    }
    if (evt->getKey() == KEY_ARROW_LEFT || evt->getKey() == KEY_A) {
        m_InventoryCycler->goDown();
        return;
    }
    if (evt->getKey() == KEY_ARROW_RIGHT || evt->getKey() == KEY_D) {
        m_InventoryCycler->goUp();
        return;
    }
    if (evt->getKey() == KEY_ARROW_DOWN || evt->getKey() == KEY_S) {
        for (int i = 0; i < SLOTS_IN_ROW; i++)
            m_InventoryCycler->goUp();
        return;
    }
    if (evt->getKey() == KEY_ARROW_UP || evt->getKey() == KEY_W) {
        for (int i = 0; i < SLOTS_IN_ROW; i++)
            m_InventoryCycler->goDown();
        return;
    }
}

InventoryWindow::InventoryWindow(Window *prevWindow, Inventory *inventory) : ReturnableWindow(prevWindow) {
    m_openedInventory = inventory;
    m_InventoryCycler = new Cycler (inventory->getHeals().size()+inventory->getWeapons().size()-1);
}



