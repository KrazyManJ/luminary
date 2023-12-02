#ifndef PROJECT_LUMINARY_INVENTORYWINDOW_H
#define PROJECT_LUMINARY_INVENTORYWINDOW_H


#include "Window.h"
#include "ReturnableWindow.h"
#include "../inventory/Inventory.h"

class InventoryWindow : public ReturnableWindow {
private:
    Inventory* m_openedInventory;
public:
    InventoryWindow(Window *prevWindow, Inventory* inventory);

    void render() override;

    void onInput(ConsoleHandler::KeyEvent *evt) override;
};


#endif //PROJECT_LUMINARY_INVENTORYWINDOW_H
