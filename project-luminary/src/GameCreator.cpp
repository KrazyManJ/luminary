
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
                            (new CharBuilder('~'))->background(ColorPalette::DAY_BLUE)->foreground(ColorPalette::LIGHT_BLUE)->format(BLINKING)->build(),
                            true
                            );
                }
            },
            {
                'c', [] () {
                    return new MapObject(
                            (new CharBuilder('"'))->background(ColorPalette::DAY_GREEN)->foreground(ColorPalette::CARROT)->format(INVERTED)->format(BLINKING)->build(),
                            (new CharBuilder('"'))->background(ColorPalette::CARROT)->foreground(ColorPalette::DAY_GREEN)->format(BLINKING)->build(),
                            true
                            );
                }
            }



    };

    std::string MAP_1 =
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

    std::string MAP_2 =
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "iiiiilllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "iiiiilllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "iiiiilllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "iiiiiillllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n";

    std::string MAP_3 =
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "hhhhhhhhhhhhhhllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "hhhhhhhhhhhhhhllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "hhhhhhhhhhhhhhhhllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "hhhhhhhhhhhhhhhhllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "hhhhhhhhhhhhhhhhllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "hhhhhhhhhhhhhhhhhhlllllliiiiiiiiiiiiiillllllllllllllllllllllllllllllllllllllllll\n"
            "hhhhhhhhhhhhhhhhhhlllllliiiiiiiiiiiiiillllllllllllllllllllllllllllllllllllllllll\n"
            "hhhhhhhhhhhhhhhhhhhhlllliiiiiiiiiiiiiillllllllllllllllllllllllllllllllllllllllll\n"
            "hhhhhhhhhhhhhhhhhhhhlllliiiiiiiiiiiiiillllllllllllllllllllllllllllllllllllllllll\n";

    std::string MAP_4 =
            "hhhhhh~~hhhhhhhhhhhhillliiiiiiiiiiiiiillllllllllllllllllllllllllllllllllllllllll\n"
            "hhhhhhhh~hhh~hhhhhhhhilliiiiiiiiiiiiiilllllllwwwwlwlllllwwllllllllwwlllkkllwllll\n"
            "ihhhhhhhhhh~hhhh~hhhhilllliiiiiiiiiiiiiillllllllllllkklllllwllwlllllllkkkkllllll\n"
            "lihhh~~hhhhhhhhhhhhhhilllliiiiiiiiiiiiiiiiilwllwlllkkkkllllllwllllllkjjkkjjkllwl\n"
            "llihhhhhhh~~hhh~hhhhhiwllliiiiiiiiiiiiiiiiillllllkjjkkjjkllllllGGGGGGGGGjjkkklll\n"
            "llihhhhhhhhhh~hhhhhhhilllllliiiiiiiiiiiiiiiiiiilkkkjjjjkkkllGGjjjjjjjjjGGGkjllll\n"
            "lllihhhhhh~hhhhhhhhhhilwlllliiiiiiiiiiiiiiiiiiiljjkkkkkkjjGGjjjjjjjjjjjjjjGGllll\n"
            "lllihhhhhhh~hhh~~hhhhiillwwlllllkkiiiiiiiiiiiiilljjjjjjjjlGjjjjjjjjjjjjjjjjGGGll\n"
            "lllliihhhhhhh~hhhhhhhhhilllllllkkkkiiiiiiiiiiiiilllljjlGGGjjjjjjjjjjjjjjjjjjjGGl\n"
            "lllllihhhhhhhhhhhhhhhhhilllllkjjkkjjkiiiiiiiiiiillwlllGGjjjjjjjjjjGGGGjjjjjjjjGG\n"
            "lllwllihhh~~hhhh~hhhhhhhilwlkkkjjjjkkkiiiiiiiiiiillllGjjjjjjjjjjGGGGGGGGjjjjjjjj\n"
            "llwlllihhhhhh~hhhh~hhhhhillljjkkkkkkjjiiiiiiiiiiilllljjjjjjjjjGGGGGlllGGGjjjjjjj\n"
            "llllkkkiiihhhhh~~hhhhhhhilllljjjjjjjjllliiiiiiiiilllljjkkkkjjGGGllllllllGGGjjjjj\n"
            "llkkjjjjkkiihhhhhh~hh~hhhilllllljjlllllliiiiiiiiilllkkkkkkkkjlllllllllllllljjjjj\n"
            "lkjjjjjjjjkkiGGGGGGGGGGGGGGlllwllllllliiiiiiiiiiillkkkkkkkkkkllwlllllllwllllllll\n"
            "lllllllllllGGGiiiiiiiiiiiiGGGllllliiiiiiiiiiiiiillwllllllwlwwllllwlllwwllwllllll\n"
            "lllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiilllllwlwwlllllwllllwllllkkllwlll\n"
            "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiillllllllllllllllllwllllkkkklllll\n"
            "iiiiiiiiiiiiiGGGGGGGGGGGGGGiiiiiiiiiiiiiiiilllllllkklllllwwwlllllllllkjjkkjjklll\n"
            "iiiiiiiiiiiGGGhh~~hhhhhhhiGGGlllllwlwlwwllwllllljkkkkjlllllwllllwlllkkkjjjjkkkll\n"
            "iiiikkillllllihhhh~hhhhhhilllllllllwlllllllllllkjjkkjjkllllllllllllljjkkkkkkjjll\n"
            "lllkkkklllllihhhhhhh~~hhhilllllwwllllllwllllllkkkjjjjkkkllwwllllllllljjjjjjjjlll\n"
            "lkjjkkjjklllihhhh~hhhhhhhhilllllllwlwllllllllljjkkkkkkjjlllllwlllllllllljjllllll\n"
            "kkkjjjjkkkihhh~hhh~hh~~hhhillllllllllwwllwllllljjjjjjjjlllwlllllllwllllllwwlllll\n"
            "lkkkkkkkklihhhhhh~~hhhhh~hillllllllllllllllllllllljjlllllllllllwllllllllllllllll\n";

    std::string MAP_5 =
            "lllllllllllllllllllllllllllllliiiiiiiiiiilllllllllllllllllllllllllllllllllllllll\n"
            "lllllllllllllllllllllllllllllliiiiiiiiiiilllllllllllllllllllllllllllllllllllllll\n"
            "lllllllllllllllllllllllllllllliiiiiiiiiiillllllllkklllllllllllllllllllllllllllll\n"
            "lllllllllllllllllllllllllllllliiiiiiiiiiilllllllkkkkllllllllllllllllllllllllllll\n"
            "lllllllllllllllllllllllllllllliiiiiiiiiiilllllkjjkkjjkllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllliiiiiiiiiiiillllllkkkjjjjkkklllllllllllllllllllllllll\n"
            "lllllllllllllllllllllliiiiiiiiiiiiiiillllllljjkkkkkkkkjjllllllllllllllllllllllll\n"
            "lllllllllllllllllllliiiiiiiiiiiiiillllllllllljjjjjjjjjjlllllllllllllllllllllllll\n"
            "llllllllllllliiiiiiiiiiiiiiiiillllllllllllllllllljjlllllllllllllllllllllllllllll\n"
            "lllllllllliiiiiiiiiiiiiiillllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "lllllllliiiiiiiiiiiiiiilllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "lllllllliiiiiiiiiiiiiillllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "lllllllliiiiiiiiiiiiiillllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "lllllllliiiiiiiiiiiillllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "lllllllliiiiiiiiiiiilllllllllllllllllllliiiiiiiiiiiillllllllllllllllllllllllllll\n"
            "llllllllliiiiiiiiiiiillllllllllllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiilllllllllllllll\n"
            "lllllllllliiiiiiiiiiiillllllllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiillllllllll\n"
            "llllllllllliiiiiiiiiiilllllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii\n"
            "llllllllllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiillllllllliiiiiiiiiiiiiiiiiiiiii\n"
            "llllllllllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiilllllllllllllliiiiiiiiiiiiiiiiiiiiii\n"
            "llllllllllllllliiiiiiiiiiiiiiiiiiiiiiiiiiillllllllllllllllllllllliiiiiiiiiiiiiii\n"
            "llllllllllllllllllliiiiiiiiiiiiiiiiiiillllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n";

    std::string MAP_6 =
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n";

    std::string EMPTY_MAP;
    game->m_mapMatrix = {
            {
                new Map(MAP_1, charMappings, {}),
                new Map(MAP_2, charMappings,{})
            },
            {
                new Map(MAP_6, charMappings,{}),
                new Map(MAP_3, charMappings,{})
            },
            {
                new Map(MAP_5, charMappings,{}),
                new Map(MAP_4, charMappings,{})
            }
    };

    game->m_player=new Player({.x=24,.y=17});
    game->m_currentMapPos = {.x=0,.y=0};
    return game;
}
