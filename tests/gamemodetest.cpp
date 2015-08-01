#include "dota2api/gamemode.cpp"
#include "gtest/gtest.h"

TEST(GameMode, gameModeFromInt)
{
    EXPECT_EQ
        (
         dota2::GameMode::Unknwown,
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
