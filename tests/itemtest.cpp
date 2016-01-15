#include "dota2api/items.hpp"
#include "gtest/gtest.h"

TEST(Item, itemFromInt)
{
    EXPECT_EQ
    (
        dota2::Item::Unknown,
        dota2::itemFromInt(-1)
    );
    EXPECT_EQ
    (
        dota2::Item::Divine_Rapier,
        dota2::itemFromInt(133)
    );
}
