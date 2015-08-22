#include "player.hpp"
#include "json/json.h"

dota2::Player::Player(const Json::Value &json)
{
    accountID = json["account_id"].asUInt();
    kills = json["kills"].asUInt();
    deaths = json["deaths"].asUInt();
    assists = json["assists"].asUInt();
    netWorth = json["gold"].asUInt() + json["gold_spent"].asUInt();
    experiencePerMinute = json["xp_per_min"].asUInt();
    goldPerMinute = json["gold_per_min"].asUInt();
    denies = json["denies"].asUInt();
    lastHits = json["last_hits"].asUInt();
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

unsigned int dota2::Player::getExperiencePerMinute() const
{
    return experiencePerMinute;
}

unsigned int dota2::Player::getGoldperMinute() const
{
    return goldPerMinute;
}

unsigned int dota2::Player::getDenies() const
{
    return denies;
}

unsigned int dota2::Player::getLastHits() const
{
    return lastHits;
}
