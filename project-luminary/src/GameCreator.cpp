
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
            },
            {
                'd', [] () {
                    return new MapObject(
                            (new CharBuilder('_'))->background(ColorPalette::LIGHT_BLUE)->foreground(ColorPalette::BLUE)->build(),
                            (new CharBuilder('_'))->background(ColorPalette::PATH)->foreground(ColorPalette::DAY_GREEN)->build(),
                            false
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
            "llllllkkllllGGGGGhhhhhhhhhhhhhhGGGGGlliididddlllllliiiiiiiiiiiiiiiiiiiiiiiiiiiii\n"
            "lllllkkkklllGGGhhhhhhiiiiiihhhhhhGGGlliddiidilllllliiiiiiiiiilllllllllllliiiiiii\n"
            "lllkjjkkjjklllhhhhhhhiiiiiihhhhhhhllllidiiiddlllliiiiiiiiiilllllllwwwwllllllliii\n"
            "llkkkjjjjkkkllhhhhhhhhhhhhhhhhhhhhlllliidiidilllliiiiiiiiiilllllwwwkkwllllllllll\n"
            "lljjkkkkkkjjllhiiiiihGGGGGGhiiiiihllllddiiiiilllliiiiiiiiiilllllllkkkkllllllllll\n"
            "llljjjjjjjjlllhiiiiihGGGGGihiiiiihllllllllllllllliiiiiiiiiilllllkjjkkjjkllllllll\n"
            "lllllljjllllllhhhhhhhGGGGGGhhhhhhhllllwwllllllliiiiiiiiiillllllkkkjjjjkkklllllll\n"
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
            "lllllllllllllllllllllllllllllllllllllllllllllllllllllllwlwllllllllllllllllllllll\n"
            "lllllwlllwllllllllllllllwlllwlllllllllllllllllllllllwlllllllwlwwllllllllllllllll\n"
            "llllllllkkkkklllllllllwllllllllllllllllllllllhhhhhhhhhhhhhhhhllllllwllllllwwllll\n"
            "llllllkkkkkkkkjllllwlllllllllllllllllhhhhhhhhh~~hh~hh~hhhh~hhhhhhhllllllllllllll\n"
            "lllljjjjjjjjjjjjlllllllllllliiiiiiiddddddddddddddddddhhh~hhhhhhhhhhhhhhlllllllll\n"
            "llllllllllwlllllllwlllllliiiiiiiiiiddddddddddddddddddhhhhhh~~hh~hhhhhhhhhhhlllll\n"
            "llllllwwlllllllllllllliiiiiiiiiiiiiddddddddddddddddddhhhhhhhhhhhhhhhhhhhhhhhhlll\n"
            "llllllllllllllllliiiiiiiiiiiiiiiiiiddddddddddddddddddhhhhhhhhh~hh~hhh~~hhhhhhlll\n"
            "iiiiiiiiiiiiiiiiiiiiiiiiiiiiilllllllhhh~~hh~hhhhhhhGGhhh~hh~hhhhhhhhhhhhhhhhllll\n"
            "iiiiiiiiiiiiiiiiiiiiiiiiiillllllllllhhhhhhh~~hh~hhhhh~hhhhhhh~hh~hhhhhh~hhhhllll\n"
            "iiiiiiiiiiiiiiiiiiiiiiiiiillllwlllllhhhhhhhhhhhhhh~hhhh~~hhhhhh~hhhh~hhhhhhhllll\n"
            "iiiiiiiiiiiiiiiiiiiiiiiiiiiillllllwlllllhhhhhh~hhhhhhhhhh~~hhhhhhh~hhhhhhhllllll\n"
            "llllllllliiiiiiiiiiiiiiiiiiiiillllllllllllllhhhhhhh~~hhhhhh~hhh~hhhhhhhhhlllwlll\n"
            "llllllkklllllllliiiiiiiiiiiiiiiillwllllllllllllllhhhhhh~~hhhh~hhhh~h~hhhhllwllll\n"
            "lllllkkkkllllwlllliiiiiiiiiiiiiilllwwllllllllllllllllhhhhh~~hh~hhhhhhhhhhlllllll\n"
            "lllkjjkkjjkllllllllliiiiiiiiiiiilllllllllllkkllllllllllllhhhhhhhhh~hhhhhllwllwll\n"
            "llkkkjjjjkkkllwwwwlliiiiiiiiiiiiilllllwlllkkkklllllwwlllllllhhhhhhhhhhlllllwllll\n"
            "lljjkkkkkkjjlllllllllliiiiiiiiiiiilwllllkjjkkjjkllllllwlllllllllllllllllllllllll\n"
            "llljjjjjjjjllllllllllliiiiiiiiiiiilllllkkkjjjjkkklllllllwwllllllwllllkklllwlllll\n"
            "lllllljjllllllllllwllliiiiiiiiiiiillwlljjkkkkkkjjllwwlllllllllllllllkkkkllllllll\n"
            "llllllllllkkkkjlllwllliiiiiiiiiiiilllllljjjjjjjjllllllllllllllllllkjjkkjjklllwll\n"
            "lllwllllkkkkkkkkjlllliiiiiiiiiiiiilwwlllllljjllllwllllkkkkkjlllllkkkjjjjkkklllll\n"
            "lllllljjjjjjjjjjjjlliiiiiiiiiiiiilllwlllllllllllllllkkkkkkjjlllljjkkkkkkjjllllll\n"
            "lllwlllllllwlllllllliiiiiiiiiiiiillllllwlwlllllwllljjjjjjjjjjjlllljjjjjjjjllllll\n"
            "lllllllllllllllllllliiiiiiiiiiiiilllllllllllllllllllllllllllllllllllljjlllllllll\n";

    std::string MAP_3 =
            "lllllllllllllllllllliiiiiiiiiiiiilllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllkkkklllllllwwlliiiiiiiiiiiiiillllwllllwwwwwwllwllllllllllwwwllllllllwwllll\n"
            "llllkkkkkjjjlllwllllliiiiiiiiiiiiiillwwlllllllwlllllllwllllllwwwlllllwllllllllll\n"
            "llljjjjjjjjjjlllllwlllliiiiiiiiiiiiillllllwwlllllwlllllllllllliiiiiiiiiiiiiiiiii\n"
            "lllllllllllwwwlllllllwlliiiiiiiiiiiilllwwwllwllliiiiiiiiiiiiiihhhhhhhhhhhhhhhhhh\n"
            "lllllwwwwlllllwwlllllllliiiiiiiiiiiilllllllliiiihhhhhhhhh~hhhhhhhh~~hhhhhhhhhhhh\n"
            "llllllwlllwllllliiiiiiiGGiiiiiiiiiiGGiiiiiiihhhhh~~~hhh~hhhh~~h~hhhhh~hh~hhhhhhh\n"
            "lllllliiiiiiiiiihhhhhhhGGiiiiiiiiiiGGhhhhhhhhhhhhhh~hhhhh~~hhhhhhh~hhh~hhhh~hhhh\n"
            "iiiiiihhhhhhhhhhhhh~~hhGGiiiiiiiiiiGGhhh~~h~~hhhhhh~hhh~hhhh~hhh~hhh~~hhhhhhhhhh\n"
            "hhhhhhhhh~~hhh~hhhhhhhhGGiiiiiiiiiiGGhhhhhhhhhhhhhhhhhhhhhhhhhhhhh~hhhhhhh~hhhhh\n"
            "hhh~~hhhhhhhh~hhhh~hhhhGGiiiiiiiiiiGGhhhhh~~hh~hhhh~~~~hhhh~~hhhhkk~hhhhhhhhhhhh\n"
            "hhhhh~~hh~hhhhhh~~hhhhhGGiiiiiiiiiiGGhhhhhhh~~hhhhhhhh~hhhhhhhhhkkkkhhhhiiiiiiii\n"
            "h~hhhhhhhhhhhh~hhhhhhhhGGiiiiiiiiiiGGhhhhhhhhhhhhhhhhhhhhiiiiikjjkkjjkiillllllll\n"
            "hhh~~hhh~hhh~~hhhhhhhhhGGiiiiiiiiiiGGiiiiiiiiiiiiiiiiiiiillllkkkjjjjkkkllllwllll\n"
            "hhhhh~~hhhhhhhhhhiiiiiiGGiiiiiiiiiiGGlllwwllllkkllllllllllllljjkkkkkkjjllllwllll\n"
            "hhh~hhhh~hhhhhhilllllllliiiiiiiiiiiillllllwllkkkkllllwwwlllllljjjjjjjjlllwwwllll\n"
            "hhhhhh~hhhhhhhilwwwllllliiiiiiiiiiiiiilllllkjjkkjjklllllwlllllllljjlllwwllllllll\n"
            "hhh~hhhhhhhhhhillllwwllllliiiiiiiiiiiiilllkkkjjjjkkklllllllwlllllwwlllkkkkllllll\n"
            "hhhhh~hhh~~hhhhhilllwllllliiiiiiiiiiiiiilljjkkkkkkjjllwllllkklllllllkkkkkjjjllll\n"
            "hhhhhhh~hhhhhhhhillllwwwllliiiiiiiiiiiiillljjjjjjjjlllllllkkkkllllljjjjjjjjjjlll\n"
            "hhh~~hhhhhhhhhhhilwwlllllllliiiiiiiiiiiiillllljjllllllwlkjjkkjjkllllllllllllllll\n"
            "hhhhh~hhh~~hhhhhhiilwwwllwlliiiiiiiiiiiiillwwwwwlllwlllkkkjjjjkkklllwwlllwlwllll\n"
            "hhhhhhh~hhh~~hhhhiillllwwllliiiiiiiiiiiiillllllwwlllllljjkkkkkkjjllllwwwwlllllll\n"
            "hhh~~hhhh~hhhh~hhhhiillllliiiiiiiiiiiiiilllllllllllwwllljjjjjjjjllllwllllllwwlll\n"
            "hhhhhhhhhhhhhhhhhhhiillliiiiiiiiiiiiiillllwwllwlllllllllllljjlllllllllllllllllll\n";

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
            "lllllllkkllllllwwwllwlwwlllllliiiiiiiiiiillllllllllllllllllwllllwwwwllllllllllll\n"
            "llllllkkkkllllllllwllllwllllliiiiiiiiiiiillllllllkklllllllllwwwllllwwwwlllllllll\n"
            "llllkjjkkjjklllllllllwwlllllliiiiiiiiiiiilllllllkkkklllllllllllwllwlllllllllllll\n"
            "lllkkkjjjjkkklllwllllllllllliiiiiiiiiiiiilllllkjjkkjjkllllllllllllllllllllllllll\n"
            "llljjkkkkkkjjlllllllwlllllliiiiiiiiiiiillllllkkkjjjjkkklllllllllllllllllllllllll\n"
            "lllljjjjjjjjlllllllllliiiiiiiiiiiiiiillllllljjkkkkkkkkjjllllllllllllllllllllllll\n"
            "llllllljjllllllllllliiiiiiiiiiiiiillllllllllljjjjjjjjjjllllllllllllkklllllllllll\n"
            "llllllllllllliiiiiiiiiiiiiiiiillllllllwwwlllllllljjlllllllllllllllkkkkllllllllll\n"
            "lllwlllllliiiiiiiiiiiiiiilllllllllwwwwlllwllllwlllllllllllllllllkjjkkjjkllllllll\n"
            "lllllwwliiiiiiiiiiiiiiiikkkllllllllllwwlllwwwlllwwlllllllllllllkkkjjjjkkklllllll\n"
            "lllllllliiiiiiiiiiiiiiikkkkklllllwlllllwwwllllllllllllllllllllljjkkkkkkjjlllllll\n"
            "llllwllliiiiiiiiiiiiikjjkkkjjkllllllwllllllllllllllllllllllllllljjjjjjjjllllllll\n"
            "lllllllliiiiiiiiiiiikkkjjjjjkkklllllllllllllllllllllllllllllllllllljjlllllllllll\n"
            "lllwlllliiiiiiiiiiiijjkkkkkkkjjllllllllliiiiiiiiiiiillllllllllllllllllllllllllll\n"
            "llllllllliiiiiiiiiiiijjjjjjjjjlllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiilllllllllllllll\n"
            "lllwwllllliiiiiiiiiiiilljjjlllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiillllllllll\n"
            "lllllwllllliiiiiiiiiiiillllllliiiiiiiiiiiiiiiiiiiiikkiiiiiiiiiiiiiiiiiiiiiiiiiii\n"
            "llllwlllllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiilkkkklllliiiiiiiiiiiiiiiiiiiiii\n"
            "llllllllllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiillllkjjkkjjklliiiiiiiiiiiiiiiiiiiiii\n"
            "llllllkkklllllliiiiiiiiiiiiiiiiiiiiiiiiiiilllllkkkjjjjkkklllllllliiiiiiiiiiiiiii\n"
            "llllkkkkkjjlllllllliiiiiiiiiiiiiiiiiiillllwwllljjkkkkkkjjllllllllllllllllwwlllll\n"
            "llljjjjjjjjllllllllwwlllwlwllllllllllllllllllwlljjjjjjjjllllllllllwwllwlwlllllll\n"
            "lllllllllllllllllllllwlwllllwlwwwlllllllllllllllllljjlllllllllllllllwwllllllllll\n"
            "lllllllllllllllllllllllllllwlllllllllllllllllllllllllllllllllllllwllllllllllllll\n";

    std::string MAP_6 =
            "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n"
            "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n"
            "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n"
            "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n"
            "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhiiihhhiiihhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n"
            "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhGiiiiiGhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n"
            "hhhhhhhhhhhhhhhhhhllllllllllllllllllGGGGGllllllllllllllllllhhhhhhhhhhhhhhhhhhhhh\n"
            "hhhhhhhhhhhhhllllllllllllllllllllGGllGGGllGGllllllllllllllllllllllllhhhhhhhhhhhh\n"
            "hhhhhhhhhllllllllllllllllllllllllGGGGGGGGGGGllllllllllllllllllllllllllllhhhhhhhh\n"
            "hhhhllllllllllllllllGGlGGGlGGllllhhGGhhhGGhhllllGGlGGGlGGlllllllllllllllllllllll\n"
            "llllllllllllllllllllGGGGGGGGGllllhhhhhhhhhhhllllGGGGGGGGGlllllllllllllllllllllll\n"
            "llllllllllllllllllllhhGhhhGhhlllllhhGhhhGhhlllllhhGhhhGhhlllllllllllllllllllllll\n"
            "lllllllllllllllllllllhhhhhhhllllllhhhhhhhhhllllllhhhhhhhllllllllllllllllllllllll\n"
            "llllllllllllllllllllllhhGhhlllllllhhGhhhGhhlllllllhhGhhlhhlhhlhhlhhlhhllllllllll\n"
            "llllllllllllllllllllllhhhhhlllllllhhhhhhhhhlllllllhhhhhGhhhhhhhhhhhhhhllllllllll\n"
            "llllllllllllllllllllllhhGhhlllllllhhhGGGhhhlllllllhhGhhGhhhhhhhhhhhhhhllllllllll\n"
            "llllllllllllllllllllllhhhhhlllllllhhGGGGGhhlllllllhhhhhGhhhhhkkhhhhhhhllllllllll\n"
            "lllllllllllllllllllllhhhhhhhllllllhhGGGGGhhllllllhhhhhhhllllkkkkllllllllllllllll\n"
            "llllllkklllllllllllllllllllllllllllliiiiilllllllllllllllllkjjkkjjkllllllllllllll\n"
            "lllllkkkkllllllllllllllllllllllllliiiiiiillllllllllllllllkkkjjjjkkklllllllllllll\n"
            "lllkjjkkjjkllllllllllllllllllllllliiiiiillllllllllllllllljjkkkkkkjjlllllllllllll\n"
            "llkkkjjjjkkkllllllllllllllllllllllliiiiiiilllllllllllllllljjjjjjjjllllllllllllll\n"
            "lljjkkkkkkjjllllllllllllllllllllllliiiiiiillllllllllllllllllljjlllllllllllllllll\n"
            "llljjjjjjjjllllllllllllllllllllllliiiiiiilllllllllllllllllllllllllllllllllllllll\n"
            "lllllljjlllllllllllllllllllllllllliiiiiiiillllllllllllllllllllllllllllllllllllll\n";

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
