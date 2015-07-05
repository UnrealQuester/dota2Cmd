#include "history.hpp"
#include "json/json.h"

dota2::History::History(const std::vector<dota2::MatchID> &matchIDs) : matchIDs(matchIDs) { }

dota2::History::History(const Json::Value &json)
{
    for(const auto &match : json["result"]["matches"])
    {
        matchIDs.push_back(match["match_id"].asInt());
    }
}

const std::vector<dota2::MatchID> &dota2::History::getMatchIDs() const
{
    return matchIDs;
}

dota2::HistoryRequest &dota2::HistoryRequest::hero(int heroID)
{
    query.insert({"hero_id", std::to_string(heroID)});
    return *this;
}

dota2::HistoryRequest &dota2::HistoryRequest::gameMode(GameMode gameMode)
{
    query.insert({"game_mode", std::to_string(static_cast<int>(gameMode))});
    return *this;
}

dota2::HistoryRequest &dota2::HistoryRequest::skillLevel(SkillLevel skillLevel)
{
    query.insert({"skill", std::to_string(skillLevel)});
    return *this;
}

dota2::HistoryRequest &dota2::HistoryRequest::minPlayers(int minPlayerCount)
{
    query.insert({"min_players", std::to_string(minPlayerCount)});
    return *this;
}

dota2::HistoryRequest &dota2::HistoryRequest::account(uint64_t accountID)
{
    query.insert({"account_id", std::to_string(accountID)});
    return *this;
}

dota2::HistoryRequest &dota2::HistoryRequest::league(uint64_t leagueID)
{
    query.insert({"league_id", std::to_string(leagueID)});
    return *this;
}

dota2::HistoryRequest &dota2::HistoryRequest::startAt(uint64_t matchID)
{
    query.insert({"start_at_match_id", std::to_string(matchID)});
    return *this;
}

dota2::HistoryRequest &dota2::HistoryRequest::matches(int numMatches)
{
    query.insert({"matches_requested", std::to_string(numMatches)});
    return *this;
}

dota2::HistoryRequest &dota2::HistoryRequest::tournament(bool tournamentOnly)
{
    query.insert({"tournament_games_only", std::to_string((int)tournamentOnly)});
    return *this;
}
