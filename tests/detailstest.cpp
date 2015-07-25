#include "dota2api/details.hpp"
#include "matchdetails_json.hpp"
#include "gtest/gtest.h"
#include "json/json.h"

TEST(Details, JSON)
{

    Json::Value json;
    Json::Reader().parse(matchdetailsJSON, json);
    dota2::Details d(json);
    EXPECT_EQ
        (
         1534328999,
         d.getMatchID()
        );
    EXPECT_EQ
        (
         dota2::Team::DIRE,
         d.getWinningTeam()
        );
    EXPECT_EQ
        (
         328,
         d.getFirstBloodTime().count()
        );
    EXPECT_EQ
        (
         1433676675,
         d.getStartTime().count()
        );
    EXPECT_EQ
        (
         true,
         d.getBuildingsStatusDire().getStatus().all()
        );
    EXPECT_EQ
        (
         true,
         d.getBuildingsStatusRadiant().getStatus().all()
        );
    EXPECT_EQ
        (
         dota2::GameMode::Solo_Mid,
         d.getGameMode()
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
