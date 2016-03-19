#include "dota2api/gamemode.hpp"
#include "gtest/gtest.h"

TEST(GameMode, gameModeFromInt)
{
    EXPECT_EQ
    (
        dota2::GameMode::Unknown,
        dota2::gameModeFromInt(-1)
    );
    for(const auto &mode : dota2::gameModes)
    {
        EXPECT_EQ
        (
            mode.second,
            dota2::gameModeFromInt(mode.first)
        );
    }
}

TEST(GameMode, gameModeToString)
{
    EXPECT_EQ
    (
        "Unknown",
        dota2::gameModeToString(dota2::GameMode::Unknown)
    );
    EXPECT_EQ
    (
        "Ranked All Pick",
        dota2::gameModeToString(dota2::GameMode::All_Pick)
    );
}
