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
    duration = timePoint(result["duration"].asInt64());
    winningTeam = result["radiant_win"].asBool() ?
        Team::RADIANT : Team::DIRE;
    buildingStatusDire.set(
            result["barracks_status_dire"].asUInt(),
            result["tower_status_dire"].asUInt()
            );
    buildingStatusRadiant.set(
            result["barracks_status_radiant"].asUInt(),
            result["tower_status_radiant"].asUInt()
            );
    gameMode = gameModeFromInt(result["game_mode"].asInt());
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
const dota2::BuildingStatus& dota2::Details::getBuildingsStatusDire() const
{
    return buildingStatusDire;
}

const dota2::BuildingStatus& dota2::Details::getBuildingsStatusRadiant() const
{
    return buildingStatusRadiant;
}

dota2::GameMode dota2::Details::getGameMode() const
{
    return gameMode;
}

dota2::Details::timePoint dota2::Details::getDuration() const
{
    return duration;
}
