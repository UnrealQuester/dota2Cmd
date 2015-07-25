#include "dota2api/buildings.hpp"
#include "gtest/gtest.h"

class BuildingStatusTest : public ::testing::Test
{
    protected:
        dota2::BuildingStatus buildings;
};

TEST_F(BuildingStatusTest, allStandingInitially)
{
    EXPECT_TRUE
        (
         buildings.getStatus().all()
        );
}

TEST_F(BuildingStatusTest, allDestroyed)
{
    buildings.set(0, 0);
    EXPECT_TRUE
        (
         buildings.getStatus().none()
        );
}

TEST_F(BuildingStatusTest, set)
{
    uint8_t barracksStatus = 0xAB; // 10101011
    uint16_t towerStatus = 0xC80F; // 1100100000001111
    buildings.set(barracksStatus, towerStatus);
    EXPECT_TRUE
        (
         buildings.get(dota2::Buildings::Top_Melee)
        );
    EXPECT_TRUE
        (
         buildings.get(dota2::Buildings::Top_Ranged)
        );
    EXPECT_FALSE
        (
         buildings.get(dota2::Buildings::Middle_Melee)
        );
    EXPECT_TRUE
        (
         buildings.get(dota2::Buildings::Middle_Ranged)
        );
    EXPECT_FALSE
        (
         buildings.get(dota2::Buildings::Bottom_Melee)
        );
    EXPECT_TRUE
        (
         buildings.get(dota2::Buildings::Bottom_Ranged)
        );
    EXPECT_TRUE
        (
         buildings.get(dota2::Buildings::Top_Tier_1)
        );
    EXPECT_TRUE
        (
         buildings.get(dota2::Buildings::Top_Tier_2)
        );
    EXPECT_TRUE
        (
         buildings.get(dota2::Buildings::Top_Tier_3)
        );
    EXPECT_TRUE
        (
         buildings.get(dota2::Buildings::Middle_Tier_1)
        );
    EXPECT_FALSE
        (
         buildings.get(dota2::Buildings::Middle_Tier_2)
        );
    EXPECT_FALSE
        (
         buildings.get(dota2::Buildings::Middle_Tier_3)
        );
    EXPECT_FALSE
        (
         buildings.get(dota2::Buildings::Bottom_Tier_1)
        );
    EXPECT_FALSE
        (
         buildings.get(dota2::Buildings::Bottom_Tier_2)
        );
    EXPECT_FALSE
        (
         buildings.get(dota2::Buildings::Bottom_Tier_3)
        );
    EXPECT_FALSE
        (
         buildings.get(dota2::Buildings::Ancient_Bottom)
        );
    EXPECT_FALSE
        (
         buildings.get(dota2::Buildings::Ancient_Top)
        );
}
