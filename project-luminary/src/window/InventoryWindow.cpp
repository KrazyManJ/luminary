#include <iostream>
#include "InventoryWindow.h"

//#include "Item.h"
void InventoryWindow::render() {

    const unsigned short MARGIN_WIDTH = 4;
    const unsigned short MARGIN_HEIGHT = 2;
    const unsigned short GRID_HEIGHT = 2;
    const unsigned short GRID_WIDTH = 4;

    for (unsigned int row = MARGIN_HEIGHT; row < Window::HEIGHT - MARGIN_HEIGHT; row++) {
        ConsoleHandler::setCursorPosition(MARGIN_WIDTH + 1, row + 1);
        std::string output;
        for (unsigned int col = MARGIN_WIDTH; col < Window::WIDTH - MARGIN_WIDTH; col++) {
            output.append(ConsoleHandler::getFormatChar(RESET) + " ");
        }
        std::cout << output;

    }

    for (unsigned int gridH = MARGIN_HEIGHT + 4; gridH < Window::HEIGHT - MARGIN_HEIGHT - 2; gridH++) {
        ConsoleHandler::setCursorPosition(MARGIN_WIDTH + 4, gridH + 1);
        std::string output;
        for (unsigned int gridW = MARGIN_WIDTH + 4; gridW < Window::WIDTH / 2; gridW += 2) {
            if (gridH % 2 == 0)
                output.append(ConsoleHandler::getFormatChar(RESET) + "| ");
            else
                output.append(ConsoleHandler::getFormatChar(RESET) + "--");
        }
        output.append(ConsoleHandler::getFormatChar(RESET) + (gridH % 2 == 0 ? "|" : "-"));
        std::cout << output;
    }


    const std::string INVENTORY_LABEL = "Inventory";
    ConsoleHandler::setCursorPosition(Window::WIDTH / 2 - INVENTORY_LABEL.length() / 2, MARGIN_HEIGHT + 1);
    std::cout << INVENTORY_LABEL;

    int i = 0;
    int z = 0;
    for (auto *heal: m_openedInventory->getHeals()) {
        ConsoleHandler::setCursorPosition(9+2*i, 7+z*2);
        std::cout<< heal->renderChar();
        i++;
    if (6+2*i> Window::WIDTH/2 -3){
        z++;
        i = 0;
    }
    }
    i = 0;
    z = 0;
    for (auto *weapon: m_openedInventory->getWeapons()) {
        ConsoleHandler::setCursorPosition(9+2*i, 15+z*2);
        std::cout<< weapon->renderChar();
        i++;
        if (6+2*i> Window::WIDTH/2 -3 && Window::HEIGHT/2-2){
            z++;
            i = 0;
        }
    }

}
    void InventoryWindow::onInput(ConsoleHandler::KeyEvent *evt) {
        if (evt->getKey() == KEY_E || evt->getKey() == KEY_ESC) close();
    }

    InventoryWindow::InventoryWindow(Window * prevWindow, Inventory * inventory) : ReturnableWindow(prevWindow) {
            m_openedInventory = inventory;
    }



