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
