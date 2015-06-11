#include "history.hpp"

dota2::History(const std::vector<dota2::MatchID> &matchIDs) : matchIDs(matchIDs) { }

const std::vector<dota2::MatchID> &dota2::History::getMatchIDs() const
{
    return matchIDs;
}
