#include "dota2api/history.hpp"
#include "gtest/gtest.h"
#include "json/json.h"

TEST(History, getMatchIDs)
{
    dota2::History h((std::vector<dota2::MatchID>()));
    EXPECT_EQ
        (
         h.getMatchIDs(),
         std::vector<dota2::MatchID>()
        );
}

TEST(History, JSON)
{
    dota2::History h((Json::Value()));
    EXPECT_EQ
        (
         h.getMatchIDs(),
         std::vector<dota2::MatchID>()
        );
}

TEST(HistoryRequest, filter)
{
    dota2::HistoryRequest request;

    request.hero(12)
        .gameMode(dota2::GameMode::SOLO_MID)
        .skillLevel(dota2::SkillLevel::NORMAL)
        .minPlayers(2)
        .account(1)
        .league(3)
        .startAt(4)
        .matches(1)
        .tournament(false);
    auto query = request.getQuery();
    EXPECT_EQ
        (
            query["hero_id"],
            "12"
        );
    EXPECT_EQ
        (
            query["game_mode"],
            "21"
        );
    EXPECT_EQ
        (
            query["skill"],
            "1"
        );
    EXPECT_EQ
        (
            query["min_players"],
            "2"
        );
    EXPECT_EQ
        (
            query["account_id"],
            "1"
        );
    EXPECT_EQ
        (
            query["league_id"],
            "3"
        );
    EXPECT_EQ
        (
            query["start_at_match_id"],
            "4"
        );
    EXPECT_EQ
        (
            query["matches_requested"],
            "1"
        );
    EXPECT_EQ
        (
            query["tournament_games_only"],
            "0"
        );
}
