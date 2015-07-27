#include "gamemode.hpp"
#include "_util.hpp"
using namespace dota2;
GameMode dota2::gameModeFromInt(int mode)
{
    switch(mode)
    {
        enumCase(GameMode::Unknwown);
        enumCase(GameMode::All_Pick);
        enumCase(GameMode::Captains_Mode);
        enumCase(GameMode::Random_Draft);
        enumCase(GameMode::Single_Draft);
        enumCase(GameMode::All_Random);
        enumCase(GameMode::Intro);
        enumCase(GameMode::Diretide);
        enumCase(GameMode::Reverse_Captains_Mode);
        enumCase(GameMode::Greeviling);
        enumCase(GameMode::Tutorial);
        enumCase(GameMode::Mid_Only);
        enumCase(GameMode::Least_Played);
        enumCase(GameMode::New_Player_Pool);
        enumCase(GameMode::Compendium_Matchmaking);
        enumCase(GameMode::Custom);
        enumCase(GameMode::Captains_Draft);
        enumCase(GameMode::Balanced_Draft);
        enumCase(GameMode::Ability_Draft);
        enumCase(GameMode::Event);
        enumCase(GameMode::All_Random_Death_Match);
        enumCase(GameMode::Solo_Mid);
        enumCaseDefault(GameMode::Unknwown);
    }
}
