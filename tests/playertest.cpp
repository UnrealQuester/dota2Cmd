#include "dota2api/details.hpp"
#include "player_json.hpp"
#include "gtest/gtest.h"
#include "json/json.h"

class PlayerTest : public ::testing::Test
{
    public:
        PlayerTest()
        {
            Json::Value json;
            Json::Reader().parse(playerJSON, json);
            player1 = dota2::Player(json["players"][0]);
            player2 = dota2::Player(json["players"][1]);
        }

     protected:
        dota2::Player player1;
        dota2::Player player2;
};

TEST_F(PlayerTest, getAccountID)
{
    EXPECT_EQ
        (
         121675089,
         player1.getAccountID()
        );
    EXPECT_EQ
        (
         dota2::privateAccountID,
         player2.getAccountID()
        );
}

TEST_F(PlayerTest, getKills)
{
    EXPECT_EQ
        (
         0,
         player1.getKills()
        );
    EXPECT_EQ
        (
         2,
         player2.getKills()
        );
}

TEST_F(PlayerTest, getAssists)
{
    EXPECT_EQ
        (
         1,
         player1.getAssists()
        );
    EXPECT_EQ
        (
         0,
         player2.getAssists()
        );
}

TEST_F(PlayerTest, getDeaths)
{
    EXPECT_EQ
        (
         2,
         player1.getDeaths()
        );
    EXPECT_EQ
        (
         0,
         player2.getDeaths()
        );
}

TEST_F(PlayerTest, getNetWorth)
{
    EXPECT_EQ
        (
         2247,
         player1.getNetWorth()
        );
    EXPECT_EQ
        (
         3731,
         player2.getNetWorth()
        );
}
