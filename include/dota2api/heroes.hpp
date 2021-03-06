#ifndef HEROES_HPP_GENERATED
#define HEROES_HPP_GENERATED

#include <map>

namespace dota2
{
    enum class Hero
    {
        Unknown             = 0,
        Anti_Mage           = 1,
        Axe                 = 2,
        Bane                = 3,
        Bloodseeker         = 4,
        Crystal_Maiden      = 5,
        Drow_Ranger         = 6,
        Earthshaker         = 7,
        Juggernaut          = 8,
        Mirana              = 9,
        Morphling           = 10,
        Shadow_Fiend        = 11,
        Phantom_Lancer      = 12,
        Puck                = 13,
        Pudge               = 14,
        Razor               = 15,
        Sand_King           = 16,
        Storm_Spirit        = 17,
        Sven                = 18,
        Tiny                = 19,
        Vengeful_Spirit     = 20,
        Windranger          = 21,
        Zeus                = 22,
        Kunkka              = 23,
        Lina                = 25,
        Lion                = 26,
        Shadow_Shaman       = 27,
        Slardar             = 28,
        Tidehunter          = 29,
        Witch_Doctor        = 30,
        Lich                = 31,
        Riki                = 32,
        Enigma              = 33,
        Tinker              = 34,
        Sniper              = 35,
        Necrophos           = 36,
        Warlock             = 37,
        Beastmaster         = 38,
        Queen_of_Pain       = 39,
        Venomancer          = 40,
        Faceless_Void       = 41,
        Wraith_King         = 42,
        Death_Prophet       = 43,
        Phantom_Assassin    = 44,
        Pugna               = 45,
        Templar_Assassin    = 46,
        Viper               = 47,
        Luna                = 48,
        Dragon_Knight       = 49,
        Dazzle              = 50,
        Clockwerk           = 51,
        Leshrac             = 52,
        Natures_Prophet     = 53,
        Lifestealer         = 54,
        Dark_Seer           = 55,
        Clinkz              = 56,
        Omniknight          = 57,
        Enchantress         = 58,
        Huskar              = 59,
        Night_Stalker       = 60,
        Broodmother         = 61,
        Bounty_Hunter       = 62,
        Weaver              = 63,
        Jakiro              = 64,
        Batrider            = 65,
        Chen                = 66,
        Spectre             = 67,
        Ancient_Apparition  = 68,
        Doom                = 69,
        Ursa                = 70,
        Spirit_Breaker      = 71,
        Gyrocopter          = 72,
        Alchemist           = 73,
        Invoker             = 74,
        Silencer            = 75,
        Outworld_Devourer   = 76,
        Lycan               = 77,
        Brewmaster          = 78,
        Shadow_Demon        = 79,
        Lone_Druid          = 80,
        Chaos_Knight        = 81,
        Meepo               = 82,
        Treant_Protector    = 83,
        Ogre_Magi           = 84,
        Undying             = 85,
        Rubick              = 86,
        Disruptor           = 87,
        Nyx_Assassin        = 88,
        Naga_Siren          = 89,
        Keeper_of_the_Light = 90,
        Io                  = 91,
        Visage              = 92,
        Slark               = 93,
        Medusa              = 94,
        Troll_Warlord       = 95,
        Centaur_Warrunner   = 96,
        Magnus              = 97,
        Timbersaw           = 98,
        Bristleback         = 99,
        Tusk                = 100,
        Skywrath_Mage       = 101,
        Abaddon             = 102,
        Elder_Titan         = 103,
        Legion_Commander    = 104,
        Techies             = 105,
        Ember_Spirit        = 106,
        Earth_Spirit        = 107,
        Terrorblade         = 109,
        Phoenix             = 110,
        Oracle              = 111,
        Winter_Wyvern       = 112,
        Arc_Warden          = 113,
    };

