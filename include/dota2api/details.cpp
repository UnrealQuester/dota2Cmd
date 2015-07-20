#include "details.hpp"
#include "json/json.h"

dota2::DetailsRequest &dota2::DetailsRequest::id(MatchID id)
{
    query.insert({"match_id", std::to_string(id)});
    return *this;
}

dota2::Details::Details(const Json::Value &json)
{
    const auto& result = json["result"];

    matchID = result["match_id"].asInt();
    startTime = timePoint(result["start_time"].asInt64());
    firstBloodTime = timePoint(result["first_blood_time"].asInt64());
    if(result["radiant_win"].asBool())
    {
        winningTeam = Team::RADIANT;
    }
    else
    {
        winningTeam = Team::DIRE;
    }
}

dota2::MatchID dota2::Details::getMatchID() const
{
    return matchID;
}

dota2::Team dota2::Details::getWinningTeam() const
{
    return winningTeam;
}

dota2::Details::timePoint dota2::Details::getStartTime() const
{
    return startTime;
}

dota2::Details::timePoint dota2::Details::getFirstBloodTime() const
{
    return firstBloodTime;
}
