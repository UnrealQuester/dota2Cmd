#include "player.hpp"
#include "json/json.h"

dota2::Player::Player(const Json::Value &json)
{
    accountID           = json["account_id"].asUInt();
    kills               = json["kills"].asUInt();
    deaths              = json["deaths"].asUInt();
    assists             = json["assists"].asUInt();
    netWorth            = json["gold"].asUInt() + json["gold_spent"].asUInt();
    experiencePerMinute = json["xp_per_min"].asUInt();
    goldPerMinute       = json["gold_per_min"].asUInt();
    denies              = json["denies"].asUInt();
    lastHits            = json["last_hits"].asUInt();
    hero                = heroFromInt(json["hero_id"].asInt());
    level               = json["level"].asUInt();
    readItems(json);
    for(const auto &unit : json["additional_units"])
        readItems(unit);
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

unsigned int dota2::Player::getGoldPerMinute() const
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

dota2::Hero dota2::Player::getHero() const
{
    return hero;
}

unsigned int dota2::Player::getLevel() const
{
    return level;
}

const std::vector<dota2::Item> &dota2::Player::getItems() const
{
    return items;
}

void dota2::Player::readItems(const Json::Value &json)
{
    for(int i = 0; i < 8; ++i)
    {
        auto key    = "item_" + std::to_string(i);
        auto itemID = json[key].asInt();

        if(!itemID)
            continue;
        items.push_back(itemFromInt(itemID));
    }
}

