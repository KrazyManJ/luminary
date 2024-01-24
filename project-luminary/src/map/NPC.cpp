

#include "NPC.h"
#include "../palettes/ColorPalette.h"
#include "../Luminary.h"
#include "../window/GameDialog.h"

NPC::NPC(char character, std::string dialogue) : MapObject(
    new CharData(character, ColorPalette::FG_PLAYER, ColorPalette::NPC_PINK),
    new CharData(character, ColorPalette::FG_PLAYER, ColorPalette::NPC_PINK),
    true){
    m_dialogue = dialogue;
}

void NPC::onCollision(Game *game) {
    Luminary::getInstance()->openWindow(new GameDialog(
            m_dialogue
            ,game), true);
}
