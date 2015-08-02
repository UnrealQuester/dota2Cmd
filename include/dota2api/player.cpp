#include "player.hpp"
#include "json/json.h"

dota2::Player::Player(const Json::Value &json)
{
    accountID = json["account_id"].asUInt();
    kills = json["kills"].asUInt();
    deaths = json["deaths"].asUInt();
    assists = json["assists"].asUInt();
    netWorth = json["gold"].asUInt() + json["gold_spent"].asUInt();
}

uint32_t dota2::Player::getAccountID() const
{
    return accountID;
}

unsigned int dota2::Player::getKills() const
{
    return kills;
}

unsigned int dota2::Player::getDeaths() const
{
    return deaths;
}

unsigned int dota2::Player::getAssists() const
{
    return assists;
}

unsigned int dota2::Player::getNetWorth() const
{
    return netWorth;
}
