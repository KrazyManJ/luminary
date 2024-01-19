#include "DebugGame.h"
#include "map/Enemy.h"
#include "console/CharBuilder.h"
#include "map/ItemEntity.h"
#include "map/Torch.h"

Game *DebugGame::create() {
    Game *game = new Game();
    game->m_player = new Player({.x=10, .y=2});
    game->m_torchesOrder = {
            new Torch(),
            new Torch(),
            new Torch(),
            new Torch(),
            new Torch()
    };
    const std::string emptyMatrix =
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG0GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "WWGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGWWWWWWWWWWGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "WWWWWWWWWWWWGGGGGGGGGGGGGGGGGGGGGGGGGGGGWWWWWWWWWWWWWWWWWGGGGGGGGGGGGGGGGGGGGGGG\n"
            "WWWWWWWWWWWWWWWWWWWWWWWGGGGGGGGGGGGGGWWWWWWWWWWWWWWWWWWWWWWWWGGGGGGGGGGGGGGGGGGG\n"
            "GGWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGWWWWWWWWWWWWWWWWWWWWGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGWWWWWWWWWWWWWGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n";
    std::map<char, std::function<MapObject *()>> map = {
            {
                    'G', []() {
                    return new MapObject(
                            new CharData(' ', COLOR_NONE, 0x1a472e),
                            new CharData(' ', COLOR_NONE, 0x3ccf7d),
                            false
                    );
                }
            },
            {
                    'W', []() {
                    return new MapObject(
                            new CharData(' ', COLOR_NONE, 0x253352),
                            new CharData(' ', COLOR_NONE, 0x476bba),
                            true
                    );
                },
            },
            {
                '0', [&game]() {
                    return game->m_torchesOrder.at(0);
                }
            }
    };
    game->m_mapMatrix = {
            {
                    new Map(emptyMatrix, map, {
                            new Enemy({.x=5,.y=5},5,5,(new CharBuilder('%'))->background(0xFF0000)->build()),
                            new ItemEntity(new Heal("xd",5,(new CharBuilder('X'))->build()) ,{.x=8,.y=5}),
                            new ItemEntity(new Heal("xd",5,(new CharBuilder('X'))->build()) ,{.x=5,.y=3},(new CharBuilder('X'))->build())
//                        new Enemy({.x=5,.y=5},5,5,new CharData('%',0xFF0000,COLOR_NONE))
                    }),
                    new Map(emptyMatrix, map, {}),
            },
            {
                    new Map(emptyMatrix, map, {}),
                    new Map(emptyMatrix, map, {}),
            },
            {
                    new Map(emptyMatrix, map, {}),
                    new Map(emptyMatrix, map, {}),
            }
    };
    game->m_currentMapPos = {.x = 0, .y=0};
    return game;
}
