#include "details.hpp"
#include "json/json.h"

dota2::DetailsRequest &dota2::DetailsRequest::id(MatchID id)
{
    query.insert({"match_id", std::to_string(id)});
    return *this;
}

dota2::Details::Details(const Json::Value &json)
{
    matchID = json["result"]["match_id"].asInt();
}

dota2::MatchID dota2::Details::getMatchID() const
{
    return matchID;
}
