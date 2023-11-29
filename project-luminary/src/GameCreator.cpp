
#include "GameCreator.h"
#include "console/CharBuilder.h"

Game *GameCreator::createNewGame() {
    Game* game = new Game();
    std::map<char, std::function<MapObject*()>> charMappings = {
            {
                    'G', []() {
                        return new MapObject(
                                new CharData(' ', 0x999999, 0x999999),
                                (new CharBuilder(' '))->background(0x550000)->build(),
                                true
                                );
                    }
            }
    };
    game->m_mapMatrix = {
            {
                new Map(
                "GG                                                                            GG\n"
                "G                                                                              G\n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "                                                                                \n"
                "G                                                                              G\n"
                "GG                                                                            GG\n"
                , charMappings, {})
            }
    };
    game->m_player=new Player({.x=10,.y=10});
    game->m_currentMapPos = {.x=0,.y=0};
    return game;
}
