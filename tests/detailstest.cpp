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
        }

    protected:
        dota2::Details d;
};

TEST_F(DetailsTest, getMatchID)
{
    EXPECT_EQ
    (
        1534328999,
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
}

TEST_F(DetailsTest, getFirstBloodTime)
{
    EXPECT_EQ
    (
        328,
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
}

TEST_F(DetailsTest, getDuration)
{
    EXPECT_EQ
    (
        511,
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
