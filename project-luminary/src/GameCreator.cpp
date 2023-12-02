
#include "GameCreator.h"
#include "console/CharBuilder.h"

Game *GameCreator::createNewGame() {
    Game* game = new Game();
    std::map<char, std::function<MapObject*()>> charMappings = {
            {
                    'G', []() {
                        return new MapObject(
                                new CharData(' ', 0x999999, 0x002A40),
                                (new CharBuilder(' '))->background(0x550000)->build(),
                                true
                                );
                    }
            },
            {
                    'h', []() {
                        return new MapObject(
                            new CharData(' ', 0x999999, 0x00547F),
                            (new CharBuilder(' '))->background(0x550000)->build(),
                            true
                            );
                    }
            },
            {
                    'i', []() {
                        return new MapObject(
                            new CharData(' ', 0x999999, 0x007FBF),
                            (new CharBuilder(' '))->background(0x550000)->build(),
                            false
                            );
                    }
            },
            {
                    'j', []() {
                        return new MapObject(
                            new CharData(' ', 0x999999, 0x006464),
                            (new CharBuilder(' '))->background(0x550000)->build(),
                            false
                            );
                    }
            },
                {
                    'k', []() {
                        return new MapObject(
                            new CharData(' ', 0x999999, 0x008D00),
                            (new CharBuilder(' '))->background(0x550000)->build(),
                            false
                            );
                }
            },


    };


    game->m_mapMatrix = {
            {
                new Map(
                        "                                                                                \n"
                        "                      GGGG                                                      \n"
                        "                    GGGGGGGG                                                    \n"
                        "                  GGGGGGGGGGGG                                                  \n"
                        "                GGGGGGGGGGGGGGGG                                                \n"
                        "              GGGGGGGGGGGGGGGGGGGG                                              \n"
                        "            GGGGGGGGGGGhhGGGGGGGGGGG                      iiiiiiiiiiiiiiii      \n"
                        "            GGGGGGGGGhhhhhhGGGGGGGGG                   iiiiiiiiiiiiiiiiiiiiii   \n"
                        "            GGGGGGGhhhhhhhhhhGGGGGGG                 iiiiiiiiiiiiiiiiiiiiiiiiiii\n"
                        "            GGGGGhhhhhhhhhhhhhhGGGGG               iiiiiiiiiiiiiiiiiiiiiiiiiiiii\n"
                        "            GGGhhhhhhiiiiiihhhhhhGGG               iiiiiiiiii            iiiiiii\n"
                        "              hhhhhhhiiiiiihhhhhhh               iiiiiiiiii                  iii\n"
                        "              hhhhhhhhhhhhhhhhhhhh               iiiiiiiiii                     \n"
                        "              hiiiiihGGGGGGhiiiiih               iiiiiiiiii                     \n"
                        "              hiiiiihGGGGGGhiiiiih               iiiiiiiiii                     \n"
                        "              hhhhhhhGGGGGGhhhhhhh             iiiiiiiiii                       \n"
                        "                     iiiiiiii                  iiiiiiiiii                       \n"
                        "                     iiiiiiii                 iiiiiiiiiii                       \n"
                        "                      iiiiiiiii             iiiiiiiiiiiii                       \n"
                        "                      iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii                         \n"
                        "                         iiiiiiiiiiiiiiiiiiiiiiiiiii                        hhhh\n"
                        "hhhh                       iiiiiiiiiiiiiiiiiiiiiii                    hhhhhhhhhh\n"
                        "hhhhhhhhhh                                                       hhhhhhhhhhhhhhh\n"
                        "hhhhhhhhhhhhhhhhhhhhh                                      hhhhhhhhhhhhhhhhhhhhh\n"
                        "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n"
                , charMappings, {})
            }
    };

    game->m_player=new Player({.x=24,.y=17});
    game->m_currentMapPos = {.x=0,.y=0};
    return game;
}