    const std::map<int, Hero> heroes({
        {(int)Hero::Unknown, Hero::Unknown},
        {(int)Hero::Anti_Mage, Hero::Anti_Mage},
        {(int)Hero::Axe, Hero::Axe},
        {(int)Hero::Bane, Hero::Bane},
        {(int)Hero::Bloodseeker, Hero::Bloodseeker},
        {(int)Hero::Crystal_Maiden, Hero::Crystal_Maiden},
        {(int)Hero::Drow_Ranger, Hero::Drow_Ranger},
        {(int)Hero::Earthshaker, Hero::Earthshaker},
        {(int)Hero::Juggernaut, Hero::Juggernaut},
        {(int)Hero::Mirana, Hero::Mirana},
        {(int)Hero::Morphling, Hero::Morphling},
        {(int)Hero::Shadow_Fiend, Hero::Shadow_Fiend},
        {(int)Hero::Phantom_Lancer, Hero::Phantom_Lancer},
        {(int)Hero::Puck, Hero::Puck},
        {(int)Hero::Pudge, Hero::Pudge},
        {(int)Hero::Razor, Hero::Razor},
        {(int)Hero::Sand_King, Hero::Sand_King},
        {(int)Hero::Storm_Spirit, Hero::Storm_Spirit},
        {(int)Hero::Sven, Hero::Sven},
        {(int)Hero::Tiny, Hero::Tiny},
        {(int)Hero::Vengeful_Spirit, Hero::Vengeful_Spirit},
        {(int)Hero::Windranger, Hero::Windranger},
        {(int)Hero::Zeus, Hero::Zeus},
        {(int)Hero::Kunkka, Hero::Kunkka},
        {(int)Hero::Lina, Hero::Lina},
        {(int)Hero::Lion, Hero::Lion},
        {(int)Hero::Shadow_Shaman, Hero::Shadow_Shaman},
        {(int)Hero::Slardar, Hero::Slardar},
        {(int)Hero::Tidehunter, Hero::Tidehunter},
        {(int)Hero::Witch_Doctor, Hero::Witch_Doctor},
        {(int)Hero::Lich, Hero::Lich},
        {(int)Hero::Riki, Hero::Riki},
        {(int)Hero::Enigma, Hero::Enigma},
        {(int)Hero::Tinker, Hero::Tinker},
        {(int)Hero::Sniper, Hero::Sniper},
        {(int)Hero::Necrophos, Hero::Necrophos},
        {(int)Hero::Warlock, Hero::Warlock},
        {(int)Hero::Beastmaster, Hero::Beastmaster},
        {(int)Hero::Queen_of_Pain, Hero::Queen_of_Pain},
        {(int)Hero::Venomancer, Hero::Venomancer},
        {(int)Hero::Faceless_Void, Hero::Faceless_Void},
        {(int)Hero::Wraith_King, Hero::Wraith_King},
        {(int)Hero::Death_Prophet, Hero::Death_Prophet},
        {(int)Hero::Phantom_Assassin, Hero::Phantom_Assassin},
        {(int)Hero::Pugna, Hero::Pugna},
        {(int)Hero::Templar_Assassin, Hero::Templar_Assassin},
        {(int)Hero::Viper, Hero::Viper},
        {(int)Hero::Luna, Hero::Luna},
        {(int)Hero::Dragon_Knight, Hero::Dragon_Knight},
        {(int)Hero::Dazzle, Hero::Dazzle},
        {(int)Hero::Clockwerk, Hero::Clockwerk},
        {(int)Hero::Leshrac, Hero::Leshrac},
        {(int)Hero::Natures_Prophet, Hero::Natures_Prophet},
        {(int)Hero::Lifestealer, Hero::Lifestealer},
        {(int)Hero::Dark_Seer, Hero::Dark_Seer},
        {(int)Hero::Clinkz, Hero::Clinkz},
        {(int)Hero::Omniknight, Hero::Omniknight},
        {(int)Hero::Enchantress, Hero::Enchantress},
        {(int)Hero::Huskar, Hero::Huskar},
        {(int)Hero::Night_Stalker, Hero::Night_Stalker},
        {(int)Hero::Broodmother, Hero::Broodmother},
        {(int)Hero::Bounty_Hunter, Hero::Bounty_Hunter},
        {(int)Hero::Weaver, Hero::Weaver},
        {(int)Hero::Jakiro, Hero::Jakiro},
        {(int)Hero::Batrider, Hero::Batrider},
        {(int)Hero::Chen, Hero::Chen},
        {(int)Hero::Spectre, Hero::Spectre},
        {(int)Hero::Ancient_Apparition, Hero::Ancient_Apparition},
        {(int)Hero::Doom, Hero::Doom},
        {(int)Hero::Ursa, Hero::Ursa},
        {(int)Hero::Spirit_Breaker, Hero::Spirit_Breaker},
        {(int)Hero::Gyrocopter, Hero::Gyrocopter},
        {(int)Hero::Alchemist, Hero::Alchemist},
        {(int)Hero::Invoker, Hero::Invoker},
        {(int)Hero::Silencer, Hero::Silencer},
        {(int)Hero::Outworld_Devourer, Hero::Outworld_Devourer},
        {(int)Hero::Lycan, Hero::Lycan},
        {(int)Hero::Brewmaster, Hero::Brewmaster},
        {(int)Hero::Shadow_Demon, Hero::Shadow_Demon},
        {(int)Hero::Lone_Druid, Hero::Lone_Druid},
        {(int)Hero::Chaos_Knight, Hero::Chaos_Knight},
        {(int)Hero::Meepo, Hero::Meepo},
        {(int)Hero::Treant_Protector, Hero::Treant_Protector},
        {(int)Hero::Ogre_Magi, Hero::Ogre_Magi},
        {(int)Hero::Undying, Hero::Undying},
        {(int)Hero::Rubick, Hero::Rubick},
        {(int)Hero::Disruptor, Hero::Disruptor},
        {(int)Hero::Nyx_Assassin, Hero::Nyx_Assassin},
        {(int)Hero::Naga_Siren, Hero::Naga_Siren},
        {(int)Hero::Keeper_of_the_Light, Hero::Keeper_of_the_Light},
        {(int)Hero::Io, Hero::Io},
        {(int)Hero::Visage, Hero::Visage},
        {(int)Hero::Slark, Hero::Slark},
        {(int)Hero::Medusa, Hero::Medusa},
        {(int)Hero::Troll_Warlord, Hero::Troll_Warlord},
        {(int)Hero::Centaur_Warrunner, Hero::Centaur_Warrunner},
        {(int)Hero::Magnus, Hero::Magnus},
        {(int)Hero::Timbersaw, Hero::Timbersaw},
        {(int)Hero::Bristleback, Hero::Bristleback},
        {(int)Hero::Tusk, Hero::Tusk},
        {(int)Hero::Skywrath_Mage, Hero::Skywrath_Mage},
        {(int)Hero::Abaddon, Hero::Abaddon},
        {(int)Hero::Elder_Titan, Hero::Elder_Titan},
        {(int)Hero::Legion_Commander, Hero::Legion_Commander},
        {(int)Hero::Techies, Hero::Techies},
        {(int)Hero::Ember_Spirit, Hero::Ember_Spirit},
        {(int)Hero::Earth_Spirit, Hero::Earth_Spirit},
        {(int)Hero::Terrorblade, Hero::Terrorblade},
        {(int)Hero::Phoenix, Hero::Phoenix},
        {(int)Hero::Oracle, Hero::Oracle},
        {(int)Hero::Winter_Wyvern, Hero::Winter_Wyvern},
        {(int)Hero::Arc_Warden, Hero::Arc_Warden},
    });
    const std::map<Hero, std::string> heroNames({
        {Hero::Unknown, "Unknown"},
        {Hero::Anti_Mage, "Anti-Mage"},
        {Hero::Axe, "Axe"},
        {Hero::Bane, "Bane"},
        {Hero::Bloodseeker, "Bloodseeker"},
        {Hero::Crystal_Maiden, "Crystal Maiden"},
        {Hero::Drow_Ranger, "Drow Ranger"},
        {Hero::Earthshaker, "Earthshaker"},
        {Hero::Juggernaut, "Juggernaut"},
        {Hero::Mirana, "Mirana"},
        {Hero::Morphling, "Morphling"},
        {Hero::Shadow_Fiend, "Shadow Fiend"},
        {Hero::Phantom_Lancer, "Phantom Lancer"},
        {Hero::Puck, "Puck"},
        {Hero::Pudge, "Pudge"},
        {Hero::Razor, "Razor"},
        {Hero::Sand_King, "Sand King"},
        {Hero::Storm_Spirit, "Storm Spirit"},
        {Hero::Sven, "Sven"},
        {Hero::Tiny, "Tiny"},
        {Hero::Vengeful_Spirit, "Vengeful Spirit"},
        {Hero::Windranger, "Windranger"},
        {Hero::Zeus, "Zeus"},
        {Hero::Kunkka, "Kunkka"},
        {Hero::Lina, "Lina"},
        {Hero::Lion, "Lion"},
        {Hero::Shadow_Shaman, "Shadow Shaman"},
        {Hero::Slardar, "Slardar"},
        {Hero::Tidehunter, "Tidehunter"},
        {Hero::Witch_Doctor, "Witch Doctor"},
        {Hero::Lich, "Lich"},
        {Hero::Riki, "Riki"},
        {Hero::Enigma, "Enigma"},
        {Hero::Tinker, "Tinker"},
        {Hero::Sniper, "Sniper"},
        {Hero::Necrophos, "Necrophos"},
        {Hero::Warlock, "Warlock"},
        {Hero::Beastmaster, "Beastmaster"},
        {Hero::Queen_of_Pain, "Queen of Pain"},
        {Hero::Venomancer, "Venomancer"},
        {Hero::Faceless_Void, "Faceless Void"},
        {Hero::Wraith_King, "Wraith King"},
        {Hero::Death_Prophet, "Death Prophet"},
        {Hero::Phantom_Assassin, "Phantom Assassin"},
        {Hero::Pugna, "Pugna"},
        {Hero::Templar_Assassin, "Templar Assassin"},
        {Hero::Viper, "Viper"},
        {Hero::Luna, "Luna"},
        {Hero::Dragon_Knight, "Dragon Knight"},
        {Hero::Dazzle, "Dazzle"},
        {Hero::Clockwerk, "Clockwerk"},
        {Hero::Leshrac, "Leshrac"},
        {Hero::Natures_Prophet, "Nature's Prophet"},
        {Hero::Lifestealer, "Lifestealer"},
        {Hero::Dark_Seer, "Dark Seer"},
        {Hero::Clinkz, "Clinkz"},
        {Hero::Omniknight, "Omniknight"},
        {Hero::Enchantress, "Enchantress"},
        {Hero::Huskar, "Huskar"},
        {Hero::Night_Stalker, "Night Stalker"},
        {Hero::Broodmother, "Broodmother"},
        {Hero::Bounty_Hunter, "Bounty Hunter"},
        {Hero::Weaver, "Weaver"},
        {Hero::Jakiro, "Jakiro"},
        {Hero::Batrider, "Batrider"},
        {Hero::Chen, "Chen"},
        {Hero::Spectre, "Spectre"},
        {Hero::Ancient_Apparition, "Ancient Apparition"},
        {Hero::Doom, "Doom"},
        {Hero::Ursa, "Ursa"},
        {Hero::Spirit_Breaker, "Spirit Breaker"},
        {Hero::Gyrocopter, "Gyrocopter"},
        {Hero::Alchemist, "Alchemist"},
        {Hero::Invoker, "Invoker"},
        {Hero::Silencer, "Silencer"},
        {Hero::Outworld_Devourer, "Outworld Devourer"},
        {Hero::Lycan, "Lycan"},
        {Hero::Brewmaster, "Brewmaster"},
        {Hero::Shadow_Demon, "Shadow Demon"},
        {Hero::Lone_Druid, "Lone Druid"},
        {Hero::Chaos_Knight, "Chaos Knight"},
        {Hero::Meepo, "Meepo"},
        {Hero::Treant_Protector, "Treant Protector"},
        {Hero::Ogre_Magi, "Ogre Magi"},
        {Hero::Undying, "Undying"},
        {Hero::Rubick, "Rubick"},
        {Hero::Disruptor, "Disruptor"},
        {Hero::Nyx_Assassin, "Nyx Assassin"},
        {Hero::Naga_Siren, "Naga Siren"},
        {Hero::Keeper_of_the_Light, "Keeper of the Light"},
        {Hero::Io, "Io"},
        {Hero::Visage, "Visage"},
        {Hero::Slark, "Slark"},
        {Hero::Medusa, "Medusa"},
        {Hero::Troll_Warlord, "Troll Warlord"},
        {Hero::Centaur_Warrunner, "Centaur Warrunner"},
        {Hero::Magnus, "Magnus"},
        {Hero::Timbersaw, "Timbersaw"},
        {Hero::Bristleback, "Bristleback"},
        {Hero::Tusk, "Tusk"},
        {Hero::Skywrath_Mage, "Skywrath Mage"},
        {Hero::Abaddon, "Abaddon"},
        {Hero::Elder_Titan, "Elder Titan"},
        {Hero::Legion_Commander, "Legion Commander"},
        {Hero::Techies, "Techies"},
        {Hero::Ember_Spirit, "Ember Spirit"},
        {Hero::Earth_Spirit, "Earth Spirit"},
        {Hero::Terrorblade, "Terrorblade"},
        {Hero::Phoenix, "Phoenix"},
        {Hero::Oracle, "Oracle"},
        {Hero::Winter_Wyvern, "Winter Wyvern"},
        {Hero::Arc_Warden, "Arc Warden"},
    });
    inline Hero heroFromInt(int hero)
    {
        const auto iter = heroes.find(hero);

        if(iter == heroes.end())
            return Hero::Unknown;

        return iter->second;
    }

    inline std::string heroToString(Hero hero)
    {
        const auto iter = heroNames.find(hero);

        if(iter == heroNames.end())
            return heroNames.at(Hero::Unknown);

        return iter->second;
    }
} // namespace dota2
#endif // ifndef HEROES_HPP_GENERATED
