#include "dota2api/heroes.hpp"
#include "gtest/gtest.h"

TEST(Hero, heroFromInt)
{
    EXPECT_EQ
    (
        dota2::Hero::Unknown,
        dota2::heroFromInt(-1)
    );
    EXPECT_EQ
    (
        dota2::Hero::Lina,
        dota2::heroFromInt(25)
    );
}

TEST(Hero, heroToString)
{
    EXPECT_EQ
    (
        "Unknown",
        dota2::heroToString(dota2::Hero::Unknown)
    );
    EXPECT_EQ
    (
        "Lina",
        dota2::heroToString(dota2::Hero::Lina)
    );
}
