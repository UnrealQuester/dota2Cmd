#include "heroes.hpp"

dota2::Hero dota2::heroFromInt(int hero)
{
    const auto iter = heroes.find(hero);
    if(iter == heroes.end())
    {
        return Hero::Unknown;
    }
    return iter->second;
}
