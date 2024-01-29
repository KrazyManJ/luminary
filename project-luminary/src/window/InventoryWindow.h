#ifndef PROJECT_LUMINARY_INVENTORYWINDOW_H
#define PROJECT_LUMINARY_INVENTORYWINDOW_H


#include "Window.h"
#include "ReturnableWindow.h"
#include "../inventory/Inventory.h"
#include "../utils/Cycler.h"

class InventoryWindow : public ReturnableWindow {
private:
    const unsigned short SLOTS_IN_ROW = 15;
    Player* m_player;
    Inventory* m_openedInventory;
    Cycler* m_InventoryCycler;

    void updateCycler();
public:
    InventoryWindow(Window *prevWindow, Player* player);

    void render() override;

    void onInput(ConsoleHandler::KeyEvent *evt) override;


};


#endif //PROJECT_LUMINARY_INVENTORYWINDOW_H
