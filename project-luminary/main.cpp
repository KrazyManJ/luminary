#include "src/Luminary.h"
#include "src/window/MainMenuWindow.h"

int main() {
    auto* luminary = new Luminary(new MainMenuWindow());
    luminary->startLoop();
    delete luminary;
    return 0;
}
