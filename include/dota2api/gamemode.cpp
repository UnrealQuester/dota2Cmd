#include "gamemode.hpp"

dota2::GameMode dota2::gameModeFromInt(int mode)
{
    const auto iter = gameModes.find(mode);
    if(iter == gameModes.end())
    {
        return GameMode::Unknown;
    }
    return iter->second;
}
