
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
            { // for entrances
                    'n', []() {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::DARK_BLUE)->build(), //dark
                                (new CharBuilder())->background(ColorPalette::ORANGE)->build(), //light
                                false
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
            { //planter
                    'o', []() {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::BLUE)->build(),
                                (new CharBuilder())->background(ColorPalette::TRUNK)->build(),
                                false
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
                                (new CharBuilder('_'))->background(ColorPalette::LIGHT_BLUE)->foreground(ColorPalette::DARK_BLUE)->build(),
                                (new CharBuilder('_'))->background(ColorPalette::PATH)->foreground(ColorPalette::DAY_GREEN)->build(),
                                false
                        );
                    }
            },
            { //planter
                    'p', [] () {
                        return new MapObject(
                                (new CharBuilder('_'))->background(ColorPalette::BLUE)->foreground(ColorPalette::DARK_BLUE)->build(),
                                (new CharBuilder('_'))->background(ColorPalette::TRUNK)->foreground(ColorPalette::PATH)->build(),
                                false
                                );
                    }
            },
            {
                    '|', [] () {
                        return new MapObject(
                                (new CharBuilder('|'))->background(ColorPalette::LIGHT_BLUE)->foreground(ColorPalette::DARK_BLUE)->build(),
                                (new CharBuilder('|'))->background(ColorPalette::PATH)->foreground(ColorPalette::DAY_GREEN)->build(),
                                false
                                );
                    }
            },
            {
                    '_', [] () {
                        return new MapObject(
                                (new CharBuilder('_'))->background(ColorPalette::LIGHT_BLUE)->foreground(ColorPalette::DARK_BLUE)->build(),
                                (new CharBuilder('_'))->background(ColorPalette::PATH)->foreground(ColorPalette::DAY_GREEN)->build(),
                                false
                                );
                    }
            },
            {
                    'g', [] () {
                        return new MapObject(
                                (new CharBuilder('\\'))->background(ColorPalette::DARK_BLUE)->foreground(ColorPalette::BLUE)->build(),
                                (new CharBuilder('\\'))->background(ColorPalette::ROOF)->foreground(ColorPalette::ORANGE)->build(),
                                true
                                );
                    }
            },
            {
                    '=', [] () {
                        return new MapObject(
                                (new CharBuilder('='))->background(ColorPalette::DARK_BLUE)->foreground(ColorPalette::BLUE)->build(),
                                (new CharBuilder('='))->background(ColorPalette::PATH)->foreground(ColorPalette::DAY_GREEN)->build(),
                                true
                                );
                    }
            },
            {
                    'm', [] () {
                        return new MapObject(
                                (new CharBuilder('/'))->background(ColorPalette::DARK_BLUE)->foreground(ColorPalette::BLUE)->build(),
                                (new CharBuilder('/'))->background(ColorPalette::ROOF)->foreground(ColorPalette::ORANGE)->build(),
                                true
                                );
                    }
            },
            {
                    'q', [] () {
                        return new MapObject(
                                (new CharBuilder())->background(ColorPalette::TRUNK_GREEN)->build(),
                                (new CharBuilder())->background(ColorPalette::TRUNK)->build(),
                                true
                                );
                    }
            },



    };

    std::string MAP_1 =
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllwwllllllllllllllG==Glllwllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "lllllllllwwllllhhhllGmm==ggGllllllllwwlllllllllkkllllllllllwwllllwwwllllllllllll\n"
            "lllllllllllllllhhhGmmmm==ggggGllllllllwlllllllkkkklllllllwllwwwwwlllllllwlllllll\n"
            "llllwllllllllllhhhmmmmm==ggggggGllllllllllllkjjkkjjkllllllwlllllwwwwwlllllllllll\n"
            "llllllllllllllGhhhmmmmm==ggggggggGlllllllllkkkjjjjkkklllllllllllllllllllllllllll\n"
            "llllllllllllGmmhhmmmmmGhhGgggggggggGllllllljjkkkkkkjjllllliiiiiiiiiiiiiiiillllll\n"
            "llllllllllllmmmmmmmmGhhhhhhGgggggggglllllllljjjjjjjjllliiiiiiiiiiiiiiiiiiiiiilll\n"
            "llllllllllllmmmmmmGhhhhhhhhhhGgggggglllllllllllqqlllliiiiiiiiiiiiiiiiiiiiiiiiiii\n"
            "llllllkkllllmmmmGhhhhhhhhhhhhhhGggggllpopoppplllllliiiiiiiiiiiiiiiiiiiiiiiiiiiii\n"
            "lllllkkkklllmmGhhhhhh_|__|_hhhhhhGggllopppopolllllliiiiiiiiiilllllllllllliiiiiii\n"
            "lllkjjkkjjklllhhhhhhhi|ii|ihhhhhhhllllopopppplllliiiiiiiiiilllllllwwwwllllllliii\n"
            "llkkkjjjjkkkllhhhhhhhhhhhhhhhhhhhhlllloopoopolllliiiiiiiiiilllllwwwkkwllllllllll\n"
            "lljjkkkkkkjjllh__|__hGGGGGGh__|__hllllppoppoplllliiiiiiiiiilllllllkkkkllllllllll\n"
            "llljjjjjjjjlllhii|iihGGGGGihii|iihllllllllllllllliiiiiiiiiilllllkjjkkjjkllllllll\n"
            "llllllqqllllllhhhhhhhGGGGGGhhhhhhhllllwwllllllliiiiiiiiiillllllkkkjjjjkkklllllll\n"
            "llllllwllllwlllllllliiiiiiiilllllllllwwlllwlllliiiiiiiiiilllllljjkkkkkkjjlllllll\n"
            "llllllllwwwwwwwllllliiiiiiiiillllllllllllllllliiiiiiiiiiillllllljjjjjjjjllllwlll\n"
            "llllllwlllwwlllllllllliiiiiiiiillllllllllllliiiiiiiiiiiiilllllwwlllqqlllllllllll\n"
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
            "llllllqqllllllllllwllliiiiiiiiiiiillwlljjkkkkkkjjllwwlllllllllllllllkkkkllllllll\n"
            "llllllllllkkkkjlllwllliiiiiiiiiiiilllllljjjjjjjjllllllllllllllllllkjjkkjjklllwll\n"
            "lllwllllkkkkkkkkjlllliiiiiiiiiiiiilwwllllllqqllllwllllkkkkkjlllllkkkjjjjkkklllll\n"
            "lllllljjjjjjjjjjjjlliiiiiiiiiiiiilllwlllllllllllllllkkkkkkjjjllljjjkkkkkjjjjllll\n"
            "lllwlllllllwlllllllliiiiiiiiiiiiillllllwlwlllllwllljjjjjjjjjjjlllljjjjjjjjllllll\n"
            "lllllllllllllllllllliiiiiiiiiiiiillllllllllllllllllllllllllllllllllllqqlllllllll\n";

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
            "hhhhhh~hhhhhhhilwwwllllliiiiiiiiiiiiiilllllkjjkkjjklllllwllllllllqqlllwwllllllll\n"
            "hhh~hhhhhhhhhhillllwwllllliiiiiiiiiiiiilllkkkjjjjkkklllllllwlllllwwlllkkkkllllll\n"
            "hhhhh~hhh~~hhhhhilllwllllliiiiiiiiiiiiiilljjkkkkkkjjllwllllkklllllllkkkkkjjjllll\n"
            "hhhhhhh~hhhhhhhhillllwwwllliiiiiiiiiiiiillljjjjjjjjlllllllkkkkllllljjjjjjjjjjlll\n"
            "hhh~~hhhhhhhhhhhilwwlllllllliiiiiiiiiiiiilllllqqllllllwlkjjkkjjkllllllllllllllll\n"
            "hhhhh~hhh~~hhhhhhiilwwwllwlliiiiiiiiiiiiillwwwwwlllwlllkkkjjjjkkklllwwlllwlwllll\n"
            "hhhhhhh~hhh~~hhhhiillllwwllliiiiiiiiiiiiillllllwwlllllljjkkkkkkjjllllwwwwlllllll\n"
            "hhh~~hhhh~hhhh~hhhhiillllliiiiiiiiiiiiiilllllllllllwwllljjjjjjjjllllwllllllwwlll\n"
            "hhhhhhhhhhhhhhhhhhhiillliiiiiiiiiiiiiillllwwllwllllllllllllqqlllllllllllllllllll\n";

    std::string MAP_4 =
            "hhhhhh~~hhhhhhhhhhhhillliiiiiiiiiiiiiillllllllllllllllllllllllllllllllllllllllll\n"
            "hhhhhhhh~hhh~hhhhhhhhilliiiiiiiiiiiiiilllllllwwwwlwlllllwwllllllllwwlllkkllwllll\n"
            "ihhhhhhhhhh~hhhh~hhhhilllliiiiiiiiiiiiiillllllllllllkklllllwllwlllllllkkkkllllll\n"
            "lihhh~~hhhhhhhhhhhhhhilllliiiiiiiiiiiiiiiiilwllwlllkkkkllllllwllllllkjjkkjjkllwl\n"
            "llihhhhhhh~~hhh~hhhhhiwllliiiiiiiiiiiiiiiiillllllkjjkkjjkllllllGGGGGGGGGjjkkklll\n"
            "llihhhhhhhhhh~hhhhhhhilllllliiiiiiiiiiiiiiiiiiilkkkjjjjkkkllGGjjjjjjjjjGGGkjllll\n"
            "lllihhhhhh~hhhhhhhhhhilwlllliiiiiiiiiiiiiiiiiiiljjkkkkkkjjGGjjjjjjjjjjjjjjGGllll\n"
            "lllihhhhhhh~hhh~~hhhhiillwwlllllkkiiiiiiiiiiiiilljjjjjjjjlGjjjjjjjjjjjjjjjjGGGll\n"
            "lllliihhhhhhh~hhhhhhhhhilllllllkkkkiiiiiiiiiiiiillllqqlGGGjjjjjjjjjjjjjjjjjjjGGl\n"
            "lllllihhhhhhhhhhhhhhhhhilllllkjjkkjjkiiiiiiiiiiillwlllGGjjjjjjjjjjnnnnjjjjjjjjGG\n"
            "lllwllihhh~~hhhh~hhhhhhhilwlkkkjjjjkkkiiiiiiiiiiillllGjjjjjjjjjjnnnnnnnnjjjjjjjj\n"
            "llwlllihhhhhh~hhhh~hhhhhillljjkkkkkkjjiiiiiiiiiiilllljjjjjjjjjnnnnnnnnnnnjjjjjjj\n"
            "llllkkkiiihhhhh~~hhhhhhhilllljjjjjjjjllliiiiiiiiilllljjkkkkjjnnnnnnnnnnnnnnjjjjj\n"
            "llkkjjjjkkiihhhhhh~hh~hhhillllllqqlllllliiiiiiiiillljkkkkkkkjnnnnnnnnnnnnnnjjjjj\n"
            "lkjjjjjjjjkkiGGGGGGGGGGGGGGlllwllllllliiiiiiiiiiilljjjjjkkkkkllwlllllllwllllllll\n"
            "lllllllllllGGGiiiiiiiiiiiiGGGllllliiiiiiiiiiiiiillwllllllwlwwllllwlllwwllwllllll\n"
            "lllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiilllllwlwwlllllwllllwllllkkllwlll\n"
            "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiillllllllllllllllllwllllkkkklllll\n"
            "iiiiiiiiiiiiiGGGGGGGGGGGGGGiiiiiiiiiiiiiiiilllllllkklllllwwwlllllllllkjjkkjjklll\n"
            "iiiiiiiiiiiGGGhh~~hhhhhhhiGGGlllllwlwlwwllwllllljkkkkjlllllwllllwlllkkkjjjjkkkll\n"
            "iiiikkillllllihhhh~hhhhhhilllllllllwlllllllllllkjjkkjjkllllllllllllljjkkkkkkjjll\n"
            "lllkkkklllllihhhhhhh~~hhhilllllwwllllllwllllllkkkjjjjkkkllwwllllllllljjjjjjjjlll\n"
            "lkjjkkjjklllihhhh~hhhhhhhhilllllllwlwllllllllljjkkkkkkjjlllllwllllllllllqqllllll\n"
            "kkkjjjjkkkihhh~hhh~hh~~hhhillllllllllwwllwllllljjjjjjjjlllwlllllllwllllllwwlllll\n"
            "lkkkkkkkklihhhhhh~~hhhhh~hilllllllllllllllllllllllqqlllllllllllwllllllllllllllll\n";

    std::string MAP_5 =
            "lllllllllllllllllllllllllllllliiiiiiiiiiillllllllllllllllllllllllllllliihhhhhhhh\n"
            "lllllllkkllllllwwwllwlwwlllllliiiiiiiiiiillllllllllllllllllwllllwwwwlllliihhhhhh\n"
            "llllllkkkkllllllllwllllwllllliiiiiiiiiiiillllllllkklllllllllwwwllllwwwwllliihhhh\n"
            "llllkjjkkjjklllllllllwwlllllliiiiiiiiiiiilllllllkkkklllllllllllwllwllllllllliihh\n"
            "lllkkkjjjjkkklllwllllllllllliiiiiiiiiiiiilllllkjjkkjjkllllllllllllllllllllllllih\n"
            "llljjkkkkkkjjlllllllwlllliiiiiiiiiikkiillllllkkkjjjjkkklllllllllllllllllllllllli\n"
            "lllljjjjjjjjlllllllliiiiiiiiiiiiiikkkklllllljjkkkkkkkkjjllllllllllllllllllllllli\n"
            "lllllllqqllllllliiiiiiiiiiiiiiiikjjkkjjkllllljjjjjjjjjjllllllllllllkklllllllllll\n"
            "llllllllllllliiiiiiiiiiiiiiiiilkkkjjjjkkkllllllllqqlllllllllllllllkkkkllllllllll\n"
            "lllwlllllliiiiiiiiiiiiiiilllllljjkkkkkkjjwllllwlllllllllllllllllkjjkkjjkllllllll\n"
            "lllllwwliiiiiiiiiiiiiiiikkkllllljjjjjjjjllwwwlllwwlllllllllllllkkkjjjjkkklllllll\n"
            "lllllllliiiiiiiiiiiiiiikkkkklllllwlqqllwwwlllllkkkklllllllllllljjkkkkkkjjlllllll\n"
            "klllwllliiiiiiiiiiiiikjjkkkjjkllllllwlllllllljjjkkkkkllllllllllljjjjjjjjllllllll\n"
            "jjkllllliiiiiiiiiiiikkkjjjjjkkkllllllllllllljjjjjjjkkjjllllllllllllqqlllllllllll\n"
            "jkkklllliiiiiiiiiiiijjkkkkkkkjjllllllllliiiiiiiiiiiillllllllllllllllllllllllllll\n"
            "kkjjllllliiiiiiiiiiiijjjjjjjjjlllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiilllllllllllllll\n"
            "jjjwwllllliiiiiiiiiiiillqqqlllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiillllllllll\n"
            "lllllwllllliiiiiiiiiiiillllllliiiiiiiiiiiiiiiiiiiiikkiiiiiiiiiiiiiiiiiiiiiiiiiii\n"
            "llllwlllllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiilkkkklllliiiiiiiiiiiiiiiiiiiiii\n"
            "llllllllllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiillllkjjkkjjklliiiiiiiiikkiiiiiiiiiii\n"
            "llllllkkklllllliiiiiiiiiiiiiiiiiiiiiiiiiiilllllkkkjjjjkkkllllllllikkkkiiiiiiiiii\n"
            "llllkkkkkjjlllllllliiiiiiiiiiiiiiiiiiillllwwllljjkkkkkkjjlllllllkjjkkjjklwwlllll\n"
            "llljjjkjjjjkklllkklwwlllwlwllllllllllllllllllwlljjjjjjjjlllllllkkkjjjjkkklllllll\n"
            "lllllllllllllllkkkkllwlwllllwlwwwllllkkllllllllllllqqlllllllllljjkkkkkkjjlllllll\n"
            "lllllllllllllkjjkkjjkllllllwllllllllkkkklllllllllllllllllllllllljjjjjjjjllllllll\n";

    std::string MAP_6 =
            "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n"
            "hh~hhhhhhh~hhhhhh~hhhhhhhhhh~hhh~h~hhhhh~hhhhhh~hhhhhhhhh~hhhhhhh~hhhhhhhhhhhhhh\n"
            "hhhhhhhhhhhhhhhhhhhh~hhhhhiiiiiiiiiiiiiiiiiiiihhhhhhhhhhhhhhhhhhhh~~hhhhhhhhhhhh\n"
            "hhhhhh~~hhhhhhhhhhhhhiiiiilllllllllllllllllllliihhhhhhhhhhh~~hhhhhhhhhhhhhhhhhhh\n"
            "hhhhhhhhhhhhhhhhhhhiillllllllllllliiillliiillllliihhh~hhhhhhhhhhhhhhhh~hhhhhhhhh\n"
            "hhh~hhhhhhhhhiiiiiillllwwllllllllllGiiiiiGlllllllliihhhhhhhhhhhhh~hhhhhhhhh~hhhh\n"
            "hhhhhhiiiiiiilllllllllllllwllwllllllGGGGGllllllllllliihhhh~hhhhhhhhhh~~hhhhhhhhh\n"
            "iiiiiillllllllllwllllwlllllllllllGGllGGGllGGlllwlllllihhhhhhhhhhhhhhhhhhhhhhhhhh\n"
            "kllllwlllwlllllllllllllllllllllllGGGGGGGGGGGlllllllllliiiiiihhhhhh~hhhhh~hhhhhhh\n"
            "kklllllwllllllkkllllGGlGGGlGGllllhhGGhhhGGhhllllGGlGGGlGGllliiiihhhhhhhhhhhhhhhh\n"
            "kjjklllllllllkkkklllGGGGGGGGGllllhhhhhhhhhhhllllGGGGGGGGGlllwlwliiiiikkhhh~~hhhh\n"
            "jjkkkllllllkjjkkjjklhhGhhhGhhlllllhhGhhhGhhlllllhhGhhhGhhllllllllwlwkkkkhhhhhhhh\n"
            "kkkjjlllllkkkjjjjkkklhhhhhhhllllllhhhhhhhhhllllllhhhhhhhlllllwllllkjjkkjjkhh~hhh\n"
            "jjjjlllhhlhhkhhkhhkhhlhhGhhlllllllhhGhhhGhhlllllllhhGhhlhhlhhlhhlhhjhhjjkkkhhhhh\n"
            "qllllllhhhhhhhhhhhhhhGhhhhhlllllllhhhhhhhhhlllllllhhhhhGhhhhhhhhhhhhhhkkkjlihhhh\n"
            "lllllllhhhhhhhhhhhhhhGhhGhhlllllllhhhnnnhhhlllllllhhGhhGhhhhhhhhhhhhhhjjjjlihh~h\n"
            "lllllllhhhhhhhhhhhhhhGhhhhhlllllllhhnnnnnhhlllllllhhhhhGhhhhhkkhhhhhhhqllllihhhh\n"
            "lllllllllllllllllllllhhhkkhhllllllhhnnnnnhhllllllhhhhhhhllllkkkkllllllllwllihhhh\n"
            "llllllkklllllllwwllllllkkkkllllllllliiiiilllllllllllllllllkjjkkjjklllllllllih~hh\n"
            "lllllkkkklllllllllwwlkjjkkjjkllllliiiiiiillllwlllwwwlllllkkkjjjjkkkllllllllihhhh\n"
            "lllkjjkkjjklllllllllkkkjjjjkkklllliiiiiillllllllwlllllllljjkkkkkkjjllllwlllihhhh\n"
            "llkkkjjjjkkkllllwllljjkkkkkkjjllllliiiiiiilllllllllllllllljjjjjjjjllllwwiiiihhhh\n"
            "lljjkkkkkkjjlllllllwwjjjjjjjjlllllliiiiiiillllkkklllllwllllllqqllllllliihhhhhhhh\n"
            "llljjjjjjjjlllllllllllllqqlwwllllliiiiiiillljjkkkkjlwwlllllllllllllwiihhhhhhhhhh\n"
            "llllllqqlllllllllllllllllllllllllliiiiiiiiljjjjjkjjjlllllllllllllllihhhhhhhhhhhh\n";

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
