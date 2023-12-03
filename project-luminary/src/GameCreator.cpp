
#include "GameCreator.h"
#include "console/CharBuilder.h"
#include "palettes/ColorPalette.h"


Game *GameCreator::createNewGame() {
    Game* game = new Game();

    std::map<char, std::function<MapObject*()>> charMappings = {
            {
                    'G', []() {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::DARK_BLUE)->build(), //dark
                                (new CharBuilder())->background(ColorPalette::ORANGE)->build(), //light
                                true
                                );
                    }
            },
            {
                    'h', []() {
                        return new MapObject(
                            (new CharBuilder())->background(ColorPalette::BLUE)->build(),
                            (new CharBuilder())->background(ColorPalette::DAY_BLUE)->build(),
                            true
                            );
                    }
            },
            {
                    'i', []() {
                        return new MapObject(
                            (new CharBuilder())->background(ColorPalette::LIGHT_BLUE)->build(),
                            (new CharBuilder())->background(ColorPalette::PATH)->build(),
                            false
                            );
                    }
            },
            {
                    'j', []() {
                        return new MapObject(
                            (new CharBuilder())->background(ColorPalette::DARK_GREEN)->build(),
                            (new CharBuilder())->background(ColorPalette::GREEN)->build(),
                            true
                            );
                    }
            },
            {
                    'k', []() {
                        return new MapObject(
                            (new CharBuilder())->background(ColorPalette::GREEN)->build(),
                            (new CharBuilder())->background(ColorPalette::TREE_GREEN)->build(),
                            true
                            );
                    }
            },
            {
                    'l', [] () {
                        return new MapObject(
                            (new CharBuilder())->background(ColorPalette::BG_COLOR)->build(),
                            (new CharBuilder())->background(ColorPalette::DAY_GREEN)->build(),
                            false
                            );
                    }

            },
            {
                    'w', []() {
                        return new MapObject(
                            (new CharBuilder('w'))->background(ColorPalette::BG_COLOR)->foreground(ColorPalette::BLUE)->build(),
                            (new CharBuilder('w'))->background(ColorPalette::DAY_GREEN)->foreground(ColorPalette::GREEN)->build(),
                            false
                            );
                    }
            },
            {
                '~', [] () {
                    return new MapObject(
                            (new CharBuilder('~'))->background(ColorPalette::BLUE)->foreground(ColorPalette::LIGHT_BLUE)->format(BLINKING)->build(),
                            (new CharBuilder('~'))->background(ColorPalette::DAY_BLUE)->foreground(ColorPalette::BLUE)->format(BLINKING)->build(),
                            true
                            );
                }
            },



    };

    std::string STARTING_MAP =
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllwwllllllllllllllGGGGlllwllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "lllllllllwwlllllllllGGGGGGGGllllllllwwlllllllllkkllllllllllwwllllwwwllllllllllll\n"
            "llllllllllllllllllGGGGGGGGGGGGllllllllwlllllllkkkklllllllwllwwwwwlllllllwlllllll\n"
            "llllwlllllllllllGGGGGGGGGGGGGGGGllllllllllllkjjkkjjkllllllwlllllwwwwwlllllllllll\n"
            "llllllllllllllGGGGGGGGGGGGGGGGGGGGlllllllllkkkjjjjkkklllllllllllllllllllllllllll\n"
            "llllllllllllGGGGGGGGGGGhhGGGGGGGGGGGllllllljjkkkkkkjjllllliiiiiiiiiiiiiiiillllll\n"
            "llllllllllllGGGGGGGGGhhhhhhGGGGGGGGGlllllllljjjjjjjjllliiiiiiiiiiiiiiiiiiiiiilll\n"
            "llllllllllllGGGGGGGhhhhhhhhhhGGGGGGGllllllllllljjlllliiiiiiiiiiiiiiiiiiiiiiiiiii\n"
            "llllllkkllllGGGGGhhhhhhhhhhhhhhGGGGGllllkkllllllllliiiiiiiiiiiiiiiiiiiiiiiiiiiii\n"
            "lllllkkkklllGGGhhhhhhiiiiiihhhhhhGGGlllkkkklllllllliiiiiiiiiilllllllllllliiiiiii\n"
            "lllkjjkkjjklllhhhhhhhiiiiiihhhhhhhlllkjjkkjjklllliiiiiiiiiilllllllwwwwllllllliii\n"
            "llkkkjjjjkkkllhhhhhhhhhhhhhhhhhhhhllkkkjjjjkkkllliiiiiiiiiilllllwwwkkwllllllllll\n"
            "lljjkkkkkkjjllhiiiiihGGGGGGhiiiiihlljjkkkkkkjjllliiiiiiiiiilllllllkkkkllllllllll\n"
            "llljjjjjjjjlllhiiiiihGGGGGihiiiiihllljjjjjjjjlllliiiiiiiiiilllllkjjkkjjkllllllll\n"
            "lllllljjllllllhhhhhhhGGGGGGhhhhhhhllllwwjjllllliiiiiiiiiillllllkkkjjjjkkklllllll\n"
            "llllllwllllwlllllllliiiiiiiilllllllllwwlllwlllliiiiiiiiiilllllljjkkkkkkjjlllllll\n"
            "llllllllwwwwwwwllllliiiiiiiiillllllllllllllllliiiiiiiiiiillllllljjjjjjjjllllwlll\n"
            "llllllwlllwwlllllllllliiiiiiiiillllllllllllliiiiiiiiiiiiilllllwwllljjlllllllllll\n"
            "llllllllllllllwwlllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiillllllllllllllllllllliiii\n"
            "iiiillllllllllllllllllllliiiiiiiiiiiiiiiiiiiiiiiiiiillllllwwlllwlllllliiiiiihhhh\n"
            "hhhhiiiiiilllllwwwllllllllliiiiiiiiiiiiiiiiiiiiiiillllllwwwwwlllliiiiihhhhhhh~hh\n"
            "hhhhhhhhhhiiiiiiiiiiillwlllllllllllllllllllllllllllllwllllliiiiiihhhhhhhhh~hhhhh\n"
            "hhhh~h~h~hhhhhh~hhhhhiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiihhhhhh~h~h~hh~hh~hhhh\n"
            "hhhhh~h~hhhhhhhh~hhhhhhhhhhhhh~hhhhhhhh~hhhhhhhhhhhhhhhhhhhhhhhhhh~h~hhhhhhhhhhh\n";

    std::string EMPTY_MAP;
    game->m_mapMatrix = {
            {
                new Map(STARTING_MAP, charMappings, {}),
                new Map(EMPTY_MAP, charMappings,{})
            },
            {
                new Map(EMPTY_MAP, charMappings,{}),
                new Map(EMPTY_MAP, charMappings,{})
            },
            {
                new Map(EMPTY_MAP, charMappings,{}),
                new Map(EMPTY_MAP, charMappings,{})
            }
    };

    game->m_player=new Player({.x=24,.y=17});
    game->m_currentMapPos = {.x=0,.y=0};
    return game;
}
