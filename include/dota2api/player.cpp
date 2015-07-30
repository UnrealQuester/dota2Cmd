#include "player.hpp"
#include "json/json.h"

dota2::Player::Player(const Json::Value &json)
{
    accountID = json["account_id"].asUInt();
}

uint32_t dota2::Player::getAccountID()
{
    return accountID;
}
