#ifndef GAMEMODE_HPP_G2COHEZY
#define GAMEMODE_HPP_G2COHEZY

#include <map>

namespace dota2
{
    /*!
     * Enum containing the game modes
     */
    enum class GameMode
    {
        Unknown,
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

    const std::map<int, GameMode> gameModes({
        {(int)GameMode::All_Pick, GameMode::All_Pick},
        {(int)GameMode::Captains_Mode, GameMode::Captains_Mode},
        {(int)GameMode::Random_Draft, GameMode::Random_Draft},
        {(int)GameMode::Single_Draft, GameMode::Single_Draft},
        {(int)GameMode::All_Random, GameMode::All_Random},
        {(int)GameMode::Intro, GameMode::Intro},
        {(int)GameMode::Diretide, GameMode::Diretide},
        {(int)GameMode::Reverse_Captains_Mode, GameMode::Reverse_Captains_Mode},
        {(int)GameMode::Greeviling, GameMode::Greeviling},
        {(int)GameMode::Tutorial, GameMode::Tutorial},
        {(int)GameMode::Mid_Only, GameMode::Mid_Only},
        {(int)GameMode::Least_Played, GameMode::Least_Played},
        {(int)GameMode::New_Player_Pool, GameMode::New_Player_Pool},
        {(int)GameMode::Compendium_Matchmaking,
         GameMode::Compendium_Matchmaking},
        {(int)GameMode::Custom, GameMode::Custom},
        {(int)GameMode::Captains_Draft, GameMode::Captains_Draft},
        {(int)GameMode::Balanced_Draft, GameMode::Balanced_Draft},
        {(int)GameMode::Ability_Draft, GameMode::Ability_Draft},
        {(int)GameMode::Event, GameMode::Event},
        {(int)GameMode::All_Random_Death_Match,
         GameMode::All_Random_Death_Match},
        {(int)GameMode::Solo_Mid, GameMode::Solo_Mid},
    });

    const std::map<GameMode, std::string> gameModeNames({
        {GameMode::Unknown, "Unknown"},
        {GameMode::All_Pick, "Ranked All Pick"},
        {GameMode::Captains_Mode, "Captains Mode"},
        {GameMode::Random_Draft, "Random Draft"},
        {GameMode::Single_Draft, "Single Draft"},
        {GameMode::All_Random, "All Random"},
        {GameMode::Intro, "Intro"},
        {GameMode::Diretide, "Diretide"},
        {GameMode::Reverse_Captains_Mode, "Reverse Captains Mode"},
        {GameMode::Greeviling, "Greeviling"},
        {GameMode::Tutorial, "Tutorial"},
        {GameMode::Mid_Only, "Mid Only"},
        {GameMode::Least_Played, "Least Played"},
        {GameMode::New_Player_Pool, "New Player Pool"},
        {GameMode::Compendium_Matchmaking, "Compendium Matchmaking"},
        {GameMode::Custom, "Custom"},
        {GameMode::Captains_Draft, "Captains Draft"},
        {GameMode::Balanced_Draft, "Balanced Draft"},
        {GameMode::Ability_Draft, "Ability Draft"},
        {GameMode::Event, "Event"},
        {GameMode::All_Random_Death_Match, "All Random Death Match"},
        {GameMode::Solo_Mid, "1vs1 Solo Mid"},
    });

    GameMode gameModeFromInt(int mode);
    std::string gameModeToString(GameMode gameMode);
} // namespace dota2
#endif /* end of include guard: GAMEMODE_HPP_G2COHEZY */
