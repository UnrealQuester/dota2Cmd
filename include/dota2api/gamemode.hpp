#ifndef GAMEMODE_HPP_G2COHEZY
#define GAMEMODE_HPP_G2COHEZY

#include <string>
#include <map>

namespace dota2
{
    /*!
     * Enum containing the game modes
     */
    enum class GameMode {
        Unknwown,
        All_Pick,
        Captains_Mode,
        Random_Draft,
        Single_Draft,
        All_Random,
        Intro,
        Diretide,
        Reverse_Captains_Mode,
        Greeviling,
        Tutorial,
        Mid_Only,
        Least_Played,
        New_Player_Pool,
        Compendium_Matchmaking,
        Custom,
        Captains_Draft,
        Balanced_Draft,
        Ability_Draft,
        Event,
        All_Random_Death_Match,
        Solo_Mid,
    };

    GameMode gameModeFromInt(int mode);
}
#endif /* end of include guard: GAMEMODE_HPP_G2COHEZY */
