#include "src/Luminary.h"
#include "src/window/MainMenuWindow.h"

int main() {
    auto* luminary = new Luminary(new MainMenuWindow());
    luminary->startLoop();
    return 0;
}
