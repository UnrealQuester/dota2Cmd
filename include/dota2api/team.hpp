#ifndef TEAM_HPP_VBXTG91H
#define TEAM_HPP_VBXTG91H

#include <string>

namespace dota2
{
    enum class Team
    {
        RADIANT,
        DIRE
    };

    inline std::string teamToString(Team team)
    {
        return team == Team::RADIANT ? "Radiant" : "Dire";
    }
}

#endif /* end of include guard: TEAM_HPP_VBXTG91H */
