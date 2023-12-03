
#include "GameCreator.h"
#include "console/CharBuilder.h"
#include "palettes/ColorPalette.h"


Game *GameCreator::createNewGame() {
    Game* game = new Game();
    std::map<char, std::function<MapObject*()>>mapObjectMap = {
            {
                    'F',[]() {
                        return new MapObject(
                            (new CharBuilder('X'))->build(),
                            (new CharBuilder('X'))->build(),
                            true);
                }
            }
    };
    std::map<char, std::function<MapObject*()>> charMappings = {
            {
                    'G', []() {
                        return new MapObject(
                                new CharData(' ', 0x999999, ColorPalette::DARK_BLUE),
                                (new CharBuilder(' '))->background(0x550000)->build(),
                                true
                                );
                    }
            },
            {
                    'h', []() {
                        return new MapObject(
                            new CharData(' ', 0x999999, ColorPalette::BLUE),
                            (new CharBuilder())->background(0x550000)->build(),
                            true
                            );
                    }
            },
            {
                    'i', []() {
                        return new MapObject(
                            new CharData(' ', 0x999999, ColorPalette::LIGHT_BLUE),
                            (new CharBuilder())->background(0x550000)->build(),
                            false
                            );
                    }
            },
            {
                    'j', []() {
                        return new MapObject(
                            new CharData(' ', 0x999999, ColorPalette::DARK_GREEN),
                            (new CharBuilder())->background(0x550000)->build(),
                            true
                            );
                    }
            },
                {
                    'k', []() {
                        return new MapObject(
                            new CharData(' ', 0x999999, ColorPalette::GREEN),
                            (new CharBuilder())->background(0x550000)->build(),
                            true
                            );
                }
            },

            {
                    'w', []() {
                        return new MapObject(
                            new CharData('w', ColorPalette::BLUE, 0x0d0d0d),
                            (new CharBuilder())->background(0x999999)->build(),
                            false
                            );
                }
            },



    };

    std::string STARTING_MAP =
            "                                                                                \n"
            "      ww              GGGG   w                                                  \n"
            "         ww         GGGGGGGG        ww         kk          ww    www            \n"
            "                  GGGGGGGGGGGG        w       kkkk       w  wwwww       w       \n"
            "    w           GGGGGGGGGGGGGGGG            kjjkkjjk      w     wwwww           \n"
            "              GGGGGGGGGGGGGGGGGGGG         kkkjjjjkkk                           \n"
            "            GGGGGGGGGGGhhGGGGGGGGGGG       jjkkkkkkjj     iiiiiiiiiiiiiiii      \n"
            "            GGGGGGGGGhhhhhhGGGGGGGGG        jjjjjjjj   iiiiiiiiiiiiiiiiiiiiii   \n"
            "            GGGGGGGhhhhhhhhhhGGGGGGG           jj    iiiiiiiiiiiiiiiiiiiiiiiiiii\n"
            "      kk    GGGGGhhhhhhhhhhhhhhGGGGG    kk         iiiiiiiiiiiiiiiiiiiiiiiiiiiii\n"
            "     kkkk   GGGhhhhhhiiiiiihhhhhhGGG   kkkk        iiiiiiiiii            iiiiiii\n"
            "   kjjkkjjk   hhhhhhhiiiiiihhhhhhh   kjjkkjjk    iiiiiiiiii       wwww       iii\n"
            "  kkkjjjjkkk  hhhhhhhhhhhhhhhhhhhh  kkkjjjjkkk   iiiiiiiiii     wwwkkw          \n"
            "  jjkkkkkkjj  hiiiiihGGGGGGhiiiiih  jjkkkkkkjj   iiiiiiiiii       kkkk          \n"
            "   jjjjjjjj   hiiiiihGGGGGihiiiiih   jjjjjjjj    iiiiiiiiii     kjjkkjjk        \n"
            "      jj      hhhhhhhGGGGGGhhhhhhh    wwjj     iiiiiiiiii      kkkjjjjkkk       \n"
            "      w    w         iiiiiiii        ww   w    iiiiiiiiii      jjkkkkkkjj       \n"
            "        wwwwwww      iiiiiiii                 iiiiiiiiiii       jjjjjjjj    w   \n"
            "      w   ww          iiiiiiiii             iiiiiiiiiiiii     ww   jj           \n"
            "              ww      iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii                         \n"
            "                         iiiiiiiiiiiiiiiiiiiiiiiiiii      ww   w            hhhh\n"
            "hhhh           www         iiiiiiiiiiiiiiiiiiiiiii      wwwww         hhhhhhhhhh\n"
            "hhhhhhhhhh             w                             w           hhhhhhhhhhhhhhh\n"
            "hhhhhhhhhhhhhhhhhhhhh                                      hhhhhhhhhhhhhhhhhhhhh\n"
            "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n";

    game->m_mapMatrix = {
            {
                new Map(STARTING_MAP, charMappings, {}),
                new Map("   ", mapObjectMap,{})
            },
            {
                new Map("   ", mapObjectMap,{}),
                new Map("   ", mapObjectMap,{})
            },
            {
                new Map("   ", mapObjectMap,{}),
                new Map("   ", mapObjectMap,{})
            }
    };

    game->m_player=new Player({.x=24,.y=17});
    game->m_currentMapPos = {.x=0,.y=0};
    return game;
}
