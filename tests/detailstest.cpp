#include "dota2api/details.hpp"
#include "matchdetails_json.hpp"
#include "gtest/gtest.h"
#include "json/json.h"

class DetailsTest : public testing::Test
{
    public:
        DetailsTest()
        {
            Json::Value json;
            Json::Reader().parse(matchdetailsJSON, json);

            d = dota2::Details(json);
            this->json = d.toJson();
        }

    protected:
        dota2::Details d;
        Json::Value json;
};

TEST_F(DetailsTest, getMatchID)
{
    EXPECT_EQ
    (
        1534328999,
        d.getMatchID()
    );
    EXPECT_EQ
    (
        json["match_id"],
        d.getMatchID()
    );
}

TEST_F(DetailsTest, getWinningTeam)
{
    EXPECT_EQ
    (
        dota2::Team::DIRE,
        d.getWinningTeam()
    );
    EXPECT_EQ
    (
        json["winner"],
        "Dire"
    );
}

TEST_F(DetailsTest, getFirstBloodTime)
{
    EXPECT_EQ
    (
        328,
        d.getFirstBloodTime().count()
    );
    EXPECT_EQ
    (
        json["first_blood_time"].asLargestInt(),
        d.getFirstBloodTime().count()
    );
}

TEST_F(DetailsTest, getStartTime)
{
    EXPECT_EQ
    (
        1433676675,
        d.getStartTime().count()
    );
    EXPECT_EQ
    (
        json["start_time"].asLargestInt(),
        d.getStartTime().count()
    );
}

TEST_F(DetailsTest, getBuildingsStatusDire)
{
    EXPECT_EQ
    (
        true,
        d.getBuildingsStatusDire().getStatus().all()
    );
}

TEST_F(DetailsTest, getBuildingsStatusRadiant)
{
    EXPECT_EQ
    (
        true,
        d.getBuildingsStatusRadiant().getStatus().all()
    );
}

TEST_F(DetailsTest, getGameMode)
{
    EXPECT_EQ
    (
        dota2::GameMode::Solo_Mid,
        d.getGameMode()
    );
    EXPECT_EQ
    (
        json["game_mode"],
        "1vs1 Solo Mid"
    );
}

TEST_F(DetailsTest, getDuration)
{
    EXPECT_EQ
    (
        511,
        d.getDuration().count()
    );
    EXPECT_EQ
    (
        json["duration"].asLargestInt(),
        d.getDuration().count()
    );
}

TEST_F(DetailsTest, getDireTeam)
{
    const auto &team = d.getDireTeam();

    EXPECT_EQ
    (
        1,
        team.size()
    );
}

TEST_F(DetailsTest, getRadiantTeam)
{
    const auto &team = d.getRadiantTeam();

    EXPECT_EQ
    (
        1,
        team.size()
    );
}

TEST(DetailsRequest, filer)
{
    dota2::DetailsRequest request;

    request.id(12);
    auto query = request.getQuery();

    EXPECT_EQ
    (
        query["match_id"],
        "12"
    );
}
