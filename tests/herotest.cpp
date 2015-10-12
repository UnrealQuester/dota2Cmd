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
