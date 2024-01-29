
#include "GameCreator.h"
#include "console/CharFactory.h"
#include "palettes/ColorPalette.h"
#include "map/Enemy.h"
#include "map/ItemEntity.h"
#include "map/factory/EnemyFactory.h"
#include "map/factory/HealFactory.h"
#include "map/NPC.h"


Game *GameCreator::createNewGame() {
    Game* game = new Game({
        .map={.x=0,.y=0},
        .position={.x=24,.y=17}
    });
    game->m_torchesOrder = {
            new Torch(),
            new Torch(),
            new Torch(),
            new Torch(),
            new Torch(),
    };

    std::map<char, std::function<MapObject*()>> charMappings = {
            {
                    'a', []() {
                        return new MapObject(
                                (new CharFactory())->background(ColorPalette::DARK_BLUE)->create(), //dark
                                (new CharFactory())->background(ColorPalette::ORANGE)->create(), //light
                                true
                                );
                    }
            },
            { // for entrances
                    'n', []() {
                        return new MapObject(
                                (new CharFactory())->background(ColorPalette::DARK_BLUE)->create(), //dark
                                (new CharFactory())->background(ColorPalette::DARK_GREY)->create(), //light
                                false
                                );
                    }
            },
            { //water
                    'h', []() {
                        return new MapObject(
                                (new CharFactory())->background(ColorPalette::BLUE)->create(),
                                (new CharFactory())->background(ColorPalette::DAY_BLUE)->create(),
                                true
                                );
                    }
            },
            { //wall
                    'r', []() {
                        return new MapObject(
                                (new CharFactory())->background(ColorPalette::BLUE)->create(),
                                (new CharFactory())->background(ColorPalette::HOUSE)->create(),
                                true
                                );
                    }
            },
            { //planter
                    'o', []() {
                        return new MapObject(
                                (new CharFactory())->background(ColorPalette::BLUE)->create(),
                                (new CharFactory())->background(ColorPalette::TRUNK)->create(),
                                false
                                );
                    }
            },
            {
                    'i', []() {
                        return new MapObject(
                                (new CharFactory())->background(ColorPalette::LIGHT_BLUE)->create(),
                                (new CharFactory())->background(ColorPalette::PATH)->create(),
                                false
                                );
                    }
            },
            {
                    's', []() {
                        return new MapObject(
                                (new CharFactory())->background(ColorPalette::LIGHT_BLUE)->create(),
                                (new CharFactory())->background(ColorPalette::DAY_BLUE)->create(),
                                false
                                );
                    }
            },
            {
                    'j', []() {
                        return new MapObject(
                                (new CharFactory())->background(ColorPalette::DARK_GREEN)->create(),
                                (new CharFactory())->background(ColorPalette::GREEN)->create(),
                                true
                                );
                    }
            },
            {
                    'k', []() {
                        return new MapObject(
                                (new CharFactory())->background(ColorPalette::GREEN)->create(),
                                (new CharFactory())->background(ColorPalette::TREE_GREEN)->create(),
                                true
                                );
                    }
            },
            {
                    'l', [] () {
                        return new MapObject(
                                (new CharFactory())->background(ColorPalette::BG_COLOR)->create(),
                                (new CharFactory())->background(ColorPalette::DAY_GREEN)->create(),
                                false
                                );
                    }

            },
            {
                    'w', []() {
                        return new MapObject(
                                (new CharFactory('w'))->background(ColorPalette::BG_COLOR)->foreground(
                                        ColorPalette::BLUE)->create(),
                                (new CharFactory('w'))->background(ColorPalette::DAY_GREEN)->foreground(
                                        ColorPalette::GREEN)->create(),
                                false
                                );
                    }
            },
            {
                    '~', [] () {
                        return new MapObject(
                                (new CharFactory('~'))->background(ColorPalette::BLUE)->foreground(
                                                ColorPalette::LIGHT_BLUE)
                                        ->format(BLINKING)->create(),
                                (new CharFactory('~'))->background(ColorPalette::DAY_BLUE)->foreground(
                                                ColorPalette::LIGHT_BLUE)
                                        ->format(BLINKING)->create(),
                                true
                                );
                    }
            },
            {
                    'c', [] () {
                        return new MapObject(
                                (new CharFactory('"'))->background(ColorPalette::DAY_GREEN)->foreground(
                                                ColorPalette::CARROT)
                                        ->format(INVERTED)->format(BLINKING)->create(),
                                (new CharFactory('"'))->background(ColorPalette::CARROT)->foreground(
                                                ColorPalette::DAY_GREEN)
                                        ->format(BLINKING)->create(),
                                true
                                );
                    }
            },
            {
                    'd', [] () {
                        return new MapObject(
                                (new CharFactory('_'))->background(ColorPalette::LIGHT_BLUE)->foreground(
                                        ColorPalette::DARK_BLUE)->create(),
                                (new CharFactory('_'))->background(ColorPalette::TRUNK)->foreground(
                                        ColorPalette::BROWN)->create(),
                                false
                        );
                    }
            },
            { //planter
                    'p', [] () {
                        return new MapObject(
                                (new CharFactory('_'))->background(ColorPalette::BLUE)->foreground(
                                        ColorPalette::DARK_BLUE)->create(),
                                (new CharFactory('_'))->background(ColorPalette::TRUNK)->foreground(
                                        ColorPalette::ORANGE)->create(),
                                false
                                );
                    }
            },
            {
                    '|', [] () {
                        return new MapObject(
                                (new CharFactory('|'))->background(ColorPalette::LIGHT_BLUE)->foreground(
                                        ColorPalette::DARK_BLUE)->create(),
                                (new CharFactory('|'))->background(ColorPalette::DAY_BLUE)->foreground(
                                        ColorPalette::BLUE)->create(),
                                false
                                );
                    }
            },
            {
                    '_', [] () {
                        return new MapObject(
                                (new CharFactory('_'))->background(ColorPalette::LIGHT_BLUE)->foreground(
                                        ColorPalette::DARK_BLUE)->create(),
                                (new CharFactory('_'))->background(ColorPalette::DAY_BLUE)->foreground(
                                        ColorPalette::BLUE)->create(),
                                false
                                );
                    }
            },
            {
                    'g', [] () {
                        return new MapObject(
                                (new CharFactory('\\'))->background(ColorPalette::DARK_BLUE)->foreground(
                                        ColorPalette::BLUE)->create(),
                                (new CharFactory('\\'))->background(ColorPalette::ROOF)->foreground(
                                        ColorPalette::ORANGE)->create(),
                                true
                                );
                    }
            },
            {
                    '=', [] () {
                        return new MapObject(
                                (new CharFactory('='))->background(ColorPalette::DARK_BLUE)->foreground(
                                        ColorPalette::BLUE)->create(),
                                (new CharFactory('='))->background(ColorPalette::ROOF)->foreground(
                                        ColorPalette::ORANGE)->create(),
                                true
                                );
                    }
            },
            {
                    'm', [] () {
                        return new MapObject(
                                (new CharFactory('/'))->background(ColorPalette::DARK_BLUE)->foreground(
                                        ColorPalette::BLUE)->create(),
                                (new CharFactory('/'))->background(ColorPalette::ROOF)->foreground(
                                        ColorPalette::ORANGE)->create(),
                                true
                                );
                    }
            },
            {
                    'q', [] () {
                        return new MapObject(
                                (new CharFactory())->background(ColorPalette::TRUNK_GREEN)->create(),
                                (new CharFactory())->background(ColorPalette::TRUNK)->create(),
                                true
                                );
                    }
            },
            {
                    't', [] () {
                        return new MapObject(
                                (new CharFactory())->background(ColorPalette::DARK_GREEN)->create(),
                                (new CharFactory())->background(ColorPalette::LIGHT_GREY)->create(),
                                true
                                );
                    }
            },
            {
                    'u', [] () {
                        return new MapObject(
                                (new CharFactory())->background(ColorPalette::DARK_BLUE)->create(),
                                (new CharFactory())->background(ColorPalette::DARK_GREY)->create(),
                                true
                                );
                    }
            },
            {
                    'v', [] () {
                        return new MapObject(
                                (new CharFactory())->background(ColorPalette::DARK_BLUE)->create(),
                                (new CharFactory())->background(ColorPalette::BROWN)->create(),
                                true
                                );
                    }
            },
            {
                    'y', [] () {
                        return new MapObject(
                                (new CharFactory())->background(ColorPalette::LIGHT_BLUE)->create(),
                                (new CharFactory())->background(ColorPalette::LIGHT_GREY)->create(),
                                true
                                );
                    }
            },
            { //fire
                    'x', [] () {
                        return new MapObject(
                                (new CharFactory())->background(ColorPalette::BLUE)->create(),
                                (new CharFactory())->background(ColorPalette::YELLOW)->create(),
                                true
                                );
                    }
            },
            { //fire
                    'z', [] () {
                        return new MapObject(
                                (new CharFactory())->background(ColorPalette::BLUE)->create(),
                                (new CharFactory())->background(ColorPalette::ORANGE)->create(),
                                true
                                );
                    }
            },
            {//ghost NPCs
                    'A', [] () {
                        return new NPC('&', "Nooothing to see here, I am just a lowly ghooost... scared of the daark...");
                    }
            },
            {
                    'B', [] () {
                        return new NPC('&', "If ooonly somebooody cooould defeat that monster and light the toooorch");
                    }
            },
            {
                    'C', [] () {
                        return new NPC('&', "Ooooooo... It's been so loooong since we've seen light... Oooooooo");
                    }
            },
            { //dad NPC
                    'D', [] () {
                        return new NPC('D',"There you are, son! Another day in the darkness...");
                    }
            },
            {
                    'E', [] () {
                        return new NPC('&', "Ooooooo... They say that when yooou light all of the toooorches,\n"
                                            "   soooomething... happens...");
                    }
            },
            {
                    'F', [] () {
                        return new NPC('&', "Better be caaareful, the monsters get way strooonger past this poooint...");
                    }
            },
            {
                    'G', [] () {
                        return new NPC('&', "Maaaybe if you had a weapooon, you could defeeeaat all these mooonsters!");
                    }
            },
            {
                    'H', [] () {
                        return new NPC('&', "Sooometimes carrots are really hard to see, look carefully... Ooooo");
                    }
            },
            {
                    'I', [] () {
                        return new NPC('&', "Oooo there it is! The big tooorch can light the whooole wooorld!");
                }
            },
            {
                '0',[&game]() { return game->m_torchesOrder.at(0);},
            },
            {
                '1',[&game]() { return game->m_torchesOrder.at(1);},
            },
            {
                '2',[&game]() { return game->m_torchesOrder.at(2);},
            },
            {
                '3',[&game]() { return game->m_torchesOrder.at(3);},
            },
            {
                '4',[&game]() { return game->m_torchesOrder.at(4);},
            },



    };

    std::string MAP_1 =
            "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll\n"
            "llllllwwlllllllllllllla==alllwlllllllllllllllllllllllllllllllllllllllllwllllllll\n"
            "lllllllllwwllllrrrllamm==ggallllllllwwlllllllllkkllllllllllwwllllwwwllllllllllll\n"
            "lllllllllllllllrrrammmm==ggggallllllllwlllllllkkkkllllwwwwllwwllllllllllwlllllll\n"
            "llllwllllllllllrrrmmmmm==ggggggallllllllllllkjjkkjjkllllwlwlllllllllllwwwwwlllll\n"
            "llllllllllllllarrrmmmmm==ggggggggalllllllllkkkjjjjkkklllllllllllllllllllllllllll\n"
            "llllllllllllammrrmmmmmarragggggggggallllllljjkkkkkkjjllllliiiiiiiiiiiiiiiillllll\n"
            "llllllllllllmmmmmmmmarrrrrragggggggglllllllljjjjjjjjllliiiiiiiiiiiiiiiiiiiiiilll\n"
            "llllllllllllmmmmmmarrrrrrrrrragggggglllllllllllqqlllliiiiiiiiiiiiiiiiiiiiiiiiiii\n"
            "llllllkkllllmmmmarrrrrrrrrrrrrraggggllpopoppplllllliiiiiiiiiiiiiiiiiiiiiiiiiiiii\n"
            "lllllkkkklllmmarrrrrr_|__|_rrrrrraggllopppopolllllliiiiiiiiiilllllllllllliiiiiii\n"
            "lllkjjkkjjklllrrrrrrrs|ss|srrrrrrrllllopopppplllliiiiiiiiiilllllllwwwwllllllliii\n"
            "llkkkjjjjkkkllrrrrrrrrrrrrrrrrrrrrlllloopoopolDlliiiiiiiiiilllllwwwkkwllllllllll\n"
            "lljjkkkkkkjjllr__|__raaaaaar__|__rllllppoppoplllliiiiiiiiiilllllllkkkkllllllllll\n"
            "llljjjjjjjjlllrss|ssraaaaairss|ssrllllllllllllllliiiiiiiiiilllllkjjkkjjkllllllll\n"
            "llllllqqllllllrrrrrrraaaaaarrrrrrrllllwwllllllliiiiiiiiiillllllkkkjjjjkkklllllll\n"
            "llllllwllllwlllllllliiiiiiiilllllllllwwlllwlllliiiiiiiiiilllllljjkkkkkkjjlllllll\n"
            "llllllllwwwwwwwllllliiiiiiiiillllllllllllllllliiiiiiiiiiillllllljjjjjjjjllllwlll\n"
            "llllllwlllwwlllllllllliiiiiiiiillllllllllllliiiiiiHiiiiiilllllwwlllqqlllllllllll\n"
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
            "llllllllllwlllllllwlllllliiiiiiiiiiddddddddddddddd0ddhhhhhh~~hh~hhhhhhhhhhhlllll\n"
            "llllllwwlllllllllllllliiiiiiiiiiiiiddddddddddddddddddhhhhhhhhhhhhhhhhhhhhhhhhlll\n"
            "llllllllllllllllliiiiiiiiiiiiiiiiiiddddddddddddddddddhhhhhhhhh~hh~hhh~~hhhhhhlll\n"
            "iiiiiiiiiiiiiiiiiiiiiiiiiiiiilllllllhhh~~hh~hhhhhhhvvhhh~hh~hhhhhhhhhhhhhhhhllll\n"
            "iiiiiiiiiiiiiiiiiiiiBiiiiillllllllllhhhhhhh~~hh~hhhhh~hhhhhhh~hh~hhhhhh~hhhhllll\n"
            "iiiiiiAiiiiiiiiiiiiiiiiiiillllwlllllhhhhhhhhhhhhhh~hhhh~~hhhhhh~hhhh~hhhhhhhllll\n"
            "iiiiiiiiiiiiiiiiiiiiiiiiiiiillllllwlllllhhhhhh~hhhhhhhhhh~~hhhhhhh~hhhhhhhllllll\n"
            "llllllllliiiiiiiiiiiiiiiiiiiiillllllllllllllhhhhhhh~~hhhhhh~hhh~hhhhhhhhhlllwlll\n"
            "llllllkklllllllliiiiiiiiiiiiiiiillwllllllllllllllhhhhhh~~hhhh~hhhh~h~hhhhllwllll\n"
            "lllllkkkkllllwlllliiiiiiiiiiiiiilllwwllllllllllllllllhhhhh~~hh~hhhhhhhhhhlllllll\n"
            "lllkjjkkjjkllllllllliiiiiiiiiiiilllllllllllkkllllllllllllhhhhhhhhh~hhhhhllwllwll\n"
            "llkkkjjjjkkkllwwwwlliiiiiiiiiiiiilllllwlllkkkklllllwwlllllllhhhhhhhhhhlllllwllll\n"
            "lljjkkkkkkjjlllllllllliiiiiiiiiiiilwllllkjjkkjjkllllllwlllllllllllllllllllllllll\n"
            "llljjjjjjjjllllllllllliiiiiiiiiiiilllllkkkjjjjkkklllllllwwllllllwllllkklllwlllll\n"
            "illlllqqllllllllllwllliiiiiiiiiiiillwlljjkkkkkkjjllwwlllllllllllllllkkkkllllllll\n"
            "hiilllllllkkkkjlllwllliiiiiiiiiiiilllllljjjjjjjjllllllllllllllllllkjjkkjjklllwll\n"
            "hhhiilllkkkkkkkkjlllliiiiiiiiiiiiilwwllllllqqllllwllllkkkkkjlllllkkkjjjjkkklllll\n"
            "hh~hiijjjjjjjjjjjjlliiiiiiiiiiiiilllwlllllllllllllllkkkkkkjjjllljjjkkkkkjjjjllll\n"
            "h~hhhhiilllwlllllllliiiiiiiiiiiiillllllwlwlllllwllljjjjjjjjjjjlllljjjjjjjjllllll\n"
            "hhhhhhiilllllllllllliiiiiiiiiiiiillllllllllllllllllllllllllllllllllllqqlllllllll\n";

    std::string MAP_3 =
            "hh~hhhiilllllllllllliiiiiiiiiiiiilllllllllllllllllllllllllllllllllllllllllllllll\n"
            "h~hh~hkkkklllllllwwlliiiiiiiiiiiiiillllwllllwwwwwwllwllllllllllwwwllllllllwwllll\n"
            "hh~hkkkkkjjjlllwllllliiiiiiiiiiiiiillwwlllllllwlllllllwllllllwwwlllllwllllllllll\n"
            "hhijjjjjjjjjjlllllwlllliiiiiiiiiiiiillllllwwlllllwlllllllllllliiiiiiiiiiiiiiiiii\n"
            "hilllllllllwwwlllllllwlliiiCiiiiiiiilllwwwllwllliiiiiiiiiiiiiihhhhhhhhhhhhhhhhhh\n"
            "hilllwwwwlllllwwlllllllliiiiiiiiiiiilllllllliiiihhhhhhhhh~hhhhhhhh~~hhhhhhhhhhhh\n"
            "hhilllwlllwllllliiiiiiiaaiiiiiiiiiiaaiiiiiiihhhhh~~~hhh~hhhh~~h~hhhhh~hh~hhhhhhh\n"
            "hhiilliiiiiiiiiihhhhhhhaaiiiiiiiiiiaahhhhhhhhhhhhhh~hhhhh~~hhhhhhh~hhh~hhhh~hhhh\n"
            "hhhhiihhhhhhhhhhhhh~~hhaaiiiiiiiiiiaahhh~~h~~hhhhhh~hhh~hhhh~hhh~hhh~~hhhhhhhhhh\n"
            "hhhhhhhhh~~hhh~hhhhhhhhaaiiiiiiiiiiaahhhhhhhhhhhhhhhhhhhhhhhhhhhhh~hhhhhhh~hhhhh\n"
            "hhh~~hhhhhhhh~hhhh~hhhhaaiiiiiiiiiiaahhhhh~~hh~hhhh~~~~hhhh~~hhhhkk~hhhhhhhhhhhh\n"
            "hhhhh~~hh~hhhhhh~~hhhhhaaiiiiiiiiiiaahhhhhhh~~hhhhhhhh~hhhhhhhhhkkkkhhhhiiiiiiii\n"
            "h~hhhhhhhhhhhh~hhhhhhhhaaiiiiiiiiiiaahhhhhhhhhhhhhhhhhhhhiiiiikjjkkjjkiillllllll\n"
            "hhh~~hhh~hhh~~hhhhhhhhhaaiiiiiiiiiiaaiiiiiiiiiiiiiiiiiiiillllkkkjjjjkkkllllwllll\n"
            "hhhhh~~hhhhhhhhhhiiiiiiaaiiiiiiiiiiaalllwwllllkkllllllllllllljjkkkkkkjjllllwllll\n"
            "hhh~hhhh~hhhhhhilllllllliiiiiiiiiiiillllllwllkkkkllllwwwlllllljjjjjjjjlllwwwllll\n"
            "hhhhhh~hhhhhhhilwwwllllliiiiiiiiiiiiiilllllkjjkkjjklllllwllllllllqqlllwwllllllll\n"
            "hhh~hhhhhhhhhhillllwwllllliiiiiiiiiiiiilllkkkjjjjkkklllllllkkllllwwlllkkkkllllll\n"
            "hhhhh~hhh~~hhhhhilllwll1lliiiiiiiiiiiiiilljjkkkkkkjjllwlllkkkkllllllkkkkkjjjllll\n"
            "hhhhhhh~hhhhhhhhillllwwwllliiiiiiiiiiiiillljjjjjjjjlllllkjjkkjjkllljjjjjjjjjjlll\n"
            "hhh~~hhhhhhhhhhhilwwlllllllliiiiiiiiiiiiilllllqqllllllwkkkjjjjkkklllllllllllllll\n"
            "hhhhh~hhh~~hhhhhhiilwwwllwlliiiiiiiiiiiiillwwwwwlllwllljjkkkkkkjjlllwwlllwlwllll\n"
            "hhhhhhh~hhh~~hhhhiillllwwllliiiiiiiiiiiiillllllwwllllllljjjjjjjjlllllwwwwlllllll\n"
            "hhh~~hhhh~hhhh~hhhhiillllliiiiiiiiiiiiiilllllllllllwwllllllqqlllllllwllllllwwlll\n"
            "hhhhhhhhhhhhhhhhhhhiillliiiiiiiiiiiiiillllwwllwlllllllllllllllllllllllllllllllll\n";

    std::string MAP_4 =
            "hhhhhh~~hhhhhhhhhhhhillliiiiiiiiiiiiiillllllllllllllllllllllllllllllllllllllllll\n"
            "hhhhhhhh~hhh~hhhhhhhhilliiiiiiiiiiiiiilllllllwwwwlwlllllwwllllllllwwlllkkllwllll\n"
            "hhhhhhhhhhh~hhhh~hhhhilllliiiiiiiiiiiiiillllllllllllkklllllwllwlllllllkkkkllllll\n"
            "hhhhh~~hhhhhhhhhhhhhhilllliiiiiiiiiiiiiiiiilwllwlllkkkkllllllwllllllkjjkkjjkllwl\n"
            "hhhhhhhhhh~~hhh~hhhhhiwllliiiiiiiiiiiiiiiiillllllkjjkkjjkllllluuuuuuuuuujjkkklll\n"
            "hhhhhhhhhhhhh~hhhhhhhilllllliiiiiiiiiiiiiiiiiiilkkkjjjjkkklluutttttttttuuukjllll\n"
            "iihhhhhhhh~hhhhhhhhhhilwlllliiiiiiiiiiiiiiiiiiiljjkkkkkkjjuuttttttttttttttuullll\n"
            "lliihhhhhhh~hhh~~hhhhiillwwlllllkkiiiiiiiiiiiiilljjjjjjjjluttttttttttttttttuuull\n"
            "lllliihhhhhhh~hhhhhhhhhilllllllkkkkiiiiiiiiiiiiillllqqluuutttttttttttttttttttuul\n"
            "lllllihhhhhhhhhhhhhhhhhilllllkjjkkjjkiiiiiiiiiiillwllluutttttttttnnnnnttttttttuu\n"
            "lllwllihhh~~hhhh~hhhhhhhilwlkkkjjjjkkkiiiiiEiiiiilllluttttttttttnnnnnnnntttttttt\n"
            "llwlllihhhhhh~hhhh~hhhhhillljjkkkkkkjjiiiiiiiiiiilllutttttttttnnnnnnnnnnnttttttt\n"
            "llllkkkiiihhhhh~~hhhhhhhilllljjjjjjjjllliiiiiiiiillluttkkkkjtnnnnnn2nnnnnntttttt\n"
            "llkkjjjjkkiihhhhhh~hh~hhhillllllqqlllllliiiiiiiiillljkkkkkkkjnnnnnnnnnnnnntttttt\n"
            "lkjjjjjjjjkkiaaaaaaaaaaaaaalllwllllllliiiiiiiiiiilljjjjjkkkkkjlwlllllllwllllllll\n"
            "lllllllllllaaaiiiiiiiiiiiiaaallllliiiiiiiiiiiiiillwllllllwlwwllllwlllwwllwllllll\n"
            "lllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiilllllwlwwlllllwllllwllllkkllwlll\n"
            "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiFiiiiiiiiiiiiiillllllllllllllllllwllllkkkklllll\n"
            "iiiiiiiiiiiiiaaaaaaaaaaaaaaiiiiiiiiiiiiiiiilllllllkklllllwwwlllllllllkjjkkjjklll\n"
            "iiiiiiiiiiiaaahh~~hhhhhhhiaaalllllwlwlwwllwllllljkkkkjlllllwllllwlllkkkjjjjkkkll\n"
            "iiiikkillllllihhhh~hhhhhhilllllllllwlllllllllllkjjkkjjkllllllllllllljjkkkkkkjjll\n"
            "lllkkkklllllihhhhhhh~~hhhilllllwwllllllwllllllkkkjjjjkkkllwwllllllllljjjjjjjjlll\n"
            "lkjjkkjjklllihhhh~hhhhhhhhilllllllwlwllllllllljjkkkkkkjjlllllwllllllllllqqllllll\n"
            "kkkjjjjkkkihhh~hhh~hh~~hhhillllllllllwwllwllllljjjjjjjjlllwlllllllwllllllwwlllll\n"
            "lkkkkkkkklihhhhhh~~hhhhh~hilllllllllllllllllllllllqqlllllllllllwllllllllllllllll\n";

    std::string MAP_5 =
            "lllllllllllllllllllllllllllllliiiiiiiiiiillllllllllllllllllllllllllihhhhhhh~hhhh\n"
            "lllllllkkllllllwwwllwlwwlllllliiiiiiiiiiilwlwlwwlllllllllllwllllwwwliihh~~hh~hhh\n"
            "llllllkkkkllllllllwllllwllllliiiiiiiiiiiilllwllllkklllllllllwwwllllwwliihhh~hhhh\n"
            "llllkjjkkjjklllllllllwwlllllliiiiiiiiiiiilwlllllkkkklllllllllllwllwllllliiihhh~h\n"
            "lllkkkjjjjkkklllwllllllllllliiiiiiiiiiiiilllllkjjkkjjkllllllllllllllllllllliihhh\n"
            "llljjkkkkkkjjlllllllwlllliiiiiiiiiikkiillllllkkkjjjjkkklllllwwwlllllllwllllllihh\n"
            "lllljjjjjjjjlllllllliiiiiiiiiiiiiikkkklllllljjkkkkkkkkjjllwwllllllllllllllllllii\n"
            "lllllllqqllllllliiiiiiii3iiiiiiikjjkkjjkllllljjjjjjjjjjllllllllllllkklllwwllllll\n"
            "llllllllllllliiiiiiiiiiiiiiiiilkkkjjjjkkkllllllllqqllwwwlllwllllllkkkkllllwlllll\n"
            "lllwlllllliiiiiiiiiiiiiiilllllljjkkkkkkjjwllllwllllllllllwlllwllkjjkkjjkllllllll\n"
            "lllllwwliiiiiiiiiiiiiiiikkkllllljjjjjjjjllwwwlllkkkkllllwllllllkkkjjjjkkklllwlll\n"
            "lllllllliiiiiiiiiiiiiiikkkkklllllwlqqllwwwlllljjjkkkkkllllllllljjkkkkkkjjllwwlll\n"
            "klllwllliiiiiiiiiiiiikjjkkkjjkllllllwlllllllljjjjjjjjjjjlllllllljjjjjjjjlwllllll\n"
            "jjkllllliiiiiiiiiiiikkkjjjjjkkkllllllllllllllllllllllllllllllllllllqqlllllllwlll\n"
            "jkkklllliiiiiiiiiiiijjkkkkkkkjjllllllllliiiiiiiiiiiillllllllllllllllllllwwwlllll\n"
            "kkjjllllliiiiiiiiiiiijjjjjjjjjlllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiillllwllllllllll\n"
            "jjjwwllllliiiiiiiiiiiillqqqlllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiillllllllll\n"
            "lllllwllllliiiiiiiiiiiillllllliiiiiiiiiiiiiiiiiiiiikkiiiiiiiiiiiiiiiiiiiiiiiiiii\n"
            "llllwlllllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiilkkkklllliiiiiiiiiiiiiGiiiiiiii\n"
            "llllllllllllliiiiiiiiiiiiiiiiiiiiiiiiiiiiiiillllkjjkkjjklliiiiiiiiikkiiiiiiiiiii\n"
            "llllllkkklllllliiiiiiiiiiiiiiiiiiiiiiiiiiilllllkkkjjjjkkkllllllllikkkkiiiiiiiiii\n"
            "llllkkkkkjjlllllllliiiiiiiiiiiiiiiiiiillllwwllljjkkkkkkjjlllllllkjjkkjjklwwlllll\n"
            "llljjjkjjjjkklllkklwwlllwlwllllllllllllllllllwlljjjjjjjjlllllllkkkjjjjkkklllllll\n"
            "lllllllllllllllkkkkllwlwllllwlwwwllllkkllllllllllllqqlllllllllljjkkkkkkjjlllllll\n"
            "lllllllllllllkjjkkjjkllllllwllllllllkkkklllllllllllllllllllllllljjjjjjjjllllllll\n";

    std::string MAP_6 =
            "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhzhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n"
            "hh~hhhhhhh~hhhhhh~hhhhhhhhhh~hhh~h~hhhhx~hhhhhh~hhhhhhhhh~hhhhhhh~hhhhhhhhhhhhhh\n"
            "hhhhhhhhhhhhhhhhhhhh~hhhhhhhhhhhhhhhhxxhzhhhhhhhhhhhhhhhhhhhhhhhhh~~hhhhhhhhhhhh\n"
            "hhhhhh~~hhhhhhh~hhhhhhhhhhhhhhhhhhhhxxxxzhhhhhhhhhhhhhhhhhh~~hhhhhhhhhhhhhhhhhhh\n"
            "hhhhhhhhhhhhhhhhhhh~~hhh~~hhhhhhhhyyyxxzyyyhhhhhhhhhh~hhhhhhhhhhhhhhhh~hhhhhhhhh\n"
            "hhh~hhhhhhh~h~~hhhhhhhhhhhhhhhhhhhhuyyyyyuhhhhhh~~hhhhhhhhhhhhhhh~hhhhhhhhh~hhhh\n"
            "hhhhhhhhhhhhhhhhh~hhhhhhhhhhhhhhhhhhuuuuuhhhhhhhhhhhhhhhhh~hhhhhhhhhh~~hhhhhhhhh\n"
            "hhhhh~h~~hhhh~hhhhhhhhhhhhhhhhiiiuuiiuuuiiuuiiiiiiiiiiihhhhhhhhhhhhhhhhhhhhhhhhh\n"
            "kh~hhhhhhh~hhhhhhhhhhhiiiiiiiiilluuuuuuuuuuulllllllllliiiiiihhhhhh~hhhhh~hhhhhhh\n"
            "kkhhhhhhhhhhiikkiiiiuuiuuuluullllrruurrruurrlllluuluuuluullliiiihhhhhhhhhhhhhhhh\n"
            "kjjkiiiiiiiiikkkkllluuuuuuuuullllrrrrrrrrrrrlllluuuuuuuuulllwlwliiiiiiiihh~~hhhh\n"
            "jjkkkllllllkjjkkjjklrrurrrurrlllllrrurrrurrlllllrrurrrurrllllllllllllllliihhhhhh\n"
            "kkkjjlllllkkkjjjjkkklrrrrrrrllllllrrrrrrrrrllllllrrrrrrrlllllwllllllllllllih~hhh\n"
            "jjjjlllrrlrrkrrkrrkrrlrrurrlllllllrrurrrurrlllllllrrurrlrrlrrlrrlrrlrrlllllihhhh\n"
            "qllllllrrrrrrrrrrrrrrurrrrrlllllllrrrrrrrrrlllllllrrrrrurrrrrrrrrrrrrrlllllihhhh\n"
            "lllllllrrrrrrrrrrrrrrurrurrlllllllrrrnnnrrrlllllllrrurrurrrrrrrrrrrrrrlllllihh~h\n"
            "llllllkkrrrrrrrrrrrrrurrrrrlllllllrrnn4nnrrlllllllrrrrrurrrrrkkrrrrrrrlllllihhhh\n"
            "lllllkkkkllllllllllllrrrkkrrllllllrrnnnnnrrllllllrrrrrrrllllkkkkllllllllwllihhhh\n"
            "lllkjjkkjjkllllwwllllllkkkkllllllllliiiiilllllllllllllllllkjjkkjjklllllllllih~hh\n"
            "llkkkjjjjkkkllllllwwlkjjkkjjkllllliiiiiiillllwlllwwwlllllkkkjjjjkkkllllllllihhhh\n"
            "lljjkkkkkkjjllllllllkkkjjjjkkklllliiiiiillllllllwlllllllljjkkkkkkjjllllwlllihhhh\n"
            "llljjjjjjjjlllllwllljjkkkkkkjjllllliiiiiiillllkkkllllllllljjjjjjjjllllwwiiiihhhh\n"
            "llllllqqlllllllllllwwjjjjjjjjlllllliiiiIiillljkkkkkkllwllllllqqllllllliihhhhhhhh\n"
            "llllllllllllllllllllllllqqlwwllllliiiiiiillljjjjjjjjjjlllllllllllllwiihhhhhhhhhh\n"
            "lllllllllllllllllllllllllllllllllliiiiiiiilllllllllllllllllllllllllihhhhhhhhhhhh\n";

    EnemyFactory* enemyFactory = new EnemyFactory();
    HealFactory* healFactory = new HealFactory();

    std::string EMPTY_MAP;
    game->m_mapMatrix = {
            {
                new Map(MAP_1, charMappings, { //x sloupce, y radky
                    enemyFactory->createEnemy({.x=65,.y=7}, EASY),

                    healFactory->createHeal({.x=39, .y=12}, VISIBLE),
                    healFactory->createHeal({.x=42, .y=9}, VISIBLE),
                    healFactory->createHeal({.x=41, .y=11}, VISIBLE),
                    healFactory->createHeal({.x=44, .y=10}, VISIBLE),
                    healFactory->createHeal({.x=40, .y=10}, VISIBLE),
                    healFactory->createHeal({.x=43, .y=13}, VISIBLE),
                    healFactory->createHeal({.x=8, .y=5}, INVISIBLE),
                    healFactory->createHeal({.x=9, .y=5}, INVISIBLE),
                    healFactory->createHeal({.x=60, .y=15}, INVISIBLE),
                    healFactory->createHeal({.x=6, .y=18}, INVISIBLE),
                    healFactory->createHeal({.x=7, .y=18}, INVISIBLE),
                    healFactory->createHeal({.x=9, .y=18}, INVISIBLE),

                }),
                new Map(MAP_2, charMappings,{
//                    enemyFactory->createEnemy({.x=33, .y=5}, EASY),
                    enemyFactory->createEnemy({.x=27, .y=19}, EASY),
                    enemyFactory->createEnemy({.x=33, .y=5}, ATTACK, nullptr, new PlayerAttack("Pounce", 15)),
                    enemyFactory->createEnemy({.x=60, .y=19}, ARMED, new Weapon("Light Axe", 10,(new CharFactory('P'))
                    ->foreground(ColorPalette::FG_PLAYER)->background(ColorPalette::NPC_PINK)->create())),

                    healFactory->createHeal({.x=55, .y=18}, VISIBLE),
                    healFactory->createHeal({.x=14, .y=15}, VISIBLE),
                    healFactory->createHeal({.x=21, .y=4}, VISIBLE),
                    healFactory->createHeal({.x=23, .y=2}, VISIBLE),
                    healFactory->createHeal({.x=47, .y=5}, VISIBLE),
                    healFactory->createHeal({.x=33, .y=10}, MAGIC),
                    healFactory->createHeal({.x=20, .y=2}, INVISIBLE),
                    healFactory->createHeal({.x=21, .y=2}, INVISIBLE),
                    healFactory->createHeal({.x=75, .y=3}, INVISIBLE),
                    healFactory->createHeal({.x=12, .y=24}, INVISIBLE),
                    healFactory->createHeal({.x=13, .y=24}, INVISIBLE),

                })
            },
            {
                new Map(MAP_6, charMappings,{
                    enemyFactory->createEnemy({.x=38, .y=17}, HARD),
                    enemyFactory->createEnemy({.x=39, .y=16}, HARD),
                    enemyFactory->createEnemy({.x=37, .y=16}, HARD),
                    enemyFactory->createEnemy({.x=37, .y=21}, ATTACK, nullptr, new PlayerAttack("DESTROY", 25)),
                    enemyFactory->createEnemy({.x=38, .y=15}, MEDIUM),
                    enemyFactory->createEnemy({.x=38, .y=19}, MEDIUM),


                    healFactory->createHeal({.x=46, .y=15}, VISIBLE),
                    healFactory->createHeal({.x=56, .y=22}, VISIBLE),
                    healFactory->createHeal({.x=65, .y=23}, VISIBLE),
                    healFactory->createHeal({.x=53, .y=19}, VISIBLE),
                    healFactory->createHeal({.x=18, .y=18}, VISIBLE),
                    healFactory->createHeal({.x=20, .y=23}, MAGIC),
                    healFactory->createHeal({.x=4, .y=15}, INVISIBLE),
                    healFactory->createHeal({.x=34, .y=10}, INVISIBLE),
                    healFactory->createHeal({.x=47, .y=12}, INVISIBLE),

                }),
                new Map(MAP_3, charMappings,{
                    enemyFactory->createEnemy({.x=32, .y=14}, EASY),
                    enemyFactory->createEnemy({.x=28, .y=14}, MEDIUM),
                    enemyFactory->createEnemy({.x=30, .y=15}, ARMED, new Weapon("Sickle of Light", 15,(new CharFactory('?'))
                            ->foreground(ColorPalette::FG_PLAYER)->background(ColorPalette::NPC_PINK)->create())),

                    healFactory->createHeal({.x=45, .y=3}, VISIBLE),
                    healFactory->createHeal({.x=67, .y=21}, VISIBLE),
                    healFactory->createHeal({.x=69, .y=23}, VISIBLE),
                    healFactory->createHeal({.x=4, .y=5}, VISIBLE),
                    healFactory->createHeal({.x=30, .y=17}, VISIBLE),
                    healFactory->createHeal({.x=74, .y=2}, INVISIBLE),
                    healFactory->createHeal({.x=8, .y=5}, INVISIBLE),
                    healFactory->createHeal({.x=60, .y=20}, INVISIBLE),
                    healFactory->createHeal({.x=61, .y=21}, INVISIBLE),

                })
            },
            {
                new Map(MAP_5, charMappings,{
                    enemyFactory->createEnemy({.x=16, .y=14}, HARD),
                    enemyFactory->createEnemy({.x=33, .y=3}, MEDIUM),
                    enemyFactory->createEnemy({.x=34, .y=17}, MEDIUM),
                    enemyFactory->createEnemy({.x=13, .y=10}, HARD),
                    enemyFactory->createEnemy({.x=67, .y=17}, ARMED, new Weapon("Lightsaber", 25,(new CharFactory('!'))
                            ->foreground(ColorPalette::FG_PLAYER)->background(ColorPalette::NPC_PINK)->create())),


                    healFactory->createHeal({.x=57, .y=5}, VISIBLE),
                    healFactory->createHeal({.x=70, .y=14}, VISIBLE),
                    healFactory->createHeal({.x=40, .y=12}, VISIBLE),
                    healFactory->createHeal({.x=41, .y=17}, VISIBLE),
                    healFactory->createHeal({.x=20, .y=4}, VISIBLE),
                    healFactory->createHeal({.x=20, .y=20}, VISIBLE),
                    healFactory->createHeal({.x=25, .y=28}, VISIBLE),
                    healFactory->createHeal({.x=45, .y=16}, VISIBLE),
                    healFactory->createHeal({.x=4, .y=10}, INVISIBLE),
                    healFactory->createHeal({.x=60, .y=12}, INVISIBLE),
                    healFactory->createHeal({.x=30, .y=20}, INVISIBLE),

                }),
                new Map(MAP_4, charMappings,{
                    enemyFactory->createEnemy({.x=67, .y=13}, MEDIUM),
//                    enemyFactory->createEnemy({.x=69, .y=12}, MEDIUM),
                    enemyFactory->createEnemy({.x=65, .y=12}, MEDIUM),
                    enemyFactory->createEnemy({.x=67, .y=11}, ARMED, new Weapon("Glowing Bow", 20,(new CharFactory('{'))
                    ->foreground(ColorPalette::FG_PLAYER)->background(ColorPalette::NPC_PINK)->create())),
                    enemyFactory->createEnemy({.x=69, .y=12}, ATTACK, nullptr, new PlayerAttack("Charge", 20)),

                    healFactory->createHeal({.x=58, .y=3}, VISIBLE),
                    healFactory->createHeal({.x=44, .y=23}, MAGIC),
                    healFactory->createHeal({.x=65, .y=23}, VISIBLE),
                    healFactory->createHeal({.x=59, .y=21}, VISIBLE),
                    healFactory->createHeal({.x=32, .y=21}, VISIBLE),
                    healFactory->createHeal({.x=2, .y=9}, VISIBLE),
                    healFactory->createHeal({.x=64, .y=16}, VISIBLE),
                    healFactory->createHeal({.x=50, .y=2}, INVISIBLE),
                    healFactory->createHeal({.x=35, .y=15}, INVISIBLE),
                    healFactory->createHeal({.x=60, .y=20}, INVISIBLE),

                })
            }
    };
    delete healFactory;
    delete enemyFactory;
    return game;
}


