#include "player.hpp"
#include "json/json.h"

dota2::Player::Player(const Json::Value &json)
{
    accountID = json["account_id"].asUInt();
    kills = json["kills"].asUInt();
    deaths = json["deaths"].asUInt();
    assists = json["assists"].asUInt();
}

uint32_t dota2::Player::getAccountID()
{
    return accountID;
}

unsigned int dota2::Player::getKills()
{
    return kills;
}

unsigned int dota2::Player::getDeaths()
{
    return deaths;
}

unsigned int dota2::Player::getAssists()
{
    return assists;
}
