#include "gamemode.hpp"

dota2::GameMode dota2::gameModeFromInt(int mode)
{
    const auto iter = gameModes.find(mode);

    if(iter == gameModes.end())
        return GameMode::Unknown;

    return iter->second;
}

std::string dota2::gameModeToString(dota2::GameMode gameMode)
{
    const auto iter = gameModeNames.find(gameMode);

    if(iter == gameModeNames.end())
        return gameModeNames.at(GameMode::Unknown);

    return iter->second;
}
