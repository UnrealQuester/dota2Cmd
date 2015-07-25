#include "gamemode.hpp"
using namespace dota2;
GameMode dota2::gameModeFromInt(int mode)
{
    switch(mode)
    {
        case (int)GameMode::Unknwown:
            return GameMode::Unknwown;
        case (int)GameMode::All_Pick:
            return GameMode::All_Pick;
        case (int)GameMode::Captains_Mode:
            return GameMode::Captains_Mode;
        case (int)GameMode::Random_Draft:
            return GameMode::Random_Draft;
        case (int)GameMode::Single_Draft:
            return GameMode::Single_Draft;
        case (int)GameMode::All_Random:
            return GameMode::All_Random;
        case (int)GameMode::Intro:
            return GameMode::Intro;
        case (int)GameMode::Diretide:
            return GameMode::Diretide;
        case (int)GameMode::Reverse_Captains_Mode:
            return GameMode::Reverse_Captains_Mode;
        case (int)GameMode::Greeviling:
            return GameMode::Greeviling;
        case (int)GameMode::Tutorial:
            return GameMode::Tutorial;
        case (int)GameMode::Mid_Only:
            return GameMode::Mid_Only;
        case (int)GameMode::Least_Played:
            return GameMode::Least_Played;
        case (int)GameMode::New_Player_Pool:
            return GameMode::New_Player_Pool;
        case (int)GameMode::Compendium_Matchmaking:
            return GameMode::Compendium_Matchmaking;
        case (int)GameMode::Custom:
            return GameMode::Custom;
        case (int)GameMode::Captains_Draft:
            return GameMode::Captains_Draft;
        case (int)GameMode::Balanced_Draft:
            return GameMode::Balanced_Draft;
        case (int)GameMode::Ability_Draft:
            return GameMode::Ability_Draft;
        case (int)GameMode::Event:
            return GameMode::Event;
        case (int)GameMode::All_Random_Death_Match:
            return GameMode::All_Random_Death_Match;
        case (int)GameMode::Solo_Mid:
            return GameMode::Solo_Mid;
        default: return GameMode::
                 Unknwown;
    }
}
